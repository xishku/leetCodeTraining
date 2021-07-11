//
// Created by g00234683 on 2020/10/14.
//

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <thread>         // std::thread
#include <mutex>          // std::mutex


using namespace std;


class Trie {
private:
    bool isEnd = false;
    Trie* next[26];

public:
    Trie() {
        isEnd = false;
        memset( next, 0, sizeof(next));
    }

    void insert(string word) {
        Trie* node = this;
        for ( char ch: word) {
            if ( node->next[ ch - 'a' ] == NULL) {
                node->next[ ch - 'a' ] = new Trie();
            }

            node = node->next[ ch - 'a' ];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        cout << "search : " << word << endl;

        Trie* node = this;
        cout << "node address: " << node << endl;
        for ( char ch : word ) {
            cout << "current character : " << ch << "  " <<  ch - 'a' << endl;


            if (node->next[ ch - 'a' ] != NULL) {
                cout << "next is not NULL" << endl;
                node = node->next[ ch - 'a'];
            } else {
                return false;
            }
        }
        cout << "node address: " << node << endl;
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        cout << "startsWith : " << prefix << endl;

        Trie* node = this;
        for ( char ch : prefix ) {
            if (node->next[ ch - 'a'] != NULL) {
                node = node->next[ ch - 'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }
};

string replaceWordsSimple(vector<string>& dictionary, string sentence) {
    set<string> prefixSet;
    for ( string word: dictionary) {
        prefixSet.insert(word);
        cout << word << endl;
    }

    string resultStr;

    int i = 0;
    int j = 0;
    while (i < sentence.length() && j < sentence.length()) {
        while (j < sentence.length() && sentence[j] != ' ') {
            ++j;
        }

        string thisWord = sentence.substr(i, j - i);
        cout << thisWord << endl;
        string prefix = thisWord;
        for ( int i = 0; i < thisWord.length(); ++i ) {
            string tmpStr = thisWord.substr(0, i);
            if ( prefixSet.find( tmpStr ) != prefixSet.end()) {
                prefix = tmpStr;
                break;
            }
        }

        resultStr.append(prefix).append(" ");

        i = j + 1;
        j = i;
    }

    if (!resultStr.empty()) {
        resultStr.pop_back();
    }
    return resultStr;
}


string replaceWords(vector<string>& dictionary, string sentence) {
    Trie trieNode;
    for ( string prefix: dictionary )  {
        trieNode.insert(prefix);
    }

    string resultStr;

    int i = 0;
    int j = 0;
    while (i < sentence.length() && j < sentence.length()) {
        while (j < sentence.length() && sentence[j] != ' ') {
            ++j;
        }

        string thisWord = sentence.substr(i, j - i);
        cout << "thisWord: " << thisWord << endl;
        string prefix = thisWord;
        for ( int n = 1; n <= thisWord.size(); ++n ) {
            cout << n << endl;
            string tmpStr = thisWord.substr(0, n);
            cout << "tmpStr: " << tmpStr << endl;
            if ( trieNode.search( tmpStr )) {
                prefix = tmpStr;

                break;
            }
        }

        resultStr.append(prefix).append(" ");

        i = j + 1;
        j = i;
    }

    if (!resultStr.empty()) {
        resultStr.pop_back();
    }

    return resultStr;
}

class MyTrie {
private:
    int count;
    MyTrie* next[26];

public:
    MyTrie() {
        count = 0;
        memset(next, 0, sizeof(next));
    }

    MyTrie* get(char ch) {
        cout << "get: " << ch << endl;
        MyTrie* node = this;
        cout << node << endl;
        if (node->next[ch - 'a'] == NULL) {
            node->count++;
            cout << node << " : " << count << endl;
            node->next[ch - 'a'] = new MyTrie();

            //cout << "new node : " << node << "-" << ch << endl;
        }
        node = node->next[ch - 'a'];

        return node;
    }

    int getCount() {
        return count;
    }
};

int minimumLengthEncoding(vector<string>& words) {
    MyTrie myTrie;
    unordered_map<MyTrie*, int> nodes;
    for( int wordIdx = 0; wordIdx < words.size(); ++wordIdx) {
        //string s;
        MyTrie* cur = &myTrie;
        for (int i = words.at(wordIdx).size() - 1; i >= 0; --i) {
            cur = cur->get(words.at(wordIdx).at(i));
        }
        //nodes.insert(make_pair(cur, wordIdx));
        nodes[cur] = wordIdx;
    }

    int resultLength = 0;
    for( auto it = nodes.begin(); it != nodes.end(); ++it) {
        cout << it->first << " : " << it->first->getCount() << endl;
        if( it->first->getCount() == 0) {
            resultLength += words[it->second].size() + 1;
        }
    }
    return resultLength;
}

int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    int n = nums.size();
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        sum += nums.at(i);
        int sum_j = sum - k;
        if (mp.find(sum_j) != mp.end()) {
            count += mp[sum_j];
        }

        mp[sum]++;
    }

    return count;
}



bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        cout << "sum: " << sum << endl;
        if (k != 0) {
            sum = sum % k;
        }


        if (mp.find(sum) != mp.end()) {
            return true;
        }

        mp[sum]++;
    }


    return false;
}

int numberOfArithmeticSlices(vector<int>& A) {
    int n = A.size();
    int count = 0;
    int sum = 0;
    for (int i = 2; i < n; ++i) {
        if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
            ++count;
        }
        else {
            sum += count * (count + 1) / 2;
            count = 0;
        }
    }

