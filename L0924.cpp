class UnionFind {
public:
    UnionFind(int len) {
        parent.resize(len, -1);
    }


    int findRootParent(int p) {
        if (parent[p] == -1 || p == parent[p]) {
            return p;
        }

        return findRootParent(parent[p]);
    }

    void unionConn(int p1, int p2) {
        int p1Root = findRootParent(p1);
        int p2Root = findRootParent(p2);
//        cout << p1 << "->" << p1Root << endl;
//        cout << p2 << "->" << p2Root << endl;
        if (p1Root != p2Root) {
//            cout << "parent: " << p1Root << "->" << p2Root << endl;
            parent[p1Root] = p2Root;
        }
    }

private:
    vector<int> parent;

};

class Solution0924 {
public:
    static bool cmp(vector<int>& l, vector<int>& r) {
        return l[1] > r[1] || (l[1] == r[1] && l[0] < r[0]);
    }

    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        int rowLen = graph.size();
        if (rowLen == 0) {
            return 0;
        }

        int colLen = graph[0].size();
        if (colLen == 0) {
            return 0;
        }

        UnionFind uf(rowLen);
        for (int row = 0; row < rowLen; ++row) {
            for (int col = 0; col < colLen; ++col) {
                if (graph[row][col] == 1) {
//                    cout << "uf.unionConn(row, col): " << row << "\t" << col << endl;
                    uf.unionConn(row, col);
                }
            }
        }

        // 根节点上设置为最大计数
        unordered_map<int, int> rootNum;
        for (int i = 0; i < rowLen; ++i) {
            int rootP = uf.findRootParent(i);
            ++rootNum[rootP];
        }

        // 染色: 颜色是root节点ID
        vector<int> color(rowLen);
        // 每个节点所在的联通集合大小，为根节点的计数
        vector<int> groupNum(rowLen, -1);
        for (int i = 0; i < rowLen; ++i) {
            int rootP = uf.findRootParent(i);
//            cout << "parent: " << i << "->" << rootP << endl;
            color[i] = rootP;
            groupNum[i] = rootNum[rootP];
        }

/*
        for (auto& p: rootNum) {
            cout << p.first << " : " << p.second << endl;
        }
        cout << endl;
*/

        map<int, int> nodeNumPerColor;
        for (int i = 0; i < initial.size(); ++i) {
            ++nodeNumPerColor[color[initial[i]]];
        }

        vector<vector<int>> ans;
        for (int num: initial) {
//            cout << num << endl;
//            cout << groupNum[num] << "\t" << nodeNumPerColor[color[num]] << endl;
            if (nodeNumPerColor[color[num]] == 1) {
                //return initial[i];
                ans.push_back({num, groupNum[num]});
                continue;
            }

            ans.push_back({num, 0});
        }

//        cout << "sort: " << endl;
//        for (auto& it: ans) {
//            cout << it[0] << ":" << it[1] << "\t";
//        }
//        cout << endl;
        sort(ans.begin(), ans.end(), cmp);
//        for (auto& it: ans) {
//            cout << it[0] << ":" << it[1] << "\t";
//        }
//        cout << endl;

        if (!ans.empty()) {
            return ans.at(0).at(0);
        }

        return 0;
    }
};

TEST(UnionFind, testcase1) {
    Solution0924 s;
    vector<vector<int>> graph =
            {{1,0,0,0},{0,1,0,0},{0,0,1,1},{0,0,1,1}};
    vector<int> init =
            {3,1};
    EXPECT_EQ(3, s.minMalwareSpread(graph, init));
}

TEST(UnionFind, testcase2) {
    Solution0924 s;
    vector<vector<int>> graph =
            {{1,1,1},{1,1,1},{1,1,1}};
    vector<int> init =
            {1,2};
    EXPECT_EQ(1, s.minMalwareSpread(graph, init));
}

TEST(UnionFind, testcase3) {
    Solution0924 s;
    vector<vector<int>> graph =
            {{1,1,0},{1,1,0},{0,0,1}};
    vector<int> init =
            {0,1};
    EXPECT_EQ(0, s.minMalwareSpread(graph, init));
}

TEST(UnionFind, testcase4) {
    Solution0924 s;
    vector<vector<int>> graph =
            {{1,0,0},{0,1,0},{0,0,1}};
    vector<int> init =
            {0,2};
    EXPECT_EQ(0, s.minMalwareSpread(graph, init));
}


TEST(UnionFind, testcase5) {
    Solution0924 s;
    vector<vector<int>> graph =
            {{1,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,1}};

    vector<int> init =
            {1,3};
    EXPECT_EQ(1, s.minMalwareSpread(graph, init));
}

TEST(UnionFind, testcase6) {
    Solution0924 s;
    vector<vector<int>> graph =
            {{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,1,0},{0,0,0,1,1,0},{0,0,0,0,0,1}};


    vector<int> init =
            {5,0};
    EXPECT_EQ(0, s.minMalwareSpread(graph, init));
}

TEST(UnionFind, testcase7) {
    Solution0924 s;
    vector<vector<int>> graph =
            {{1,0,0,0,0,0,0,0},
             {0,1,1,0,0,1,0,0},
             {0,1,1,0,0,0,0,0},
             {0,0,0,1,0,0,0,0},
             {0,0,0,0,1,0,0,0},
             {0,1,0,0,0,1,0,0},
             {0,0,0,0,0,0,1,0},
             {0,0,0,0,0,0,0,1}};


    vector<int> init =
            {1,6};
    EXPECT_EQ(1, s.minMalwareSpread(graph, init));
}
