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

// insert new node if the list is empty.
void insert(Node *&head, int data)
{
    Node *newNode = new Node(data);
    head = newNode;
    newNode->next = newNode;
    newNode->prev = newNode;
}

// insert node at head pointer
void insertAtHead(Node *&head, int data)
{
    if (head == NULL)
    {
        insert(head, data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = head;
    newNode->prev = head->prev;
    head->prev->next = newNode;
    head->prev = newNode;
    head = newNode;
}

// insert node at end pointer
void insertAtEnd(Node *&head, int data)
{
    Node *newNode = new Node(data);
    newNode->prev = head->prev;
    newNode->prev->next = newNode;
    head->prev = newNode;
    newNode->next = head;
}

// insert at a particular position
void insertAtPos(Node *&head, int pos, int data)
{
    Node *temp = head;
    Node *temp2 = head;

    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }

    // calculate the length of.
    int len = 1;
    while (temp2->next != head)
    {
        len++;
        temp2 = temp2->next;
    }
    // check if position is beyond the list
    if (pos > len + 1 || pos < 1)
    {
        cout << "You cannot insert the Node at position " << pos << " please insert the node between 1 to " << len + 1 << endl;
        return;
    }

    // is Node insert at end of the list
    if (pos == len + 1)
    {
        insertAtEnd(head, data);
        return;
    }

    int curr = 1;
    while (curr < pos - 1)
    {
        temp = temp->next;
        curr++;
    }
    Node *newNode = new Node(data);
    temp->next->prev = newNode;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node *&head)
{
    if (head == NULL)
    {
        cout << "The list is empty" << endl;
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
    insertAtHead(head, 13);
    insertAtHead(head, 14);
    insertAtHead(head, 21);

    // insert at end/tail
    insertAtEnd(head, 61);
    insertAtEnd(head, 62);
    insertAtEnd(head, 63);

    // insert at a particular position
    // head,position,data
    insertAtPos(head, 2, 11);
    insertAtPos(head, 1, 24);
    insertAtPos(head, 4, 5);
    insertAtPos(head, 11, 31);
    // insertAtPos(head, 13, 67);
    // insertAtPos(head, -1, 23);

    // print list
    // cout << "list before reverse.";
    printList(head);
    return 0;
}