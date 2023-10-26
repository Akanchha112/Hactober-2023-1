#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "#,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }

    // Decodes your encoded data to a tree.
    TreeNode* deserialize(string data) {
        if (data == "#,") return nullptr;
        stringstream s(data);
        return helper(s);
    }

    TreeNode* helper(stringstream &s) {
        string str;
        getline(s, str, ',');
        if (str == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(str));
        root->left = helper(s);
        root->right = helper(s);
        return root;
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec codec;
    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    TreeNode* deserialized = codec.deserialize(serialized);
    cout << "Deserialized tree: " << codec.serialize(deserialized) << endl;

    // Remember to free memory (e.g., using a function to delete the tree nodes) to avoid memory leaks.
    return 0;
}
