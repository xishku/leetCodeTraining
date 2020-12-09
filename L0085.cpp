class Solution0084 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> monoStack;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for (int i = 0; i < n; ++i) {
            while (!monoStack.empty() && heights[monoStack.top()] >= heights[i]) {
                right[monoStack.top()] = i;
                monoStack.pop();
            }

            left[i] = monoStack.empty() ? -1 : monoStack.top();
            monoStack.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }

        cout << ans << endl;
        return ans;
    }
};

class Solution0085 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix.size();
        if (m == 0) {
            return 0;
        }

        const int columnNum =  matrix[0].size();
        int ans = 0;
        vector<int> heights(columnNum, 0);
        for (int rowIndex = 0; rowIndex < matrix.size(); ++rowIndex) {
            for (int colIndex = 0; colIndex <  columnNum; ++ colIndex) {
                if (matrix[rowIndex][colIndex] == '0') {
                    heights[colIndex] = 0;
                } else {
                    ++heights[colIndex];
                }
            }

            for (auto el: heights) {
                cout << el << "\t";
            }
            cout << endl;

            Solution0084 s84;
            ans = max(ans, s84.largestRectangleArea(heights));
        }

        return ans;
    }
};
