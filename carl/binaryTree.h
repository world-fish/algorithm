#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTree {
public:
    // 102. 二叉树的层序遍历
    vector<vector<int>> levelOrder(TreeNode *root) {
        queue<TreeNode *> qu;
        vector<vector<int>> vec;
        if (root == nullptr) {
            return {};
        }
        qu.push(root);
        while (!qu.empty()) {
            vector<int> v;
            int count = qu.size();
            for (int i = 0; i < count; ++i) {
                if (qu.front() == nullptr) {
                    qu.pop();
                    continue;
                }
                v.push_back(qu.front()->val);
                qu.push(qu.front()->left);
                qu.push(qu.front()->right);
                qu.pop();
            }
            if (!v.empty()) {
                vec.push_back(v);
            }
        }
        return vec;
    }

    // 226. 翻转二叉树
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    // 101. 对称二叉树
    bool isSymmetric(TreeNode *root) {
        return root == nullptr || recur(root->left, root->right);
    }

    bool recur(TreeNode *l, TreeNode *r) {
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr || r == nullptr || l->val != r->val) {
            return false;
        }
        return recur(l->left, r->right) &&
               recur(l->right, r->left);
    }

    // 104. 二叉树的最大深度
    stack<int> stack1;
    int m3 = 0;

    int maxDepth(TreeNode *root) {
        if (root != nullptr) {
            stack1.push(root->val);
            m3 = maxDepth(root->left);
            m3 = maxDepth(root->right);
            stack1.pop();
        }
        return max(m3, int(stack1.size()));
    }

    // 222. 完全二叉树的节点个数
    int countLevels(TreeNode *root) { // 查看树最左边的层数
        int levels = 0;
        while (root) {
            root = root->left;
            levels += 1;
        }
        return levels;
    }

    int countNodes(TreeNode *root) {
        if (root == nullptr) return 0;
        // 查看左右子树的层级
        int left_levels = countLevels(root->left);
        int right_levels = countLevels(root->right);
        // 判断最底层的情况 根据情况返回节点个数
        if (left_levels == right_levels) {
            return countNodes(root->right) + (1 << left_levels);
        } else {
            return countNodes(root->left) + (1 << right_levels);
        }
    }

    // 110. 平衡二叉树
    bool isBalanced(TreeNode *root) {
        return recur(root) != -1;
    }

    int recur(TreeNode *root) { // 获取节点高度 对比左右节点高度差
        if (root == nullptr) {
            return 0;
        }
        int left = recur(root->left);
        if (left == -1) return -1;
        int right = recur(root->right);
        if (right == -1) return -1;
        return abs(left - right) > 1 ? -1 : max(left, right) + 1;
    }

    // 257. 二叉树的所有路径
    vector<int> stack2;
    vector<string> vec1;

    vector<string> binaryTreePaths(TreeNode *root) {
        recurr(root);
        return vec1;
    }

    void recurr(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        stack2.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            string temp;
            for (int i = 0; i < stack2.size(); ++i) {
                if (i != 0) {
                    temp += "->";
                }
                temp += to_string(stack2[i]);
            }
            vec1.push_back(temp);
        }
        recurr(root->left);
        recurr(root->right);
        stack2.pop_back();
    }

    // 404. 左叶子之和
    int sumOfLeftLeaves(TreeNode *root) {
        if (root == nullptr) return 0;
        int ans = 0;
        if (root->left != nullptr && root->left->left == nullptr && root->left->right == nullptr)
            ans = root->left->val;
        return ans + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }

    // 513. 找树左下角的值
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> queue;
        queue.push(root);
        while (true) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *r = queue.front();
                if (r->right != nullptr) queue.push(r->right);
                if (r->left != nullptr) queue.push(r->left);
                if (queue.size() == 1) return queue.front()->val;
                queue.pop();
            }
        }
    }

    // 112. 路径总和
    int sum1 = 0;

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return false;
        sum1 += root->val;
        if (sum1 == targetSum && root->left == nullptr && root->right == nullptr) return true;
        bool b1 = hasPathSum(root->right, targetSum);
        bool b2 = hasPathSum(root->left, targetSum);
        sum1 -= root->val;
        return b1 || b2;
    }

    // 106. 从中序与后序遍历序列构造二叉树
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {

        return dfs(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *dfs(vector<int> &inorder, vector<int> &postorder, int il, int ir, int pl, int pr) {
        if (il > ir) return nullptr;
        TreeNode *root = new TreeNode(postorder[pr]);
        auto it = find(inorder.begin(), inorder.end(), postorder[pr]);
        int k = distance(inorder.begin(), it);

        root->left = dfs(inorder, postorder, il, k - 1, pl, pl + k - 1 - il);
        root->right = dfs(inorder, postorder, k + 1, ir, pr - 1 - ir + k + 1, pr - 1);

        return root;
    }

    // 654. 最大二叉树
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        if (nums.empty()) return nullptr;
        auto max_i = max_element(nums.begin(), nums.end()) - nums.begin();

        TreeNode *root = new TreeNode(nums[max_i]);

        vector<int> n1(nums.begin(), nums.begin() + max_i);
        vector<int> n2(nums.begin() + max_i + 1, nums.end());

        root->left = constructMaximumBinaryTree(n1);
        root->right = constructMaximumBinaryTree(n2);
        return root;
    }

    // 617. 合并二叉树
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        TreeNode *root = new TreeNode(root1->val + root2->val);
        root->left = mergeTrees(root1->left, root2->left);
        root->right = mergeTrees(root1->right, root2->right);
        return root;
    }

    // 700. 二叉搜索树中的搜索
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr) return NULL;
        if (root->val == val) return root;
        else if (val > root->val) return searchBST(root->right, val);
        else return searchBST(root->left, val);
    }

    // 98. 验证二叉搜索树
    bool isValidBST(TreeNode *root, ll left = LLONG_MIN, ll right = LLONG_MAX) {
        if (root == nullptr) {
            return true;
        }
        ll x = root->val;
        return left < x && x < right &&
               isValidBST(root->left, left, x) &&
               isValidBST(root->right, x, right);
    }

    // 530. 二叉搜索树的最小绝对差
    vector<int> vec2;

    void traversal(TreeNode *root) {
        if (root == NULL) return;
        traversal(root->left);
        vec2.push_back(root->val); // 将二叉搜索树转换为有序数组
        traversal(root->right);
    }

    int getMinimumDifference(TreeNode *root) {
        traversal(root);
        if (vec2.size() < 2) return 0;
        int m = INT_MAX;
        for (int i = 1; i < vec1.size(); ++i) {
            m = min(m, vec2[i] - vec2[i - 1]);
        }
        return m;
    }

    // 501. 二叉搜索树中的众数
    int maxCount = 0;
    int count = 0;
    TreeNode *pre = nullptr;
    vector<int> result;

    void searchBST(TreeNode *cur) {
        if (cur == nullptr) return;
        searchBST(cur->left);

        if (pre == nullptr) {
            count = 1;
        } else if (pre->val == cur->val) {
            count++;
        } else {
            count = 1;
        }

        pre = cur;

        if (count == maxCount) result.push_back(cur->val);
        else if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }

        searchBST(cur->right);

    }

    vector<int> findMode(TreeNode *root) {
        searchBST(root);
        return result;
    }

    // 236. 二叉树的最近公共祖先
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }

    // 235. 二叉搜索树的最近公共祖先
    TreeNode *lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor2(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor2(root->right, p, q);
        } else return root;
    }

    // 701. 二叉搜索树中的插入操作
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (root == nullptr) return new TreeNode(val);
        if (root->val > val) root->left = insertIntoBST(root->left, val);
        if (root->val < val) root->right = insertIntoBST(root->right, val);
        return root;
    }

    // 450. 删除二叉搜索树中的节点
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (root == nullptr) return root;
        if (root->val == key) {
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;
            TreeNode *node = root->right;
            while (node->left) node = node->left;
            node->left = root->left;
            root = root->right;
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    // 669. 修剪二叉搜索树
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (root == nullptr) return root;
        if (root->val < low) return trimBST(root->right, low, high);
        else if (root->val > high) return trimBST(root->left, low, high);
        else {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        return root;
    }

    // 108. 将有序数组转换为二叉搜索树
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        int size = nums.size();
        if (size == 0) return nullptr;
        size /= 2;
        TreeNode *root = new TreeNode(nums[size]);
        vector<int> l(nums.begin(), nums.begin() + size);
        root->left = sortedArrayToBST(l);
        vector<int> r(nums.begin() + size + 1, nums.end());
        root->right = sortedArrayToBST(r);
        return root;
    }

    // 538. 把二叉搜索树转换为累加树
    int sum = 0;

    TreeNode *convertBST(TreeNode *root) {
        if (root == nullptr) return root;

        convertBST(root->right);

        sum += root->val;
        root->val = sum;

        convertBST(root->left);

        return root;
    }


















//
//
//
//
//
//
//
//
//
//
//


};