#include "pch.h"
#include "SumCal1Test.hpp"


TEST_F(SumCal1Test, Target35ElementShouldBe3and7) {
	std::vector<int> inNums = { 1, 11, 111, 2, 22, 222, 3, 33, 333 };
	std::vector<int> outNums = sCal1->twoSum(inNums, 35);

	int i = 0;
	for (std::vector<int>::const_iterator it = outNums.begin();
		it != outNums.end(); it++)
	{
		if (0 == i)
		{
			EXPECT_EQ(3, *it);
		}

		if (1 == i)
		{
			EXPECT_EQ(7, *it);
		}

		++i;
		//std::cout << "print vector element: " << *it << std::endl;
	}
}

TEST_F(SumCal1Test, BigNumAdding7add8shouldBe15) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	ListNode l1(7);
	ListNode l2(8);

	ListNode* l3 = sCal1->addTwoNumbers(&l1, &l2);
	ListNode* curNode = l3;
	for (int i = 0; ; ++i)
	{
		if (NULL != curNode)
		{
			if (0 == i)
			{
				EXPECT_EQ(5, curNode->val);
			}
			else
			{
				EXPECT_EQ(1, curNode->val);
			}
			//std::cout << "print sum: " << curNode->val << std::endl;
			curNode = curNode->next;
		}
		else
		{
			break;
		}
	}
}

TEST_F(SumCal1Test, lengthOfLongestSubstringabcabcbb) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
	EXPECT_EQ(6, sCal1->lengthOfLongestSubstring("abcabcbbcdefg"));
}

TEST_F(SumCal1Test, lengthOfLongestSubstringbbb) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	EXPECT_EQ(1, sCal1->lengthOfLongestSubstring("bbb"));
}



TEST_F(SumCal1Test, lengthOfLongestSubstringpwwkew) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	EXPECT_EQ(3, sCal1->lengthOfLongestSubstring("pwwkew"));
}

TEST_F(SumCal1Test, lengthOfLongestSubstringEmptyStr) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	EXPECT_EQ(0, sCal1->lengthOfLongestSubstring(""));
}


TEST_F(SumCal1Test, lengthOfLongestSubstringSpaceStr) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

	EXPECT_EQ(1, sCal1->lengthOfLongestSubstring(" "));
}

TEST_F(SumCal1Test, IntegerReverse1534236469) {
	EXPECT_EQ(0, sCal1->integerReverse(1534236469));
}

TEST_F(SumCal1Test, IntegerReverse0) {
	EXPECT_EQ(0, sCal1->integerReverse(0));
}

TEST_F(SumCal1Test, IntegerReverse120) {
	EXPECT_EQ(-21, sCal1->integerReverse(-120));
}

TEST_F(SumCal1Test, IntegerReverse12100) {
	EXPECT_EQ(-121, sCal1->integerReverse(-12100));
}

TEST_F(SumCal1Test, IntegerReverse1900) {
	EXPECT_EQ(91, sCal1->integerReverse(1900));
}


TEST_F(SumCal1Test, game123123) {
	vector<int> guess;
	guess.push_back(1);
	guess.push_back(2);
	guess.push_back(3);
	vector<int> answer;
	answer.push_back(1);
	answer.push_back(2);
	answer.push_back(3);
	EXPECT_EQ(3, sCal1->game(guess, answer));
}


TEST_F(SumCal1Test, game123223) {
	vector<int> guess = { 1, 2, 3};
	vector<int> answer = { 2, 2, 3 };
	EXPECT_EQ(2, sCal1->game(guess, answer));
}


TEST_F(SumCal1Test, game123) {
	vector<int> input = { 1, 2, 3};	
	EXPECT_EQ(6, sCal1->maximumProduct(input));
}

TEST_F(SumCal1Test, game1234567) {
	vector<int> input = { 1, 2, 3, 4, 5, 6, 7 };
	EXPECT_EQ(210, sCal1->maximumProduct(input));
}


TEST_F(SumCal1Test, gameb1234567) {
	vector<int> input = { -10, -2, 3, 4, 5, 6, 7 };
	EXPECT_EQ(210, sCal1->maximumProduct(input));
}

TEST_F(SumCal1Test, gameb12345678) {
	vector<int> input = { -10, -2, -3, -4};
	EXPECT_EQ(-24, sCal1->maximumProduct(input));
}


TEST_F(SumCal1Test, myPower24) {
	EXPECT_EQ(16, sCal1->myPowRecur(2, 4));
}

TEST_F(SumCal1Test, myPowerb24) {
	EXPECT_EQ(1.0000 / 16, sCal1->myPowRecur(2, -4));
}






