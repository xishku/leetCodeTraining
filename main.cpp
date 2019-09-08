// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include "SumCal1.hpp"

int main()
{
	std::vector<int> numVer;

	for (int i = 0; i < 100; i++)
	{
		numVer.push_back(i);
	}

	for(std::vector<int>::const_iterator it = numVer.begin();
		it != numVer.end(); it++)
	{
		//std::cout << "print vector element: " << *it << std::endl;
	}
	std::cout << "Hello World!\n";


	std::vector<int> inNums = { 1, 11, 111, 2, 22, 222, 3, 33, 333 };
	SumCal1 sCal1;
	std::vector<int> outNums = sCal1.twoSum(inNums, 35);

	for (std::vector<int>::const_iterator it = outNums.begin();
		it != outNums.end(); it++)
	{
		std::cout << "print vector element: " << *it << std::endl;
	}

	ListNode l1(7);
	ListNode l2(8);

	ListNode* l3 = sCal1.addTwoNumbers(&l1, &l2);
	ListNode* curNode = l3;
	for(int i = 0; ; ++i)
	{ 
		if (NULL != curNode)
		{
			std::cout << "print sum: " << curNode->val << std::endl;
			curNode = curNode->next;
		}
		
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
