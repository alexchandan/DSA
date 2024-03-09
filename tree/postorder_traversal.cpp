#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// creating a binary tree;
Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }
    root = new Node(data);

    cout << "Enter the data left of " << data << ": " << endl;
    root->left = buildTree(root->left);
    cout << "Enter the data right of " << data << ": " << endl;
    root->right = buildTree(root->right);
    return root;
}

void postorderRecursive(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    cout << root->data << " ";
}

void postorderNonRecursive(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    Node *lastVisited = nullptr;

    while (curr != nullptr || !s.empty())
    {
        // visit the leftmost node and push all left nodes.
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }

        // check if right node to be visited;
        Node *topNode = s.top();
        if (topNode->right != nullptr && topNode->right != lastVisited)
        {
            curr = topNode->right;
        }
        else
        {
            cout << topNode->data << " ";
            s.pop();
            lastVisited = topNode;
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    // postorderRecursive(root);
    postorderNonRecursive(root);
    return 0;
}