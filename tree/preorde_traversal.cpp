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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in the left of " << data << ": " << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in the right of " << data << ": " << endl;
    root->right = buildTree(root->right);

    return root;
}

// preorder traversal with recursion

void preorderWithRecursion(Node *&root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        cout << root->data << " ";
        preorderWithRecursion(root->left);
        preorderWithRecursion(root->right);
    }
}

// preorder traversal without recurion using stack;
void preorderWithoutRecursion(Node *&root)
{
    if (root == nullptr)
    {
        cout << "the tree is empty" << endl;
        return;
    }
    else
    {
        stack<Node *> s;
        s.push(root);

        while (!s.empty())
        {
            Node *curr = s.top();
            s.pop();

            // print the top element of the stack
            cout << curr->data << " ";

            if (curr->right)
            {
                s.push(curr->right);
            }

            // push curr left in the end to take it on the top on the stack.
            if (curr->left)
            {
                s.push(curr->left);
            }
        }
    }
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    preorderWithRecursion(root);
    // cout << endl;
    // preorderWithoutRecursion(root);
    return 0;
}
