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
