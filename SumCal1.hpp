#include <vector>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};


class SumCal1
{
public:
	SumCal1(int inputNum) :num(inputNum) {};
	std::vector<int> twoSum(std::vector<int>& nums, int target);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int lengthOfLongestSubstring(std::string s);
	int lengthOfLongestSubstringLowSpeed(std::string s);
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
	int integerReverse(int x);

	//int operator""();
	int game(vector<int>& guess, vector<int>& answer);
	int maximumProduct(vector<int>& nums);
	double myPow(double x, int n);
	double myPowRecur(double x, int n);
	
private:
	int num;
};



