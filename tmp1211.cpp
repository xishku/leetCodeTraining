void printVector(vector<int> v) {
    for (auto el : v) {
        cout << el << "\t";
    }
    cout << endl;
}

class Solution1208 {
public:
    int equalSubstringOld(string s, string t, int maxCost)
    {
        int left = 0;
        int right = 0;
        int cost = 0;
        int n = s.size();
        int result = 0;

        while (right < n) {
            //cout << "left: " << left << "  right: " << right ;
            cost += abs(s.at(right) - t.at(right));
            //cout << "  cost: " << cost << endl;
            while (cost > maxCost) {
                //cout << ">> left: " << left << "  right: " << right ;
                cost -= abs(s.at(left) - t.at(left));
                //cout << "  cost: " << cost << endl;
                ++left;
            }

            result = max(result, right - left + 1);
            //cout << "result: " << result << endl;
            ++right;
        }

        return result;
    }

    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0;
        int left = 0;
        int right = 0;
        int n = t.size();
        int cost = 0;
        while (right < n) {
            cost += abs(s[right] - t[right]);
            while (cost > maxCost) {
                cost -= abs(s[left] - t[left]);
                ++left;
            }

            ans = max(ans, right - left + 1);
            ++right;
        }

        return ans;
    }
};

class Solution0209 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        int ans = n + 1;
        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < n) {
            sum += nums[right];
            while (sum >= s) {
                // cout << left << "\t" << right << endl;
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            ++right;
        }

        if (ans == n + 1) {
            return 0;
        }

        return ans;
    }
};

class Solution0003 {
public:
    int getPosInStr(string&s , int left, int right, char matchChar) {
//        cout << "getPosInStr\t" << s.substr(left, right - left + 1) << endl;
        for (int i = left; i <= right; ++i) {
            if (matchChar == s[i]) {
                return i;
            }
        }

        return -1;
    }

    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0 ) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }


        int left = 0;
        int right = 1;
        int ans = 0;

        while (right < n) {
//            cout << left << "\t" << right << endl;
            int pos = getPosInStr(s, left, right - 1, s[right]);
            if (pos == -1) {
                ++right;
            } else {
                ans = max(ans, right - left);
                left = pos + 1;
//                cout << "set left=" << left << endl;
            }
        }
        ans = max(ans, right - left);

        return ans;
    }
};

class Solution1004 {
public:
    int longestOnes(vector<int>& A, int K) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }

        if (n <= K) {
            return n;
        }

        int left = 0;
        int right = 0;
        int count = 0;
        int ans = 0;
        while (right < n) {
            count += 1 - A[right];
            while (count > K) {
                count -= 1 - A[left];
                ++left;
            }

//            cout << left << "\t" << right  << "\tcount: " << count << endl;
            ans = max(ans, right - left + 1);

            ++right;
        }

        return ans;
    }
};

class Solution0560 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return nums[0] == k ? 1 : 0;
        }

        // key放置某个前缀和，value放置key出现的次数
        unordered_map<int, int> mp;

        int count = 0;
        mp[0] = 1; // 第一个前缀和是0，个数是1，也可以写为++mp[0]
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int peerKey = sum - k;
            if (mp.find(peerKey) != mp.end()) {
                count += mp[peerKey];
            }

            ++mp[sum];
        }

        return count;
    }

    void test() {
        vector<int> nums = {-1, -1, 1};
        cout << "1=" << subarraySum(nums, 0) << endl;

        nums = {1,1,1,1,3,1,3,2,4};
        cout << "5=" << subarraySum(nums, 4) << endl;
    }
};

class Solution0523 {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }

        int sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];

            if (k != 0) {
                sum = sum % k;
            }

            if (mp.find(sum) != mp.end()) {
                if (i - mp[sum] >= 2) {
                    return true;
                }
            } else {
                mp[sum] = i; // 只有找不到同余才更新，否则会把不符合距离的位置刷新掉，如k=4，1,2，4，4
            }
        }

        return false;
    }

    void test() {
        vector<int> nums = {23,2,4,6,7};
        cout << "1=" << checkSubarraySum(nums, 6) << endl;
        nums = {23,2,6,4,7};
        cout << "1=" << checkSubarraySum(nums, 6) << endl;
        nums = {0,0};
        cout << "0=" << checkSubarraySum(nums, 6) << endl;
    }
};


