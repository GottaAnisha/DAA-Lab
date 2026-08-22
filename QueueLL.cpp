#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << value << " inserted into queue." << endl;
}

void dequeue()
{
    if (front == NULL)
    {
        cout << "Queue Underflow!" << endl;
        return;
    }

    Node* temp = front;

    cout << front->data << " deleted from queue." << endl;

    front = front->next;

    if (front == NULL)
    {
        rear = NULL;
    }

    delete temp;
}

void peek()
{
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
    }
    else
    {
        cout << "Front element: " << front->data << endl;
    }
}

void display()
{
    if (front == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Node* temp = front;

    cout << "Queue elements: ";

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n--- QUEUE MENU ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            enqueue(value);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}