    sum += count * (count + 1) / 2;
    return sum;
}

void dfs(int i, const vector<vector<int>>& edges, vector<int>& visited, bool& valid, vector<int>& result) {
    //cout << "dfs: " << i << endl;
    visited[i] = 1;
    for (auto target: edges[i]) {
        if (!visited[target]) {
            dfs(target, edges, visited, valid, result);
            if (!valid) {
                return;
            }
        } else if (visited[target] == 1){
            valid = false;
            return;
        }
    }
    visited[i] = 2;

    result.push_back(i);
}


vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> edges(numCourses);
    vector<int> visited(numCourses);
    vector<int> result;
    bool valid = true;

    for (const auto& info: prerequisites) {
        edges[info[1]].push_back(info[0]);
    }

    for (int i = 0; i < numCourses && valid; ++i) {
        if (!visited[i]) {
            dfs(i, edges, visited, valid, result);
        }
    }

    if (!valid) {
        return {};
    }

    reverse(result.begin(), result.end());
    return result;
}





class Solution {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 存储每个节点的入度
    vector<int> indeg;
    // 存储答案
    vector<int> result;

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (const auto& info: prerequisites) {
            edges[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        // 将所有入度为 0 的节点放入队列中
        for (int i = 0; i < numCourses; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            // 从队首取出一个节点
            int u = q.front();
            q.pop();
            // 放入答案中
            result.push_back(u);
            for (int v: edges[u]) {
                --indeg[v];
                // 如果相邻节点 v 的入度为 0，就可以选 v 对应的课程了
                if (indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        if (result.size() != numCourses) {
            return {};
        }
        return result;
    }
};


class Solution0476 {
public:
    int wiggleMaxLength(vector<int>& nums) {


        int n = nums.size();
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        int diff = 0;
        int lastDiff = 0;
        int count  = 1;
        if  (nums[1] - nums[0] > 0)  {
            lastDiff = 1;
            ++count;
        } else if (nums[1] - nums[0] < 0) {
            lastDiff = -1;
            ++count;
        }

        int maxValue = 0;
        for (int i = 2; i < n; ++i) {
            cout << i << endl;

            if (nums[i] == nums[i-1]) {
                continue;
            }

            diff = (nums[i] - nums[i - 1] > 0) ? 1 : -1;
            cout << lastDiff << "  :  " <<  diff << endl;

            if (lastDiff == 0) {
                lastDiff = diff;
                ++count;
                continue;
            }

            if (diff != lastDiff) {
                ++count;
                cout << "count: " << count << endl;
            }
            lastDiff = diff;
        }

        return count;
    }
};

class Solution0739 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> tempStack;
        int n = T.size();
        if (n == 0) {
            return T;
        }

        vector<int> ans(n, 0);
        tempStack.push(0);
        for (int i = 1; i < n; ++i) {
            while (!tempStack.empty() && T[tempStack.top()] < T[i] ) {
                ans[tempStack.top()] = i - tempStack.top();
                tempStack.pop();
            }

            tempStack.push(i);
        }

        return ans;
    }
};

class Solution0503 {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return nums;
        }

        vector<int> simpleStack;
        vector<int> ans(n, -1);
        for (int j = 0; j < n * 2; ++j) {
            int i = j % n;
            while (!simpleStack.empty() && nums[simpleStack.back()] < nums[i]) {
                ans[simpleStack.back()] = nums[i];
                // cout << simpleStack.back() << "   :  " << nums[i] << endl;
                simpleStack.pop_back();
            }

            // cout << "push back: " << i << endl;
            simpleStack.push_back(i);

        }

        return ans;
    }