class Solution0974 {
public:
    int subarraysDivByKOld(vector<int>& A, int K) {
        int n = A.size();
        int sum = 0;
        unordered_map<int, int> mp;
        int count = 0;

        mp[0] = 1;
        for (int i = 0; i < n; ++i) {
            //cout << "\n\n round: " << i << endl;
            sum += A.at(i);

            if (K != 0) {
                sum = sum % K;
                sum = (sum + K) % K;
            }

            if (mp.find(sum) != mp.end()) {
                count += mp[sum];
                //cout << "sum: "<< sum << " count : " << count << endl;
            }

            mp[sum]++;
            //cout << "sum: "<< sum << endl;
            //printMap(mp);
        }

        return count;
    }

    int subarraysDivByK(vector<int>& A, int K) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }

        map<int, int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];

            if (K != 0) {
                sum = sum % K;
                sum = (sum + K) % K;
            }

            if (mp.find(sum) != mp.end()) {
                count += mp[sum];
            }

            ++mp[sum];
        }

        return count;
    }

    void test() {
        vector<int> nums = {4,5,0,-2,-3,1};
        cout << "7=" << subarraysDivByK(nums, 5) << endl;
    }
};

class Solution1094 {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        const int n = 1001;
        vector<int> work(1001, 0);
        for (auto& t: trips) {
            work[t[1]] += t[0];
            work[t[2]] -= t[0];
        }

        for (int i = 1; i < n; ++i) {
            work[i] += work[i - 1];
            if (work[i] > capacity) {
                return false;
            }
        }

        return true;
    }

    void test() {

    }
};

class Solution1109 {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        if (n == 0) {
            return {};
        }
        vector<int> flights(n, 0);
        for (auto& bk: bookings) {
           flights[bk[0] - 1] += bk[2];
           if (bk[1] < n) {
               flights[bk[1]] -= bk[2];
           }
        }

        for (int i = 1; i < n; ++i) {
            flights[i] += flights[i - 1];
        }

        return flights;
    }

    void  test() {
        vector<vector<int>> bookings = {{1,2,10},{2,3,20},{2,5,25}};
        for (auto el: corpFlightBookings(bookings, 5)) {
            cout << el << "\t";
        }

        cout << endl;
    }
};

class Solution0121 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) {
            return 0;
        }

        vector<int> profits(n, 0);
        int ans = 0;
//        profits[0] = 0; 已经初始化
        for (int i = 1; i < n; ++i) {
            int p = prices[i] - prices[i - 1];
//            cout << "i: " <<  profits[i - 1] + profits[i];
            profits[i]= max(p, profits[i - 1] + p);
            ans = max(ans, profits[i]);
//            cout << endl << ans << endl;
        }
        return ans;
    }

    void test() {
        vector<int> nums = {7,1,5,3,6,4};
        cout << "5=" << maxProfit(nums) << endl;

        nums = {7,6,4,3,1};
        cout << "0=" << maxProfit(nums) << endl;
    }
};

class Solution0210 {
private:
    vector<vector<int>> edges;
    // 访问状态 0未搜索 1搜索中 2完成
    vector<int> visited;
    //栈
    vector<int> pstack;
    // 判断是否有环
    bool valid = true;

public:
    void dfs(int u) {
        cout << "dfs: " << u << endl;
        visited[u] = 1;
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (!valid) {
                    return;
                }
            }
            else if (visited[v] == 1) {
                valid = false;
                return;
            }
        }
        visited[u] = 2;

        pstack.push_back(u);
    }



    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses <= 0) {
            return {};
        }

        edges.resize(numCourses);
        pstack.clear();
        valid = true;
        visited.resize(numCourses, 0);

        for (auto& item: prerequisites) {
            edges[item[0]].push_back(item[1]);
        }

//        cout << "edges: " << endl;
//        for (auto& item: edges) {
//            cout << "\ninner:";
//            for (auto i: item) {
//                cout << i << "\t";
//            }
//        }


        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] != 0)
            {
                continue;
            }

            dfs(i);

            if (!valid) {
                return {};
            }
        }

        //reverse(pstack.begin(), pstack.end());
        return pstack;
    }

    void test() {

        vector<vector<int>> p = {{1,0},{2,0},{3,1},{3,2}};
//        for (auto el: findOrder(4, p)) {
//            cout << el << "\t" ;
//        }
//        cout << endl;

        p = {{1,0},{1,2},{0,1}};
        p = {{1,0},{2,1},{3,2},{1,3}};
        for (auto el: findOrder(4, p)) {
            cout << el << "\t";
        }
        cout << endl;

    }
};


