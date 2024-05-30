#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void BFS (TreeNode *root_node, vector<TreeNode *> *tree_vals) {
    queue<TreeNode *> traverse_nodes;
    traverse_nodes.push(root_node);

    while (!traverse_nodes.empty()) {
        TreeNode *curr_node = traverse_nodes.front();
        traverse_nodes.pop();

        tree_vals->push_back(curr_node);

        if (curr_node == nullptr) {
            continue;
        }

        traverse_nodes.push(curr_node->left);
        traverse_nodes.push(curr_node->right);
    }
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    } else if (p == nullptr | q == nullptr) {
        return false;
    }

    vector<TreeNode *> p_nodes;
    BFS(p, &p_nodes);

    vector<TreeNode *> q_nodes;
    BFS(q, &q_nodes);

    if (p_nodes.size() != q_nodes.size()) {
        return false;
    }

    for (int i=0; i<p_nodes.size(); i++) {
        if (p_nodes.at(i) == nullptr ^ q_nodes.at(i) == nullptr) {
            return false;
        } else if (p_nodes.at(i) == nullptr && q_nodes.at(i) == nullptr) {
            continue;
        }

        if (p_nodes.at(i)->val != q_nodes.at(i)->val) {
            return false;
        }
    }

    return true;
}

int main (){
    TreeNode minus_one(-1);
    TreeNode minus_five(-5);
    minus_five.left = &minus_one;
    TreeNode eight_p(8, nullptr, &minus_five);

    TreeNode minus_nine(-9);
    TreeNode minus_six(-6);
    minus_six.right = &minus_nine;
    TreeNode eight_q(1, &minus_six, nullptr);

    cout << isSameTree(&eight_p, &eight_q) << "\n";

    return 0;
}