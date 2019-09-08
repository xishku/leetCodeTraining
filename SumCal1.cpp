#include "SumCal1.hpp"
#include  <iostream>

std::vector<int> SumCal1::twoSum(std::vector<int>& nums, int target)
{
	

	int countNums = nums.size();
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


