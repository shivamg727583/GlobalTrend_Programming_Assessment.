#include <iostream>
#include <sstream>
#include <string>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
   
    string serialize(TreeNode* root) {
        ostringstream out;
        serializeHelper(root, out);
        return out.str();
    }

    
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserializeHelper(in);
    }

private:
    void serializeHelper(TreeNode* node, ostringstream& out) {
        if (node == nullptr) {
            out << "# ";
            return;
        }
        out << node->val << " ";
        serializeHelper(node->left, out);
        serializeHelper(node->right, out);
    }

    TreeNode* deserializeHelper(istringstream& in) {
        string val;
        in >> val;
        if (val == "#") {
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(in);
        node->right = deserializeHelper(in);
        return node;
    }
};


void printPreOrder(TreeNode* node) {
    if (node == nullptr) {
        cout << "# ";
        return;
    }
    cout << node->val << " ";
    printPreOrder(node->left);
    printPreOrder(node->right);
}


void deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    Codec ser, deser;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string serializedTree = ser.serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    TreeNode* deserializedTree = deser.deserialize(serializedTree);
    cout << "Deserialized Tree (Pre-Order): ";
    printPreOrder(deserializedTree);
    cout << endl;

   
    deleteTree(root);
    deleteTree(deserializedTree);

    return 0;
}

