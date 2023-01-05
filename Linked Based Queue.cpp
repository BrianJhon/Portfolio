#include <iostream>

using namespace std;

class Node
{
    public:
        Node* next;
        int data;
};

class Queue
{
    public:
        Node* Enqueue(int, Node*);
        Node* newNode(int);
        int Dequeue();
        bool isEmpty();

    
    private:
        Node* front;
        Node* back;
        int count = 0;
};

Node* Queue::newNode(int num)
{
    Node* temp = new Node();
    temp -> data = num;
    temp -> next = NULL;
    count++;
    return temp;
}

Node* Queue::Enqueue(int num, Node* ref)
{
    if(ref == NULL)
    {
        back = newNode(num);
        cout << back -> data << " has entered queue." << endl;
        return back;
    }
    ref -> next = Enqueue(num, ref -> next);
    front = ref;
    return ref;
}

int Queue::Dequeue()
{
    count--;
    Node* temp = front;
    int num;
    if(front == NULL)
    {
        cout << "Queue is empty ";
        return 0;
    }
    num = front -> data;
    front = temp -> next;
    return num;
}

bool Queue::isEmpty()
{
    return(count <= 0);
}

int main()
{
    Queue myQueue;
    Node* queue = NULL;

    queue = myQueue.Enqueue(6,queue);
    queue = myQueue.Enqueue(45,queue);
    queue = myQueue.Enqueue(11,queue);

    while(!myQueue.isEmpty())
    {
        cout << myQueue.Dequeue() << " has left queue." << endl;
    }
    cout <<  myQueue.Dequeue();
    return 0;
}