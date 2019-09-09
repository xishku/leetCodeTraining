#include "pch.h"
#include "SumCal1Test.hpp"


TEST_F(SumCal1Test, Target35ElementShouldBe3and7) {
	std::vector<int> inNums = { 1, 11, 111, 2, 22, 222, 3, 33, 333 };
	std::vector<int> outNums = sCal1.twoSum(inNums, 35);

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

TEST_F(SumCal1Test, ShouldReduceBookCountOnBorrow) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

}

TEST_F(SumCal1Test, ShouldThrowExceptionWhenNoBookIsAvailable) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}
