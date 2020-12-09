class UnionFind {
public:
    UnionFind(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        count = 0;
        parent.resize(m * n, -1);
        rank.resize(m * n, 0);
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                int pos = row * n + col;
//                cout << "init: " << pos << endl;
                if (grid[row][col] == '1') {
                    parent[pos] = pos;
                    ++count;

                }
            }
        }
    }

    int getRootParent(int p) {
        if (parent[p] == p) {
            return p;
        }

        return  getRootParent(parent[p]);
    }

    void unionConn(int p1, int p2) {
        int rootP1 = getRootParent(p1);
        int rootP2 = getRootParent(p2);
//        cout << "unionConn: " << p1 << "\tparent->" << rootP1 << endl;
//        cout << "unionConn: " << p2 << "\tparent->" << rootP2 << endl;
        if (rootP1 != rootP2) {
            // 保证rootP1的rank大于等于rootP2
            if (rank[rootP1] < rank[rootP2]) {
                swap(rootP1, rootP2);
            }
            // rootP2挂到rootP1下，最小化增加rank数或者不增加
            parent[rootP2] = rootP1;
//            cout << rootP2 << "\tparent-> " << rootP1 << endl;

            // 上面已经保证了rootP1的rank大于等于rootP2，大于的情况下rank不增加，等于的情况下rank加1
            if (rank[rootP1] == rank[rootP2]) {
                rank[rootP1] += 1;
            }
            // p1和p2的联通挂接，孤岛数目减少1
            --count;
//            cout << "count: " << count << endl;
        }
    }

    int getCount() {
        return count;
    }


private:
    int count;
    vector<int> rank;
    vector<int> parent;
};

class Solution0200 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (m == 0) {
            return 0;
        }

        int n = grid[0].size();
        if (n == 0) {
            return 0;
        }

        UnionFind uf(grid);
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                int curPos = row * n + col;
//                cout << endl << "curPos: " << curPos << "\trow: " << row << "\tcol: " << col << endl;

                if (grid[row][col] == '1') {
                    // 扫描顺序为从左到右，从上到下，所以不用往上和往左搜索
                    if (col + 1 < n && grid[row][col + 1] == '1') {
                        uf.unionConn(curPos, curPos + 1);
                    }

                    if (row + 1 < m && grid[row + 1][col] == '1') {
                        uf.unionConn(curPos, curPos + n);
                    }
                }
            }
        }

        return uf.getCount();
    }
};
