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
    void removeFirst()
    {
        if (head == NULL)
        {
            cout << "can't remove bacuase Linked List is empty " << endl;
        }
        else if (head->next == NULL)
        {
            delete head;
            tail = head = NULL;
        }
        else
        {
            Node<T> *current = new Node<T>;
            current = head;
            head = head->next;
            delete current;
        }
        size--;
    }
    void removeLast()
    {
        if (head == NULL)
        {
            cout << "can't remove bacuase Linked List is empty " << endl;
        }
        else if (head->next == NULL)
        {
            delete head;
            tail = head = NULL;
        }
        else
        {
            Node<T> *current = new Node<T>;
            Node<T> *temp = new Node<T>;
            current = head->next;
            temp = head;
            while (current->next != NULL)
            {
                temp = current;
                current = current->next;
            }
            delete current;
            temp->next = NULL;
            tail = temp;
        }
        size--;
    }
    void removeAtPosition(int index)
    {
        if (index <= size)
        {
            if (index == 0)
            {
                removeFirst();
            }
            else if (index == size - 1)
            {
                removeLast();
            }
            else
            {
                Node<T> *current = new Node<T>;
                Node<T> *prev = new Node<T>;
                current = head->next;
                prev = head;
                for (int i = 1; i < size - 1; i++)
                {
                    if (i == index)
                    {
                        prev->next = current->next;
                        delete current;
                        size--;
                        return;
                    }
                    prev = current;
                    current = current->next;
                }
            }
            size--;
        }
        else
        {
            cout << "invalid Index" << endl;
        }
    }
    void reverse()
    {
        Node<T> *prev, *current, *after = new Node<T>;
        prev = NULL;
        current = head;
        after = current->next;
        while (after != NULL)
        {
            after = current->next;
            current->next = prev;
            prev = current;
            current = after;
        }
        head = prev;
    }
    int search(T element)
    {
        Node<T> *current = new Node<T>;
        int index = 0;
        current = head;
        while (current != NULL)
        {
            if (current->data == element)
            {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1;
    }
};

int main()
{
    LinkedList<int> l1;
    l1.insertFirst(5);
    l1.print();
    // l1.removeFirst();
    cout << "-------------" << endl;
    l1.print();
    cout << "-------------" << endl;
    l1.insertFirst(4);
    l1.insertLast(1);
    l1.insertAtPosition(1, 66);
    l1.insertAtPosition(2, 606);
    l1.print();
    cout << l1.search(1) << endl;
    cout << "-------------" << endl;

    l1.reverse();
    // l1.removeAtPosition(2);
    //  l1.removeLast();
    //   l1.removeFirst();
    l1.print();
    cout << l1.search(1) << endl;
    return 0;
}
