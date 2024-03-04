#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Class constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// callback function for node insertion if List is empty.

void insert(Node *&head, int data)
{
    Node *newNode = new Node(data);
    head = newNode;
    newNode->next = newNode;
}

// Insert node at head/start.
void insertAtHead(Node *&head, int data)
{
    // if list is empty
    if (head == NULL)
    {
        insert(head, data);
        return;
    }
    Node *newNode = new Node(data);

    Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

// Insert Node at tail/end.
void insertAtEnd(Node *&head, int data)
{
    Node *temp = head;
    Node *newNode = new Node(data);
    // If list is empty;
    if (head == NULL)
    {
        insert(head, data);
    }

    // If list is not empty
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Insert node at a particular position
void insertAtPos(Node *&head, int data, int pos)
{
    Node *temp = head;

    // inserting if position is 1
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }

    // calculate length of the list..
    Node *temp2 = head;
    int len = 1;
    while (temp2->next != head)
    {
        len++;
        temp2 = temp2->next;
    }

    // check if position is beyond the list length
    if (pos > len + 1 || pos < 1)
    {
        cout << "You are beyond the position: " << pos << " Please insert within length: " << len << endl;
        return;
    }

    // if node is inserting at the end posiition
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
    newNode->next = temp->next;
    temp->next = newNode;
}

// Print the circular list
void printList(Node *&head)
{
    if (head == NULL)
    {
        cout << "The list is empty." << endl;
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

    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 9);
    insertAtHead(head, 5);

    // Insert at end;
    insertAtEnd(head, 45);
    insertAtEnd(head, 8);

    // InsertAtposition
    insertAtPos(head, 12, 2);
    // printList(head);
    insertAtPos(head, 54, 7);
    insertAtPos(head, 43, 8);

    // print list
    printList(head);
    return 0;
}