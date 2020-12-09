class Solution0684 {
public:
    int findParent(unordered_map<int, int>& parents, int point) {
        if (parents.find(point) == parents.end()) {
            return point;
        }

        return findParent(parents, parents[point]);
    }

    void recordConn(unordered_map<int, int>& parents, int p1, int p2) {
        int p1root = findParent(parents, p1);
        int p2root = findParent(parents, p2);
        if (p1 == p1root) {
            parents[p1] = p2root;
            // cout << p1 << "   parent->  " << p2 << endl;
            return;
        }

        if (p2 == p2root) {
            parents[p2] = p1root;
            // cout << p2 << "   parent->  " << p1 << endl;
            return;
        }

        if (p1root != p2root) {
            parents[p1root] = p2root;
            // cout << p1root << "   parent->  " << p2root << endl;
        }
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        if (n == 0) {
            return {};
        }

        unordered_map<int, int> parents;
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            int p1root = findParent(parents, edges[i][0]);
            int p2root = findParent(parents, edges[i][1]);

            if (p1root == p2root) {
                vector<int> temp = {edges[i][0], edges[i][1]};
                sort(temp.begin(), temp.end());

                // cout << "found: " << temp[0] << "," << temp[1] << endl;

                ans.push_back(temp);
            } else {
                recordConn(parents, edges[i][0], edges[i][1]);
            }


        }

        if (ans.empty()) {
            return {};
        } else {
            return ans.back();
        }
    }
};