class Solution02101 {
private:
    vector<vector<int>> edges;

    vector<int> indeg;

    vector<int> result;

public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (auto& it: prerequisites) {
            edges[it[1]].push_back(it[0]); // it[1]依赖it[0]
            ++indeg[it[0]]; // 被依赖次数
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int head = q.front();
            q.pop();
            result.push_back(head);
            for (auto v: edges[head]) {
                --indeg[v];
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (numCourses != result.size()) {
            return {};
        }

        return result;
    }

    void test() {

        vector<vector<int>> p =
                {{0,1},{0,2},{1,2}};
//                {{1,0},{2,0},{3,1},{3,2}};
//        for (auto el: findOrder(4, p)) {
//            cout << el << "\t" ;
//        }
//        cout << endl;

//        p = {{1,0},{1,2},{0,1}};
//        p = {{1,0},{2,1},{3,2},{1,3}};
        for (auto el: findOrder(3, p)) {
            cout << el << "\t";
        }
        cout << endl;

    }
};


class Solution0005 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) {
            return "";
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                cout << dp[i][j] << "\t";
//            }
//            cout << endl;
//        }

        int ans = 0;
        string result;
        for (int length = 0; length < n; ++length) {
//            cout << "length: " << length << endl;
            for (int i = 0; i + length <n; ++i) {
                int j = i + length;
//                cout << i << " to " << j << endl;
                // 处理i到j字符串是否回文串
                if (length == 0) { // i == j只有1个字符，是回文串
                    dp[i][j] = 1;
//                    cout << " 0 , " << dp[i][j] << endl;
                }
                else if (length == 1) { // 两个字符
                    dp[i][j] = (s[i] == s[j]);
//                    cout << " 1 , " << dp[i][j] << endl;
                } else { //3个以上字符
//                    cout << "dp[i + 1][j - 1]=" << dp[i + 1][j - 1] << endl;
//                    cout << s[i] << "=" << s[j] << "\t";

                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1]; // dp[i + 1][j -1]长度小2，所以在前面算过了
//                    cout << " 2+ , " << dp[i][j] << endl;
                }

                if (dp[i][j] && j - i + 1 > ans) { // length = j - i
                    ans = length + 1;
                    result = s.substr(i, ans);
//                    cout << "from " << i << " to " << j ;
//                    cout << "\tfound bigger: " << result << endl;
                }
            }
        }

        return result;
    }

    void test() {
        cout << "bab=" << longestPalindrome("babad") << endl;
    }
};

class Solution {
private:
    static constexpr int SEG_COUNT = 4;
private:
    vector<int> segments;
    vector<string> ans;


public:
    void dfs(string& s, int segId, int segStart) {
        if (segId == SEG_COUNT) {
            if (segStart == s.size()) {
                string ip;
                for (int i = 0; i < SEG_COUNT; ++i) {
                    ip.append(to_string(segments[i])).push_back('.');
                }
                ip.pop_back();
                cout << "ip: " << ip << endl;
                ans.push_back(move(ip));
            }

            cout << "invalid ip address" << endl;
            return;
        }


        if (segId >= SEG_COUNT) {
            cout << "segId >= 4 : " << segId << endl;
            return;
        }

        if (s[segStart] == '0') {
            segments[segId] = 0;
            cout << "0 segments[segId: " << segId << "]\t :" << 0 << endl;
            dfs(s, segId + 1, segStart + 1);
        }

        int addr = 0;
        for (int segEnd = segStart; segEnd < s.size(); ++segEnd) {
            cout << endl << "normal segEnd:" << segEnd << endl;
            addr = addr * 10 + (s[segEnd] - '0');
            if (addr > 0 && addr <= 0xFF) {
                segments[segId] = addr;
                cout << "=segments[segId: " << segId << "]\t :" << segments[segId] << endl;
                dfs(s, segId + 1, segEnd + 1);
            } else {
                break;
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        dfs(s, 0, 0);
        return ans;
    }

    void test() {
        for(auto& ip: restoreIpAddresses("101023")) {
            cout << ip << endl;
        }
    }
};
