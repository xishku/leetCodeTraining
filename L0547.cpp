class Solution0547 {
public:
    int findFather(vector<int>& father, int p) {

        if (father[p] == -1) {
            return p;
        }

        int f = findFather(father, father[p]);

        return f;
    }


    void unionCircle(vector<int>& father, int p1, int p2) {
        // cout << "unionCircle: " << p1 << "\t" << p2 << endl;
        int p1f = findFather(father, p1);
        // cout << "findFather\t " << p1 << " -> " << p1f  << endl;
        int p2f = findFather(father, p2);
        // cout << "findFather\t " << p2 << " -> " << p2f  << endl;
        if (p1f != p2f) {
            // cout << "set " << p1f << " father to " << p2f << endl;
            father[p1f] = p2f;
        } else {
            // cout << "do nothing" << endl;
        }

    }

    int findCircleNum(vector<vector<int>>& M) {
        int m = M.size();
        if (m == 0) {
            return 0;
        }

        vector<int> father(m, -1);
        for (int i = 0; i < M.size(); ++i) {
            for (int j = 0; j < M[0].size(); ++j) {
                if (M[i][j] == 1 && i != j ) {
                    unionCircle(father, i, j);
                }
            }
        }

        int ans = 0;
        for (auto el: father) {
            // cout << el << "\t";
            if (el == -1) {
                ++ans;
            }
        }
        // cout << endl;
        return ans;
    }
};
