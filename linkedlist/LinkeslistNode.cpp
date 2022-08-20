#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

Node insertNodeingivenInput(Node *head, int element, int position)
{
    Node *temp = head;
    Node *newnode = new Node(element);
    int i = 1;
    if (position==1)
    {
        head=newnode;
        return head;
    }
    
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

void Print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

Node *TakeInput()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

int main()
{

    Node *head = TakeInput();
    //     //statically created a node
    //    Node n1(2);
    //    Node *head=&n1;
    //    Node n2(3);
    //    n1.next=&n2;

    //    // dynamically created a node;
    //    Node *n3 = new Node(4);
    //    n2.next=n3;
    //    Node *n4 = new Node(5);
    //    n3->next = n4;

   head=insertNodeingivenInput(head,7,3);

    Print(head);

    return 0;
}