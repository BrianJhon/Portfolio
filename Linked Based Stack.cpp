#include <iostream>

using namespace std;

class Node
{
    public:
        Node* next;
        int data;
};

class List
{
    public:
        void push(int);
        int pop();
        bool isEmpty();
    
    private:
        int count = 0;
        Node* top = NULL;
};

void List::push(int num)
{
    Node* newNode = new Node();
    newNode->data = num;
    newNode->next = top;
    top = newNode;
    cout << top->data << " has been pushed into stack." << endl;
    count++;

}

int List::pop()
{
    Node* temp = top;
    int num;
    count--;
    if(top == NULL)
    {
        cout << "Error stack empty.";
        return 0;
    }
    num = top->data;
    top = temp->next;
    delete temp;
    return num;    
}

bool List::isEmpty()
{
    return(count <= 0);
}

int main()
{
    List myStack;

    myStack.push(3); 
    myStack.push(14);
    myStack.push(100);
    myStack.push(8);
    myStack.push(34);
    myStack.push(64);
    
    while(!myStack.isEmpty())
    {
        cout << myStack.pop() << " has been popped." << endl;
    }
    myStack.pop();

    return 0;
}