#include<bits/stdc++.h>
#include "carl/binaryTree.h"

using namespace std;

// 层序遍历输出二叉树
void printTree(TreeNode *root) {
    if (!root) {
        cout << "Empty tree" << endl;
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();

        // 输出当前层的节点
        for (int i = 0; i < levelSize; ++i) {
            TreeNode *node = q.front();
            q.pop();

            if (node) {
                cout << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << "null ";
            }
        }
        cout << endl; // 换行表示新的一层
    }
}

int main() {

    BinaryTree BTree;

    vector<int> vec = {-10, -3, 0, 5, 9};

    TreeNode *root = BTree.sortedArrayToBST(vec);

    printTree(root);

}