class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result("");
        int n =  indices.size();
        vector<int> pos(n, 0);
        for (int i = 0; i < n; ++i) {
            pos[indices[i]] = i;

        }

        for (int j = 0; j < n; ++j) {
            result.push_back(s[pos[j]]);
        }

        return result;
    }
};

TEST(restoreStringabc, Test1)
{
    Solution s1;
    vector<int> data = {0,1,2};
    EXPECT_EQ("abc",s1.restoreString("abc", data));
}

TEST(restoreStringaiohn, Test1)
{
    Solution s1;
    vector<int> data = {3,1,4,2,0};
    EXPECT_EQ("nihao",s1.restoreString("aiohn", data));
}


bool cmpFunction(vector<int>& a, vector<int>& b) {
    return a[0] > b[0] || (a[0] == b[0] && a[1] <= b[1]);
}

class Solution1 {
public:
    vector<vector<int>> ReconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmpFunction);
        int n = people.size();
        list<vector<int>> lst;
        for (const vector<int>& person: people) {
            int spaces = person[1];
            auto it = lst.begin();
            for (int i = spaces; i > 0; --i) {
                ++it;
            }
            lst.insert(it, person);
        }

        vector<vector<int>> result(lst.begin(), lst.end());
        return result;
    }
};

TEST(reconstructQueue666, Test1)
{
    Solution1 s1;
    vector<vector<int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    cout << endl;
    for (auto& p1: s1.ReconstructQueue(people)) {
        cout << p1[0] << ", " << p1[1] << "\t";
    }
    cout << endl;

    //EXPECT_EQ("nihao",s1.restoreString("aiohn", data));
}

class LogSystem {
private:
    map<int, int> logm;
public:
    LogSystem()
    {

    }

    void Add(int id, int timeStamp)
    {
        logm[id] = timeStamp;
    }

    int Delete(int id)
    {
        auto it = logm.find(id);
        if (it != logm.end()) {
            logm.erase(it);
            return 0;
        }

        return -1;
    }

    int Query(int startTime, int endTime)
    {
        int count = 0;
        for (auto& item: logm) {
            if (item.second >= startTime && item.second <= endTime) {
                ++count;
            }
        }

        return  count;
    }
};



class Solution001 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            auto it = mp.find(target - nums[i]);
            if (it != mp.end()) {
                return {i, it->second};
            }

            mp.insert(pair<int, int>(nums[i], i));
        }

        return {};
    }
};

TEST(twoSum111, Test1)
{
    Solution001 s1;
    vector<int> nums = {2, 7, 11, 15};
    for (auto& p1: s1.twoSum(nums, 22)) {
        cout << p1 << "\t";
    }
    cout << endl;

    //EXPECT_EQ("nihao",s1.restoreString("aiohn", data));
}

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution0002 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return nullptr;
    }
};


class Solution1247 {
public:
    int minimumSwap(string s1, string s2) {
        int s1Length = s1.size();
        int s2Length = s2.size();
        if (s1Length != s1Length) {
            return -1;
        }

        int count = 0;
        for (int i = 0; i < s1Length; ++i) {
            cout << s1 << endl << s2 << endl;
            cout << i << ": " << s1[i] << "  " << s2[i] << endl;

            if (s1[i] ==  s2[i]) {
                cout << "passed" << endl;
                continue;
            }

            bool findedFlag = false;

            // 当前位置不同，当前字符为s1[i]为x（x-y）或者y（y-x），s1继续往后找s1[j]和s1[i]相同，找到就交换完成i位置的相同
            for (int j = i + 1; j < s1Length; ++j) {
                cout << j << "j1: " << s1[j] << "  " << s2[i] << endl;
                if (s1[i] == s1[j] && s1[j] != s2[j]) {
                    ++count;
                    cout << "senario1 before: \n" << s1 << endl << s2 << endl;
                    char tempChar = s2[i];
                    s2[i] = s1[j];
                    s1[j] = tempChar;
                    findedFlag = true;
                    cout << "senario1 after: \n" << s1 << endl << s2 << endl << endl;
                    break;
                }
            }

            // s1往后找没有找到和s1[j]相同的字符，说明后面都和s2[i]相同，即xyyy或者yxxx，这种情况就需要在s2中往后找s1[i]，形成yx组合进行两次交换
            if (!findedFlag) {
               for (int j = i + 1; j < s1Length; ++j) {
                   cout << j << "j2: " << s1[ i + 1] << "  " << s2[j] << endl;
                   if (s2[j] == s1[i] && s1[j] != s2[j]) {
                       count += 2;
                       // 交换s2[j]和s2[i]
                       cout << "senario2 before: \n" << s1 << endl << s2 << endl;
                       char tempChar = s2[j];
                       s2[j] = s2[i];
                       s2[i] = tempChar;
                       findedFlag = true;
                       cout << "senario2 after: \n" << s1 << endl << s2 << endl << endl;
                       break;
                   }
               }
            }

            if (!findedFlag) {
                return -1;
            }
        }

        cout << s1 << endl << s2 << endl;
        if (s1 == s2) {
            return count;
        } else {
            return -1;
        }
    }
};

