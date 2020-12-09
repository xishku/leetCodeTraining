class Solution0239 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        deque<int> que;
        vector<int> ans;
        for (int i = 0, j = 0; i < n; ++i) {
            while(!que.empty() && nums[que.back()] < nums[i]) {
                que.pop_back();
            }

            que.push_back(i);

            if (i - j + 1 > k) {
                if (que.front() <= j) {
                    que.pop_front();
                }
                ++j;
            }

            if (i - j + 1 == k) {
                ans.push_back(nums[que.front()]);
            }
        }

        return ans;
    }
};
