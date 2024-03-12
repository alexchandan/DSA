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

Node *buildTree(Node *root)
{
    cout << "Enter the data" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);

    cout << "Enter the left data of the " << data << ": " << endl;
    root->left = buildTree(root->left);
    cout << "Enter the right data of the " << data << ": " << endl;
    root->right = buildTree(root->right);
    return root;
}

void inroderWithRecursive(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inroderWithRecursive(root->left);
    cout << root->data << " ";
    inroderWithRecursive(root->right);
}

void inorderWithoutRecursive(Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    while (curr != nullptr || !s.empty())
    {
        // reach the left most node of the tree
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        // print the data inorder
        cout << curr->data << " ";

        // now check the right node of the curr(root);
        curr = curr->right;
    }
}

int main()
{
    Node *root = nullptr;
    root = buildTree(root);
    // inroderWithRecursive(root);
    inorderWithoutRecursive(root);
    return 0;
}