    static void test() {
        Solution0503 s;
        vector<int> temperatures = {5, 4, 3, 2, 1};
        for (auto item: s.nextGreaterElements(temperatures)) {
            cout << item << "\t";
        }
        cout << endl;

        temperatures = {1, 2, 3, 4 , 5};
        for (auto item: s.nextGreaterElements(temperatures)) {
            cout << item << "\t";
        }
        cout << endl;

        temperatures = {1, 2, 1};
        for (auto item: s.nextGreaterElements(temperatures)) {
            cout << item << "\t";
        }
        cout << endl;

        temperatures = {1, 1, 1, 1, 1};
        for (auto item: s.nextGreaterElements(temperatures)) {
            cout << item << "\t";
        }
        cout << endl;
    }
};

//1334
class Solution1334 {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if (n == 0) {
            return {};
        }
        set<int> sortArr;
        for (int i = 0; i < n; ++i) {
            sortArr.insert(arr[i]);
        }

        map<int, int> mp;

        int i = 1;
        for (auto it = sortArr.begin(); it != sortArr.end(); ++it, ++i) {
            mp[*it] = i;
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = mp[arr[i]];
        }

        return ans;
    }
};

class Solution0685 {
public:
    void dfs(int u) {
        cout << "dfs: " << u << endl;
        visited[u] = 1;
        for (auto v: mp[u]) {
            cout << "browse: " << u << "->" << v << endl;
            if (visited[v] == 0) {
                ringEdges.push_back({u, v});
                dfs(v);

                if (!valid) {
                    return;;
                }
            } else if (visited[v] == 1) {
                cout << "ring found: " << u << "->" << v << endl;
                ringEdges.push_back({u, v});
                valid = false;
                while (!ringEdges.empty()) {
                    if(mp[ringEdges.back()[0]].size() == 1) {
                        break;
                    }
                    cout << "ring pop back: " << ringEdges.back()[0] << "->" << ringEdges.back()[1] << endl;
                    ringEdges.pop_back();
                }

                return;
            }
        }
        visited[u] = 2;
        result.push_back(u);
    }


    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        if (n == 0) {
            return {};
        }

        mp.clear();
        result.clear();
        visited.clear();
        valid = true;
        ringEdges.clear();
        ans.clear();

        for (auto& item: edges) {
            cout << "push: " << item[0] << "->" << item[1] << endl;
            mp[item[0]].push_back(item[1]);
        }

        for (auto& it: mp) {
            if (visited[it.first] == 0) {
                dfs(it.first);
            }

            if (!valid) {
                break;
            }
        }

