class Solution0042 {
public:

    int trapMonoStack(vector<int>& height) {
        int n = height.size();

        // 单调栈用来找出一个柱子左右比它高的柱子的位置
        stack<int> monoStack;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int mid = 0; mid < n; ++mid) {
            while (!monoStack.empty() && height[monoStack.top()] <= height[mid]) {
                right[monoStack.top()] = mid; //右边大的
                monoStack.pop();
            }

            left[mid] =  monoStack.empty() ? -1 :monoStack.top(); //左边大的
            monoStack.push(mid);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // 左边没有高的，或者右边没有高的，挡不到雨水
            if (left[i] == -1 || right[i] == n ) {
                continue;
            }
            // 核心理解点：当前柱子上面，左右比当前高的柱子挡水，矮的那个，这个范围计算在当前柱子上面
            ans += (right[i] - left[i] - 1) * (min(height[left[i]], height[right[i]]) - height[i]);
        }

        return ans;
    }

    int trapSimple(vector<int>& height) {

        int n = height.size();

        int ans = 0;
        for (int mid = 0; mid < n; ++mid) {
            int leftMax = 0;
            for (int left = mid; left >= 0; --left) {
                leftMax = max(leftMax, height[left]);
            }

            int rightMax = 0;
            for (int right = mid; right < n; ++right) {
                rightMax = max(rightMax, height[right]);
            }

            int h = min(leftMax, rightMax);
            ans += h - height[mid];
        }

        return ans;
    }

    int trapSimplest(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        stack<int> monoStack;
        for (int i = 0; i < n; ++i) {
            while (!monoStack.empty() && height[monoStack.top()] <= height[i]) {
                int mid = monoStack.top();
                int right = i;
                monoStack.pop();

                int left = -1;
                if (!monoStack.empty()) {
                    left = monoStack.top();
                }

                // cout << mid << "\t" << left << "\t"  << right << "\t"  << endl;
                // cout << ans << " -> ";
                if (left != -1) {
                    ans += (min(height[left], height[right]) - height[mid]) * (right - left -1);
                }
                // cout << ans << endl;
            }


            monoStack.push(i);
        }

        return ans;
    }

    int trap(vector<int>& height) {
        int left = 0;
        int  right = height.size() - 1;
        int ans = 0;

        int leftMax = 0;
        int rightMax = 0;
        while (left < right) {
            if (height[left] < height[right]) {

                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    ans += leftMax - height[left];
                }

                ++left;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    ans += rightMax - height[right];
                }

                --right;
            }
        }

        return ans;
    }
};