TEST(Solution1247minimumSwap, Test1)
{
    Solution1247 s;
    string s1 = "xxyyxyxyxx";
    string s2 = "xyyxyxxxyx";

    EXPECT_EQ(4,s.minimumSwap(s1, s2));
}

class Solution455 {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n = s.size();
        int m = g.size();
        cout << "m: " << m << endl;
        int bisIndex = n - 1;
        int count = 0;
        for (int childIndex = m - 1; childIndex >= 0; --childIndex) {
            cout << childIndex << ":" << bisIndex << "\t --  " << s[bisIndex] << " - " << g[childIndex] << endl;
            if (bisIndex >= 0 && s[bisIndex] >= g[childIndex]) {
                ++count;
                --bisIndex;
            }
        }
        return count;
    }
};

TEST(findContentChildren111, Test1)
{
    Solution455 s1;
    vector<int> g = {1,2,3};
    vector<int> s = {3};
    //cout << s1.findContentChildren(g,s ) << endl;

    EXPECT_EQ(1,s1.findContentChildren(g,s ));
}


class Solution0045 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxPos = 0;
        int count = 0;
        int startPoint = 0; // 起跳点从0开始
        for (int i = 0; i < n - 1; ++i) {
            if (maxPos >= i) { // 如果0是0，可能跳不出去
                // cout << "i: " << i << "\t maxPos: " << maxPos << "\t i + nums[i]: " << i + nums[i] << endl;
                maxPos = max(maxPos, i + nums[i]);
                if (i == startPoint) { // i到达起跳点，跳；i = 0 是第一个起跳点
                    startPoint = maxPos; // 起跳点更新为前面计算出来的能达到最远的点maxPos
                    ++count; // 步骤记录

                    // cout << "No." << count << " jump: " << " from " << i << " to " << end << endl;
                }
            }
        }

        return  count;
    }

    int jump1(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        int count = 0;
        while (i > 0) {
            cout << endl << "pos: " << i << endl;
            for (int j = 0; j < i; ++j) {
                cout << "j: " << j << "\t";
                if (nums[j] + j >= i) {
                    cout << endl << "found: " << j << endl;
                    ++count;
                    i = j;
                    break;
                }
            }
        }

        return count;
    }
};


class cmpPair {
public:
    bool operator() (const pair<char, int>& pa, const pair<char, int>& pb) {
        //cout << "operator() " << pa.first << " vs "<< pb.first  << "  2: " << pa.second << " vs " << pb.second << endl;
        return pa.second < pb.second;
    }
};