        if (ringEdges.empty()) {
            return {};
        } else {
            ans.push_back(ringEdges.back()[0]);
            ans.push_back(ringEdges.back()[1]);
        }
        return ans;
    }

private:
    map<int, vector<int>> mp;
    vector<vector<int>> ringEdges;
    vector<int> result;
    vector<int> ans;
    map<int, int> visited;
    bool valid = false;
};


class Solution0008 {
public:
    int myAtoi(string s) {

        return 0;
    }

    void test() {
        string s = "42";
        cout << myAtoi(s) << endl;
    }
};




struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution0021 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* pre = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                pre->next = l1;
                pre = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                pre = l2;
                l2 = l2->next;
            }
        }

        pre->next = (l1 == nullptr ? l2 : l1);
        return preHead->next;
    }

    ListNode* mergeTwoListsRes(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }

        if (l2 == nullptr) {
            return l1;
        }

        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }

    void Test()
    {
        ListNode* l1 = new ListNode(1);
        l1->next = new ListNode(2);
        l1->next->next = new ListNode(4);

        ListNode* l2 = new ListNode(1);
        l2->next = new ListNode(3);
        l2->next->next = new ListNode(4);

        ListNode* node = mergeTwoLists(l1, l2);
        while (node != nullptr) {
            cout << node->val << "\t";
            node = node->next;
        }
        cout << endl;
    }
};

class Solution0957 {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<int, int> valueDay;
        map<int, vector<int>> dayValue;
        int repeatDays = N;
        for (int day = 1; day <= N; ++day) {
            // cout << "day : " << day << endl;
            vector<int> lastDayStatus(cells);
            cells[0] = 0;
            int value = 0;
            for(int i = 1; i < cells.size() - 1; ++i) {
                cells[i] = (lastDayStatus[i - 1] == lastDayStatus[i + 1] ? 1 : 0);
                // cout << cells[i] << "\t";
                value <<= 1;
                value += cells[i];
            }
            cells[cells.size() - 1] = 0;
            if (valueDay.find(value) == valueDay.end()) {
                valueDay[value] = day;
                dayValue[day] = cells;
                cout << "insert day = " << day << "\t value = " << bitset<8>(1UL << value) << endl;
            } else {
                repeatDays = day;
                cout << "repeatDays = " << repeatDays << endl;
                break;
            }
            // cout << endl;
        }

        cout << "repeatDays = " << repeatDays << endl;
        if (repeatDays == N) {
            return dayValue[N];
        } else {
            int pos = (N % repeatDays) + 1;
            cout << "pos = " << pos << endl;
            return dayValue[pos];
        }
    }

    void Test() {
        vector<int> cells = {1,0,0,1,0,0,1,0};
        for (int element: prisonAfterNDays(cells, 1000000000)) {
            cout << element << "\t";
        }
        cout << endl;
    }
};

class SolutionO40 {
public:
    vector<int> getLeastNumbersNormal(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(arr[i]);
        }
        return ans;
    }

    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> pq;

        for (int i = 0; i < k; ++i) {
            pq.push(arr[i]);
        }

        for (int i = k; i < arr.size(); ++i) {
           if (!pq.empty() && pq.top() > arr[i]) {
               pq.pop();
               pq.push(arr[i]);
           }
        }

        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void Test()
    {
        vector<int> arr = {0,1,2,1,7,5};
        for (auto i: getLeastNumbers(arr, 0)) {
            cout << i << "\t";
        }
    }
};

class Solution0058 {
public:
    int lengthOfLastWord(string s) {
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        int n = s.length();
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ' ') {
                return n - 1 - i;
            }
        }

        return n;
    }

    void Test()
    {
        string s = " ";
        cout << lengthOfLastWord(s) << endl;
    }
};

class Solution0038 {
public:
    string countAndSay(int n) {
        return "";
    }

