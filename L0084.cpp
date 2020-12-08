class Solution0084 {
public:
    int largestRectangleArea(vector<int> &height) {
        int ans = 0;
        height.push_back(0); // 最右边放了高度为0的矩形
        stack<int> matchStack;
        for(int i = 0; i < height.size(); i++) {

            cout << endl << "No. " << height.size() << "-" << i << endl;

            while(matchStack.size() > 0 && height[matchStack.top()] >= height[i]) {
                //cout << "index.back():" << matchStack.top() << " - " << height[matchStack.top()] << "    current value:" << height[i] << endl;
                int mid = matchStack.top();
                int h = height[matchStack.top()]; // 当前栈顶历史位置的高度
                matchStack.pop();

                // index.back()即index.size() - 1
                int left = matchStack.size() > 0 ? matchStack.top() : -1; // 左边比他小的位置
                int right = i;

                cout << mid << "\t left : " << left << "\t right : " << right << endl;
                ans = max(ans, h * (right - left - 1)); // i是当前位置
                //cout << "update bigger area " << ret << " from " << sidx + 1 << " to " << i - 1 << endl;
            }
            matchStack.push(i);
        }
        return ans;
    }

    int largestRectangleAreaMonoStack(vector<int>& heights) {
        int n = heights.size();

        stack<int> monoStack;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            while (!monoStack.empty() && heights[monoStack.top()] >= heights[i]) {
                right[monoStack.top()] = i; // 栈里面放的是前面的位置，遇到了height比栈里小，所以要出栈的位置，右边比它小的就是当前的i
                monoStack.pop();
            }

            left[i] = monoStack.empty()? -1 : monoStack.top(); // 大的都已经pop出，栈顶是比当前height小的；

            monoStack.push(i);
        }

        int ans = 0;
        for (int j = 0; j < n; ++j) {
            ans = max(ans, heights[j] * (right[j] - left[j] - 1));
        }

        return ans;
    }

    int largestRectangleAreaStackLeftRight(vector<int>& heights) {
        int n = heights.size();

        stack<int> monoStack;
        vector<int> left(n, -1);
        // 找到左边最小高度对应的i，栈里维护递增值，如果栈顶对应位置的高度大于当前i的高度会出栈
        for (int i = 0; i < n; ++i) {
            while (!monoStack.empty() && heights[monoStack.top()] >= heights[i]) {
                monoStack.pop();
            }

            // 左边比当前小的值是栈顶（大的或者相等的都弹出了），如果栈空则为最左边，设置为-1
            left[i] = monoStack.empty() ? -1: monoStack.top();
            monoStack.push(i);
        }

        vector<int> right(n, -1);
        monoStack = stack<int>();
        // 找到右边最小高度对应的i,栈里维护递增值，如果栈顶对应位置的高度大于当前i的高度会出栈
        for (int j = n - 1; j >= 0; --j) {
            while (!monoStack.empty() && heights[monoStack.top()] >= heights[j]) {
                monoStack.pop();
            }
            // 右边比当前小的值是栈顶，如果栈空则为最右边，设置为n
            right[j] = monoStack.empty() ? n: monoStack.top();
            monoStack.push(j);
        }

        int ans = 0;
        for (int mid = 0; mid < n; ++mid) {
            ans = max(ans, heights[mid] * (right[mid] - left[mid] - 1));
        }

        return ans;
    }


    // 枚举所有高度，找最低的，形成矩形
    int largestRectangleAreaHeight(vector<int>& heights) {
        int n = heights.size();

        int ans = 0;
        for (int mid = 0; mid < n; ++mid) {
            int left = mid;
            while (left - 1 >= 0 && heights[left - 1] >= heights[mid]) {
                --left;
            }

            int right = mid;
            while (right + 1 < n && heights[right + 1] >= heights[mid]) {
                ++right;
            }

            ans = max(ans, heights[mid] * (right - left + 1));
        }

        return ans;
    }

    int largestRectangleAreaWidth(vector<int>& heights) {
        int n = heights.size();

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int minHeight = INT_MAX;

            for (int j = i; j < n; ++j) {
                // cout << "j: " << j << endl;
                minHeight = min(minHeight, heights[j]);
                // cout << "ans: " << ans << "\t" << j - i + 1 << endl;
                ans = max(ans, minHeight * (j - i + 1));
            }
        }

        return ans;
    }
};
