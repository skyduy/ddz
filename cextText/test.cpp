#include "pch.h"
#include "../ddz/m.h"

vector<vector<int>> res;

TEST(getActionsTest, ����_�ֳ�54����_��������13550��)
{
	EXPECT_EQ(foo(), 0);
}
//
//TEST(getActionsTest, ����_�ֳ�54����_��������13550��)
//{
//	vector<int> handcards;
//	for (int i = 0; i < 13; i++)
//		handcards.push_back(4);
//	handcards.push_back(1);
//	handcards.push_back(1);
//	vector<int> none;
//	res = getActions(handcards, none);
//	EXPECT_EQ(res.size(), 13550);
//}
//
//TEST(getActionsTest, ����_�ֳ�20�Ŵ�����_��������368��)
//{
//	vector<int> handcards = { 0, 0, 0, 0, 0, 1, 1, 3, 3, 3, 3, 3, 1, 1, 1 };
//	vector<int> none;
//	res = getActions(handcards, none);
//	EXPECT_EQ(res.size(), 368);
//}
//
//TEST(getActionsTest, ����_Ҫ����)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 1, 1, 1, 1, 1, 3, 0, 2, 3, 1, 0 };
//	vector<int> lastcards = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 1);
//}
//
//TEST(getActionsTest, ����_�Է��˵�_Ҫ����)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 1, 1, 1, 1, 1, 3, 0, 2, 3, 1, 0 };
//	vector<int> lastcards = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 1);
//}
//
//TEST(getActionsTest, ����_�ҷ��˵�_ը��)
//{
//	vector<int> handcards = { 1, 1, 1, 2, 1, 1, 1, 1, 1, 3, 0, 2, 3, 1, 1 };
//	vector<int> lastcards = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0 };
//	res = getActions(handcards, lastcards);
//	vector<int> ans = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };
//	EXPECT_EQ(res.size(), 2);
//	EXPECT_EQ(res[1], ans);
//}
//
//TEST(getActionsTest, ����_ը��ը��)
//{
//	vector<int> handcards = { 0, 4, 1, 2, 1, 1, 1, 1, 1, 3, 0, 2, 3, 1, 0 };
//	vector<int> lastcards = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	vector<int> ans = { 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	EXPECT_EQ(res[1], ans);
//}
//
//TEST(getActionsTest, ����_ը����ѹ_Ҫ����)
//{
//	vector<int> handcards = { 1, 1, 1, 2, 1, 1, 1, 1, 1, 3, 0, 4, 0, 0, 0 };
//	vector<int> lastcards = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 1);
//}
//
//TEST(getActionsTest, ����_����_ѹ��)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 1, 1, 1, 1, 1, 3, 0, 2, 3, 1, 0 };
//	vector<int> lastcards = { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 11 + 1);
//}
//
//TEST(getActionsTest, ����_����_ѹ��)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 1, 1, 1, 1, 1, 3, 0, 2, 3, 1, 0 };
//	vector<int> lastcards = { 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 5 + 1);
//}
//
//TEST(getActionsTest, ����_����_����)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 1, 1, 1, 1, 1, 3, 0, 2, 3, 1, 0 };
//	vector<int> lastcards = { 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 2 + 1);
//}
//
//TEST(getActionsTest, ����_ը��ѹը��)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 1, 1, 1, 0, 1, 1, 0, 4, 1, 0, 0 };
//	vector<int> lastcards = { 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 1 + 1);
//}
//
//TEST(getActionsTest, ����_����һ_ѹ��)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 1, 1, 1, 0, 1, 1, 0, 3, 1, 0, 0 };
//	vector<int> lastcards = { 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 9 + 1);
//}
//
//TEST(getActionsTest, ����_������_ѹ��)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 1, 1, 1, 0, 1, 1, 0, 3, 1, 0, 0 };
//	vector<int> lastcards = { 0, 0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 2 + 1);
//}
//
//TEST(getActionsTest, ����_˳��_����)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 1, 1, 0, 1, 1, 1, 1, 3, 1, 0, 0 };
//	vector<int> lastcards = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 2 + 1);
//}
//
//TEST(getActionsTest, ����_��˳_����)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 2, 2, 2, 0, 1, 1, 0, 0, 1, 0, 0 };
//	vector<int> lastcards = { 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 2 + 1);
//}
//
//TEST(getActionsTest, ����_͹��ɻ�_ѹ��)
//{
//	vector<int> handcards = { 0, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0 };
//	vector<int> lastcards = { 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 3 + 1);
//}
//
//TEST(getActionsTest, ����_�Ĵ�������_ѹ��)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 2, 2, 4, 0, 1, 1, 0, 0, 1, 0, 0 };
//	vector<int> lastcards = { 0, 1, 1, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 1 + 1 + 28);
//}
//
//TEST(getActionsTest, ����_�Ĵ���2)
//{
//	vector<int> handcards = { 0, 2, 1, 2, 2, 2, 2, 0, 1, 4, 0, 0, 1, 0, 0 };
//	vector<int> lastcards = { 0, 2, 2, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 1 + 1 + 10);
//}
//
//TEST(getActionsTest, ����_����ɻ�_ѹ��)
//{
//	vector<int> handcards = { 0, 2, 1, 3, 3, 3, 3, 0, 1, 1, 0, 0, 1, 0, 0 };
//	vector<int> lastcards = { 0, 1, 3, 3, 3, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 1 + 20 + 20);
//}
//
//TEST(getActionsTest, ����_˫��ɻ�_����)
//{
//	vector<int> lastcards = { 0, 2, 3, 3, 3, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0 };
//	vector<int> handcards = { 0, 2, 1, 3, 3, 3, 3, 0, 1, 2, 0, 0, 1, 0, 0 };
//	res = getActions(handcards, lastcards);
//	EXPECT_EQ(res.size(), 1 + 2);
//}