    void Test()
    {
        cout << countAndSay(8) << endl;
    }
};


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution0257 {
public:
    void BuildTreePath(TreeNode* root, string path, vector<string>& treePaths) {
        string appendStr = path.empty() ? "" : "->";
        appendStr += to_string(root->val);
        path.append(appendStr);
//        cout << "BuildTreePath: " << path << endl;

        if (root->left == nullptr && root->right == nullptr) {
            treePaths.push_back(path);
            return;
        }

        if (root->left) {
            BuildTreePath(root->left, path, treePaths);
        }

        if (root->right) {
            BuildTreePath(root->right, path, treePaths);
        }
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans = {};
        string path = "";
        BuildTreePath(root, path, ans);
        return ans;
    }

    void Test() {
        TreeNode root(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left->right = new TreeNode(4);
        root.left->left = new TreeNode(5);

        for (const auto& el: binaryTreePaths(&root)) {
            cout << el << endl;
        }
    }
};

class Solution0258 {
public:
    int addDigits(int num) {
        int ans = 0;
        while (num > 0) {
            ans += num % 10;
            num /= 10;
        }

        if (ans >= 10) {
            return addDigits(ans);
        }

        return ans;
    }

    void Test() {
        cout << addDigits(123456) << endl;
    }
};


class Solution0263 {
public:
    bool isUgly(int n) {
        if (n == 0) {
            return false;
        }
        else if (n == 1) {
            return true;
        }
        else {
            while (n != 1) {
                if (n % 2 == 0) {
                    n /= 2;
                } else if (n % 3 == 0) {
                    n /= 3;
                } else if (n % 5 == 0) {
                    n /= 5;
                } else {
                    return false;
                }
            }
        }

        return true;
    }

    void Test() {
        cout << isUgly(6) << endl;
    }
};




std::mutex mtx;           // mutex for critical section

void print_block (int n, int m) {
    // critical section (exclusive access to std::cout signaled by locking mtx):
    //mtx.lock();
    for (int i=0; i<n; ++i) { std::cout << m << " - " << i << endl; }
    std::cout << '\n';
    //mtx.unlock();
}

template <int N>
struct Functional {
    enum { value = N * Functional<N - 1>::value };
};

template <>
struct Functional<0> {
    enum { value = 1 };
};

void foo() {
    int x = Functional<7>::value;

    int y = Functional<1>::value;
    cout << x << "\t" << y << endl;
}

class Solution0260 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for (int n : nums) {
            ret ^= n;
        }

        int div = 1;
        while ((div & ret) == 0) {
            div <<= 1;
        }

        int a = 0;
        int b = 0;
        for (int n : nums) {
            if (div & n) { //与标志位相同的分到a组
                a ^= n;
            } else {
                b ^= n; //与标志位不同的分到b组
            }
        }

        //a组的异或值为a，b组的异或值为b
        return {a, b};
    }

    void Test() {
        vector<int> nums = {1,2,1,3,2,5};
        for (int n : singleNumber(nums)) {
            cout << n << endl;
        }
    }
};



class Solution0017 {
public:
    vector<string> multiply(vector<string>& resSet, string& alphaStr)
    {
        vector<string> ans = {};
        if (resSet.empty()) {
            for (char alpha: alphaStr) {
                //cout << alpha << endl;
                string str = "";
                str.push_back(alpha);
                ans.push_back(str);
            }
        } else {
            for (string& s1: resSet) {
                for (char alpha: alphaStr) {
                    string s2 = s1;
                    s2.push_back(alpha);
                    ans.push_back(s2);
                }
            }
        }

        return ans;
    }


    vector<string> letterCombinations(string digits) {
        map<int, string> digitAlphaMap;
        digitAlphaMap[2] = {"abc"};
        digitAlphaMap[3] = {"def"};
        digitAlphaMap[4] = {"ghi"};
        digitAlphaMap[5] = {"jkl"};
        digitAlphaMap[6] = {"mno"};
        digitAlphaMap[7] = {"pqrs"};
        digitAlphaMap[8] = {"tuv"};
        digitAlphaMap[9] = {"wxyz"};

        vector<string> ans = {};
        for (char c: digits) {
            //cout << c - '0' << endl;
            ans = multiply(ans, digitAlphaMap[c - '0']);
        }
        return ans;
    }

