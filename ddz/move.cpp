#include "move.h"

inline void reset(vector<int>& v) {
	std::fill(v.begin(), v.end(), 0);
}

void combine(const vector<int>& options, int k, vector<vector<int>>& candidates)
{
	int n = options.size();
	int i = 0;
	vector<int> candidate(k, 0);
	vector<int> p(k, 0);
	while (i >= 0)
	{
		p[i]++;
		if (p[i] > n) {
			--i;
		}
		else if (i == k - 1) {
			reset(candidate);
			for (int j = 0; j < k; j++) {
				candidate[j] = options[p[j] - 1];
			}
			candidates.push_back(candidate);
		}
		else
		{
			++i;
			p[i] = p[i - 1];
		}
	}
}

vector<vector<int>> getActions(vector<int>& handcards, vector<int>& last)
{
	vector<vector<int>> res;
	vector<int> choice(15, 0);
	int totalCard = 0; // ���������Ŀ
	for (int num : last)
		totalCard += num;
	if (totalCard == 0)
	{
		vector<int> lenDict = { 5, 3, 2 };
		// �˵�
		if (handcards[13] && handcards[14])
		{
			reset(choice);
			choice[13] = choice[14] = 1;

			res.push_back(choice);
		}
		// ����������˫�������� & �Ĵ�2����2˫
		for (int i = 0; i < 15; i++)
		{
			for (int j = 1; j <= handcards[i]; j++)
			{
				reset(choice);
				choice[i] = j;
				res.push_back(choice);
				if (j == 4)
				{ // �Ĵ�2����2˫
					for (int num = 1; num <= 2; num++)
					{ // ��˫��
						vector<int> container;
						for (int k = 0; k < 15; k++)
						{
							if (k != i && handcards[k] >= num)
							{
								container.push_back(k);
							}
						}
						if (container.size() < 2)
							break;
						vector<vector<int>> candidates;
						combine(container, 2, candidates);
						for (vector<int> candidate : candidates)
						{
							vector<int> backup(choice);
							for (int c : candidate)
							{
								backup[c] = num;
							}
							res.push_back(backup);
						}
					}
				}
			}
		}
		// ����һ��������
		for (int main = 0; main < 15; main++)
		{
			if (handcards[main] >= 3)
			{
				for (int i = 0; i < 15; i++)
				{
					if (i != main && handcards[i] != 0)
					{ // + 1
						reset(choice);
						choice[main] = 3;
						choice[i] = 1;
						res.push_back(choice);
					}
					if (i != main && handcards[i] > 1)
					{ // + 2
						reset(choice);
						choice[main] = 3;
						choice[i] = 2;
						res.push_back(choice);
					}
				}
			}
		}
		// ˳�ӣ�����˫���� & �ɻ������
		for (int t = 0; t < 3; t++)
		{
			int start = 0, cur = 0;
			while (cur < 12)
			{
				// 'A' index is 11
				while (cur < 12 && handcards[cur] > t)
					cur++;
				if (cur - start >= lenDict[t])
				{
					// ���������20��
					for (int len = lenDict[t]; len <= (cur - start) && (t + 1) * len <= 20; len++)
					{
						for (int i = start; i + len <= cur; i++)
						{
							reset(choice);
							for (int j = i; j < i + len; j++)
							{
								choice[j] = t + 1;
							}
							res.push_back(choice);
							if (t == 2)
							{ // �ɻ����Դ�1, 2���
								for (int wing = 1; wing <= 2; wing++)
								{ // ��˫��
									if ((t + 1) * len + wing * len <= 20)
									{
										vector<int> container;
										for (int i = 0; i < 15; i++)
										{
											if (choice[i] == 0 && handcards[i] >= wing)
											{
												container.push_back(i);
											}
										}
										if (int(container.size()) < len)
											break;
										vector<vector<int>> candidates;
										combine(container, len, candidates);
										for (vector<int> candidate : candidates)
										{
											vector<int> backup(choice);
											for (int c : candidate)
											{
												backup[c] = wing;
											}
											res.push_back(backup);
										}
									}
								}
							}
						}
					}
				}
				while (cur < 12 && handcards[cur] <= t)
					cur++;
				start = cur;
			}
		}
	}
	else
	{
		// ȫ������
		int diffCard = 0;		  // ���ﲻͬ���������
		int maxCard = 0;		  // �����������: 0, 1, ... 14
		int maxCount = 0;		  // ���������ƣ����ж��ٸ�
		vector<int> maxCountCard; // �����������γɵ�����
		for (int i = 0; i < 15; i++)
		{
			if (last[i] != 0)
			{
				maxCard = i;
				diffCard += 1;
				if (last[i] > maxCount)
					maxCount = last[i];
			}
		}
		for (int i = 0; i < 15; i++)
		{
			if (last[i] == maxCount)
			{
				maxCountCard.push_back(i);
			}
		}
		// ��һ����Ҫ����
		vector<int> none(15, 0);
		res.push_back(none);
		// --------------��ѹ����------------------
		// �˵���ѹһ��
		if (handcards[13] == 1 && handcards[14] == 1)
		{ // �˵�ը����
			reset(choice);
			choice[13] = 1;
			choice[14] = 1;
			res.push_back(choice);
		}
		if (totalCard == 2 && last[13] == 1 && last[14] == 1)
		{ // �˵�Ҫ����
			return res;
		}
		// ը����ѹ�Ǻ˵����Ǹ����ը���������������
		if (diffCard == 1 && maxCount == 4)
		{
			for (int i = maxCard + 1; i < 15; i++)
			{
				if (handcards[i] == 4)
				{
					reset(choice);
					choice[i] = 4;
					res.push_back(choice);
				}
			}
		}
		else
		{
			for (int i = 0; i < 15; i++)
			{
				if (handcards[i] == 4)
				{
					reset(choice);
					choice[i] = 4;
					res.push_back(choice);
				}
			}
		}
		// --------------����Թ���------------------
		// ������1��2��3
		if (diffCard == 1)
		{
			if (maxCount < 4)
			{
				for (int i = maxCard + 1; i < 15; i++)
				{
					if (handcards[i] >= maxCount)
					{
						reset(choice);
						choice[i] = maxCount;
						res.push_back(choice);
					}
				}
			}
			return res;
		}
		// ����һ��������
		if ((totalCard == 4 || totalCard == 5) && diffCard == 2 && maxCount == 3)
		{
			int kicker = totalCard - 3;
			for (int main = maxCountCard[0] + 1; main < 15; main++)
			{
				if (handcards[main] >= 3)
				{
					for (int i = 0; i < 15; i++)
					{
						if (i != main && handcards[i] >= kicker)
						{ // ��1��2
							reset(choice);
							choice[main] = 3;
							choice[i] = kicker;
							res.push_back(choice);
						}
					}
				}
			}
			return res;
		}
		// ˳�ӣ�1��2��3
		if (diffCard == maxCountCard.size())
		{
			int type = totalCard / diffCard;
			int start = maxCountCard[0] + 1;
			int cur = start;
			while (cur < 12)
			{
				// 'A' index is 11
				while (cur < 12 && handcards[cur] >= type)
					cur++;
				if (cur - start >= diffCard)
				{
					for (int i = start; i + diffCard <= cur; i++)
					{
						reset(choice);
						for (int j = i; j < i + diffCard; j++)
						{
							choice[j] = type;
						}
						res.push_back(choice);
					}
				}
				while (cur < 12 && handcards[cur] < type)
					cur++;
				start = cur;
			}
			return res;
		}
		// �Ĵ���1���Ĵ���2
		if (diffCard == 3 && maxCount == 4 && (totalCard == 6) || (totalCard == 8))
		{
			int kicker = (totalCard - 4) / 2;
			for (int i = maxCountCard[0] + 1; i < 15; i++)
			{
				if (handcards[i] == 4)
				{
					reset(choice);
					choice[i] = 4;

					vector<int> container;
					for (int k = 0; k < 15; k++)
					{
						if (k != i && handcards[k] >= kicker)
						{
							container.push_back(k);
						}
					}
					if (container.size() < 2)
						continue;
					vector<vector<int>> candidates;
					combine(container, 2, candidates);
					for (vector<int> candidate : candidates)
					{
						vector<int> backup(choice);
						for (int c : candidate)
						{
							backup[c] = kicker;
						}
						res.push_back(backup);
					}
				}
			}
			return res;
		}
		// �ɻ���һ������
		for (int wing = 1; wing <= 2; wing++)
		{
			if (maxCountCard.size() >= 2 && maxCount == 3 && totalCard == (3 + wing) * maxCountCard.size() && diffCard == 2 * maxCountCard.size())
			{
				int len = diffCard / 2;
				int start = maxCountCard[0];
				int cur = start;
				while (cur < 12)
				{
					// 'A' index is 11
					while (cur < 12 && handcards[cur] >= 3)
						cur++;
					if (cur - start >= len)
					{
						for (int i = start; i + len <= cur; i++)
						{
							reset(choice);
							for (int j = i; j < i + len; j++)
							{
								choice[j] = 3;
							}
							vector<int> container;
							for (int i = 0; i < 15; i++)
							{
								if (choice[i] == 0 && handcards[i] >= wing)
								{
									container.push_back(i);
								}
							}
							if (container.size() < 2)
								continue;
							vector<vector<int>> candidates;
							combine(container, len, candidates);
							for (vector<int> candidate : candidates)
							{
								vector<int> backup(choice);
								for (int c : candidate)
								{
									backup[c] = wing;
								}
								res.push_back(backup);
							}
						}
					}
					while (cur < 12 && handcards[cur] < 3)
						cur++;
					start = cur;
				}
				return res;
			}
		}
	}
	return res;
}