#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Inserting node at head of the list
void insertAtHead(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        newNode->next = newNode;
    }

    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void display(Node *&head)
{
    // if list is empty
    if (head == NULL)
    {
        cout << "The list is empty";
        return;
    }

    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main()
{

    Node *head = NULL;
    insertAtHead(head, 12);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 4);
    insertAtHead(head, 9);
    insertAtHead(head, 8);

    display(head);

    return 0;
}