    void Test() {
        for (string& str: letterCombinations("238")) {
            cout << str << endl;
        }
    }
};


class Solution0198 {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> maxValue(nums.size(), 0);
        maxValue[0] = nums[0];
        maxValue[1] = max(maxValue[0], nums[1]);
        for (int i = 2; i < nums.size(); ++i) {
            maxValue[i] = max(maxValue[i - 1], maxValue[i - 2] + nums[i]);
        }
        return maxValue[nums.size() - 1];
    }

    void Test() {
        vector<int> rs = {2,7,9,3,1};
        cout << rob(rs) << endl;
    }
};

class Solution0213 {
public:
    int robInner(vector<int>& nums, int start, int end) {
        vector<int> maxValue(nums.size(), 0);
        maxValue[start] = nums[start];
        maxValue[start + 1] = max(maxValue[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++i) {
            maxValue[i] = max(maxValue[i - 1], maxValue[i - 2] + nums[i]);
        }
        return maxValue[end];
    }

    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int maxIncluding1 = robInner(nums, 0, nums.size() - 2);
        int maxExcluding1 = robInner(nums, 1, nums.size() - 1);
        return max(maxIncluding1, maxExcluding1);
    }

    void Test() {
        vector<int> rs = {1,2,3,1};
        cout << rob(rs) << endl;
    }
};

class Solution0076 {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        for (char c: t) {
            need[c]++;
        }

        int left = 0;
        int right = 0;
        int valid = 0;
        int start = 0;
        int len = INT_MAX;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == need.size()) {
                // 记录结果集
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }

                char d = s[left];
                left++;
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d] --;
                }
            }
        }

        return len == INT_MAX? "" : s.substr(start, len);
    }

    void Test() {
        cout << minWindow("ADOBECODEBANC", "ABC") << endl;
        cout << minWindow("q", "q") << endl;
        cout << minWindow("a", "aa") << endl;
        cout << minWindow("abc", "b") << endl;
    }
};

class Solution0004 {
public:
    double getKstValue(vector<int>& nums1, vector<int>& nums2, int k) {
        int start1 = 0;
        int start2 = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        while (true) {
            cout << "k = " << k << endl;

            cout << "nums1 start1 = " << start1 << "\t nums2 start2 = " << start2 << endl;
            if (start1 == n1) {
                return nums2[start2 + k - 1];
            }

            if (start2 == n2) {
                return  nums1[start1 + k - 1];
            }

            if (k == 1) {
                cout << "k = 0 matched!" << endl;
                return min(nums1[start1], nums2[start2]);
            }
            int mid = k / 2 - 1;

            cout << "k = " << k << "\t mid = " << mid << endl;

            int newIndex1 = min(start1 + mid, n1 - 1);
            int newIndex2 = min(start2 + mid, n2 - 1);
            if (nums1[newIndex1] <= nums2[newIndex2]) {
                k -= newIndex1 - start1 + 1;
                start1 = newIndex1 + 1;
            } else {
                k -= newIndex2 - start2 + 1;
                start2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() + nums2.size();

        if (n % 2 == 1) {
            return getKstValue(nums1, nums2, (n + 1) / 2);
        } else {
            return (getKstValue(nums1, nums2, (n + 1) / 2) + getKstValue(nums1, nums2, (n + 1) / 2 + 1)) / 2.0;
        }
    }


    void Test() {
        vector<int> nums1 = {1, 3, 5, 7, 9, 11};
        vector<int> nums2 = {2, 4, 6, 8, 10, 12};
        cout << findMedianSortedArrays(nums1, nums2) << endl;

    }
};









