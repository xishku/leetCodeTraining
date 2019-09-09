#include "SumCal1.hpp"
#include  <iostream>
#include <map>
#include <algorithm>

/***
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***/
std::vector<int> SumCal1::twoSum(std::vector<int>& nums, int target)
{


	size_t countNums = nums.size();
	for (int i = 0; i < countNums; ++i)
	{

		for (int j = i + 1; j < countNums; ++j)
		{
			if (target == nums[i] + nums[j])
			{
				//std::cout << "print vector element: " << i << "&" << j << std::endl;
				std::vector<int> resNums = { i, j };
				return resNums;
			}
		}
	}

	std::vector<int> resNums;
	return resNums;
}

/***
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-two-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***/
ListNode* SumCal1::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* l3 = NULL;
	ListNode* nowL1 = l1;
	ListNode* nowL2 = l2;
	int numPos = 0;
	ListNode* curNode = NULL;
	for (int i = 0; ; ++i)
	{
		if (NULL != nowL1 || NULL != nowL2 || 0 < numPos)
		{
			ListNode* tmpNode = new ListNode(numPos);
			if (0 == i)
			{
				l3 = tmpNode;
			}
			else
			{
				curNode->next = tmpNode;
			}
			curNode = tmpNode;
		}

		if (NULL == nowL1 && NULL == nowL2)
		{
			return l3;
		}

		if (NULL != nowL1)
		{
			curNode->val += nowL1->val;
			nowL1 = nowL1->next;
		}

		if (NULL != nowL2)
		{
			curNode->val += nowL2->val;
			nowL2 = nowL2->next;
		}

		numPos = curNode->val / 10;
		curNode->val = curNode->val % 10;
	}

	return l3;
}


/***
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
***/
int SumCal1::lengthOfLongestSubstring(std::string s) {
	size_t length = s.size();
	std::map<int, int> childStr;
	//std::map<int, int> childPos;
	int maxLen = 0;

	for (size_t i = 0; i < length; ++i)
	{
		for (size_t j = i; j < length; ++j)
		{
			char ch = s[j];
			std::cout << "lengthOfLongestSubstring: " << int(s[j]) << std::endl;
			if (childStr.find(ch) != childStr.end())//find same charator
			{				
				maxLen = std::max(maxLen, (int)(j - i));
							
				childStr.clear();
				break;				
			}
			else
			{
				//std::cout << "same charator not find! " << std::endl;
				childStr[ch] = ch;				
				
				if (length - 1 == j)
				{
					maxLen = std::max(maxLen, (int)(length - i));
					childStr.clear();
				}
				
			}
		}
	}
	//std::cout << "print vector element: " << i << "&" << j << std::endl;

	return maxLen;
}



