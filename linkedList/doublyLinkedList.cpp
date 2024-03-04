#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Insert New node at head position..
void insertAtHead(int data, Node *&head)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

// Insert new node at at Tail position..
void insertAtEnd(int data, Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert new node at at particular position..
void insertAtPos(int data, int pos, Node *&head)
{
    // if position is on start
    if (pos == 1)
    {
        insertAtHead(data, head);
        return;
    }
    Node *temp = head;
    int currPos = 1;
    while (currPos < pos - 1)
    {
        temp = temp->next;
        currPos++;
    }
    Node *newNode = new Node(data);

    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

// Printing the linked list..
void printList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    Node *node = new Node(10);
    Node *head = node;
    insertAtHead(13, head);
    insertAtHead(14, head);
    insertAtHead(15, head);
    insertAtEnd(34, head);
    insertAtEnd(89, head);
    insertAtPos(23, 3, head);
    insertAtPos(43, 1, head);
    // Displaying the lists
    printList(head);
    return 0;
}