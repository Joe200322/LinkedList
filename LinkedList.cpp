#include <iostream>
using namespace std;
template <typename T>
struct Node
{
    T data;
    Node *next;
};
template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void insertFirst(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }
    void insertLast(T value)
    {
        Node<T> *newNode = new Node<T>;
        newNode->data = value;
        if (head == NULL)
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
        size++;
    }
    void insertAtPosition(int index, T value)
    {
        if (index > size)
        {
            cout << "invalid Index." << endl;
        }
        else if (index == 0)
        {
            insertFirst(value);
        }
        else if (index == size)
        {
            insertLast(value);
        }
        else
        {
            Node<T> *current = new Node<T>;
            Node<T> *newNode = new Node<T>;
            current = head;
            newNode->data = value;
            for (int i = 1; i < index; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        size++;
    }
    void print()
    {
        Node<T> *newNode = new Node<T>;
        newNode = head;
        if (head == NULL)
        {
            cout << "List Is Empty." << endl;
        }
        else
        {
            while (newNode != NULL)
            {
                cout << newNode->data << endl;
                newNode = newNode->next;
            }
        }
    }
};

int main()
{
    LinkedList<int> l1;
    l1.insertFirst(5);
    l1.insertFirst(4);
    l1.insertLast(1);
    l1.insertAtPosition(1, 66);
    l1.insertAtPosition(2, 606);
    l1.print();
    return 0;
}
