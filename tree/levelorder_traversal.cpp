#include <iostream>
#include <queue>
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

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    if (data == -1)
    {
        return nullptr;
    }
    root = new Node(data);

    cout << "Enter to insert in the left of " << data << ": " << endl;
    root->left = buildTree(root->left);
    cout << "Enter to insert in the right of " << data << ": " << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelorderNonRecursive(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        cout << curr->data << " ";
        q.pop();
        if (curr->left != nullptr)
        {
            q.push(curr->left);
        }
        if (curr->right != nullptr)
        {
            q.push(curr->right);
        }
    }
}

int main()
{
    Node *root = nullptr;
    root = buildTree(root);
    levelorderNonRecursive(root);
    return 0;
}