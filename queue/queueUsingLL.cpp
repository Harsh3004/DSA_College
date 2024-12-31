#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(){
            data = -1;
            next = NULL;
        }
};

class queue : public node{
    node* front;        //Accesss from front
    node* rear;         //Insert from rear

    public:
    queue(){
        front = NULL;
        rear = NULL;
    }

    // For checking wheater queue is empty or not
    bool isEmpty(){
        if(front == NULL && rear == NULL)
            return true;
        
        return false;
    }

    // for fetching front element in the queue
    int peek(){
        if(isEmpty())
            return -1;
        
        return front->data;
    }

    // Insert an element in the queue 
    void push(const int &element){
        node* newNode = new node();
        newNode->data = element;

        // If queue is empty
        if(isEmpty()){
            front = newNode;
            rear = newNode;
        }
        // If queue is not empty
        else{
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Pop an element from queue and return it.
    int pop(){
        if(isEmpty())
            return -1;
        
        node* temp = front;

        // If only one element in queue
        if(front == rear){
            front = NULL;
            rear = NULL;
        }
        else
            front = front->next;
        
        int poppedElement = temp->data;             // Store element for the node to be deleted
        delete temp;
        
        return poppedElement;
    }

    // For displaying all the element in the queue
    void display(){
        if(isEmpty())
            cout << "Queue is Empty";
        else{
            node* temp = front;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
};

int main(){
    
    queue q1;
    cout << "Queue created successfully" << endl;

    int choice;
    do
    {
        cout << "Now you can perform following operation: " << endl
             << "1. Push an Element in Queue" << endl
             << "2. Pop an Element in Queue" << endl
             << "3. Front Element" << endl
             << "4. Display Queue" << endl
             << "5. Exit" << endl
             << "Enter the number for performing specific operation: ";
        
        cin >> choice;

        switch (choice)
        {
        // --------------------- Push ---------------------
        case 1:
            cout << "Enter the element in the queue: ";
            int element;
            cin >> element;
            q1.push(element);
            break;

        // --------------------- Pop ---------------------
        case 2:
        {
            int temp = q1.pop();
            if(temp != -1)
                cout << "Popped Element: " << temp << endl;
            else
                cout << "Queue is Empty" << endl;
            
            break;
        }

        // --------------------- Front Element ---------------------
        case 3:
        {
            int temp = q1.peek();
            if(temp != -1)
                cout << "Front Element: " << temp << endl;
            else
                cout << "Queue is Empty" << endl;
            
            break;
        }

        // --------------------- Display ---------------------
        case 4:
            q1.display();
            break;
        
        case 5:
            cout << "Thank You" << endl;
            break;

        // --------------------- Invalid Input ---------------------
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}