class Solution0621 {

public:
    static bool sourceTasksCompare(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    int leastInterval1(vector<char>& tasks, int n) {

        map<int, int> mp;
        int ans = 0;
        string result;
        int taskNum = tasks.size();
        for (int i = 0; i < taskNum; ++i) {
            mp[tasks[i] - 'A']++;
        }

        vector<pair<int, int>> sourceTasks(mp.begin(), mp.end());
        sort(sourceTasks.begin(), sourceTasks.end(), sourceTasksCompare);

        for (auto& pe: sourceTasks) {
            char ch = 'A' + pe.first;
            cout << ch << "-" << pe.first << " : " << pe.second << endl;
        }

        while (sourceTasks[0].second > 0) { // 位置0表示任务最多的任务类型，second即任务个数
            int i = 0;
            while (i <= n) { // 给本轮的n个位置分配任务
                if (sourceTasks[0].second == 0) { // 任务最多的已经被取完了；什么情况下会出现呢？：
                    break;
                }

                if (i < sourceTasks.size() && sourceTasks[i].second > 0) { // 本轮总计有n个，第i个一定小于任务的种类个数时，查一下i对应的任务类型是否已经分配完成，分配或者作为等待任务
                    sourceTasks[i].second--;
                    char ch = sourceTasks[i].first + 'A';
                    result.push_back(sourceTasks[i].first + 'A');
                    cout << "task: " << ch << "-" << sourceTasks[i].first << " : " << sourceTasks[i].second << endl;
                } else {
                    result.push_back(' ');
                    cout << "a waiting cycle" << endl;
                }

                ++i;
                ++ans;
            }

            sort(sourceTasks.begin(), sourceTasks.end(), sourceTasksCompare);
            cout << endl;
            for (auto& pe: sourceTasks) {
                char ch = 'A' + pe.first;
                cout << ch << "-" << pe.first << " : " << pe.second << endl;
            }
        }

        cout << result << endl;
        return ans;
    }

    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (char ch: tasks) {
            mp[ch]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>, cmpPair> pq;
        for (auto& pr: mp) {
            //cout << "push: " << pr.first << " - " << pr.second << endl;
            pq.push(pr);
        }

        int ans = 0;
        string result;
        vector<pair<char, int>> vc;
        while (!pq.empty()) {
            int i = 0;
            vc.clear();

            // 开始排列n个任务
            cout << "arrange " << n + 1 << " tasks begin:" << endl;
            while (i <= n && !(vc.empty() && pq.empty())) {
                cout << "i : " << i << endl;

                if (!pq.empty()) {
                    pair<char, int> top = pq.top();
                    pq.pop();
                    result.push_back(top.first);
                    top.second--;
                    if (top.second > 0) {
                        vc.push_back(top);
                    }
                } else {
                    result.push_back(' ');
                }

                ++ans;
                ++i;


            }
            cout << result << endl;
            cout << ans << endl;
            cout << "arrange " << n << " tasks end:" << endl;


            for (auto& item: vc) {
                pq.push(item);
            }
        }

        cout << result << endl;
        return ans;
    }



};

class TrieNode {
private:
    TrieNode* children[26];
    int count;

public:
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            children[i] = NULL;
        }
        count = 0;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; ++i) {
            if (children[i] != NULL) {
                delete children[i];
                children[i] = NULL;
            }
        }
    }


    TrieNode* get(char c) {
        if (children[c - 'a'] == NULL) {
            children[c - 'a'] = new TrieNode();
            ++count;
        }

        return children[c - 'a'];
    }

    int getCount() {
        return count;
    }
};

class Solution0820 {
public:
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode trie;
        unordered_map<TrieNode*, int> nodes;

        int n = words.size();
        for (int i = 0; i < n; ++i) {
            string word = words[i];
            TrieNode* cur = &trie;
            for (int j = word.length() - 1; j >= 0; --j) {
                cur = cur->get(word[j]);
            }
            nodes[cur] = i;
        }

        int ans = 0;
        for (auto& item: nodes) {
            if (item.first->getCount() == 0) {
                ans += words[item.second].length() + 1;
            }
        }

        return ans;
    }
};


class Trie {
private:
    int count;
    //Trie208* node[26];
    vector<Trie*> nodes;
    bool isEnd;

public:
    /** Initialize your data structure here. */
    Trie() {
        nodes.reserve(26);
        nodes.resize(26, nullptr);

        count = 0;
        isEnd = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        int n = word.size();
        Trie* cur = this;
        for (int i = 0; i < n; ++i) {
            if (cur->nodes[word[i] - 'a'] == nullptr) {
                cur->nodes[word[i] - 'a'] = new Trie();
                cur->count++;
            }

            cur = cur->nodes[word[i] - 'a'];
        }

        cur->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        int n = word.size();
        Trie* cur = this;
        for (int i = 0; i < n; ++i) {
            if (cur->nodes[word[i] - 'a'] == nullptr) {
                return false;
            }

            cur = cur->nodes[word[i] - 'a'];
        }

        return cur->isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int n = prefix.size();
        Trie* cur = this;
        for (int i = 0; i < n; ++i) {
            if (cur->nodes[prefix[i] - 'a'] == nullptr) {
                return false;
            }

            cur = cur->nodes[prefix[i] - 'a'];
        }

        return true;
    }
};


class Solution0648 {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for (auto& word: dictionary) {
            t.insert(word);
        }

        int n = sentence.size();
        int i = 0;
        string word;
        string ans;
        while (i < n) {
            cout << i << endl;
            word.clear();
            for (int j = i; j < n; ++j) {
                if (sentence[j] == ' ') {

                    break;
                }
                word.push_back(sentence[j]);
            }

            bool found = false;
            for (int k = 1; k < word.size(); ++k) {
                string prefix = word.substr(0, k);
                if (t.search(prefix)) {
                    found = true;
                    ans.append(prefix).push_back(' ');
                    break;
                }
            }

            if (!found) {
                ans.append(word).push_back(' ');
            }

            i += word.size() + 1;
        }

        if (!ans.empty()) {
            ans.pop_back();
        }

        return ans;
    }
};
