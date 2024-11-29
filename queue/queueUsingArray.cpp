#include <iostream>
using namespace std;

class queue{
    int n;
    int *arr;
    int front;      //Access in Queue using front
    int rear;       //Push element from rear

    public:

    queue(int size){
        n = size;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return (front == -1 && rear == -1);
    }

    bool isFull(){
        return (rear == n-1);
    }

    void push(int element){
        if(isFull())
            cout << "Queue is full" << endl;
        else{
            if(isEmpty()){
                front++;
                arr[++rear] = element;
            }
            else
                arr[++rear] = element;
        }
    }

    int pop(){
        if(isEmpty())
            return -1;
        
        int temp = arr[front++];
        if(front > rear){
            front = -1;
            rear = -1;
        }

        return temp; 
    }

    int peek(){
        if(isEmpty())
            return -1;
        
        return arr[front];
    }

    void display(){
        if(isEmpty())
            cout << "Queue is Empty" << endl;
        else{
            for(int i = front; i<=rear; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main(){

    int sizeOper;
    cout << "For Creating Queue of Specific Size enter 1: ";
    cin >> sizeOper;

    int n;
    if(sizeOper){
        cout << "Enter the size of the queue: ";
        cin >> n;
    }
    else
        n = 100;
    
    queue q(n);
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
            int element;
            cout << "Enter the element in the queue: ";
            cin >> element;
            q.push(element);
            break;

        // --------------------- Pop ---------------------
        case 2:
        {
            int temp = q.pop();
            if(temp != -1)
                cout << "Popped Element: " << temp << endl;
            else
                cout << "Queue is Empty" << endl;
            
            break;
        }

        // --------------------- Front Element ---------------------
        case 3:
        {
            int temp = q.peek();
            if(temp != -1)
                cout << "Front Element: " << temp << endl;
            else
                cout << "Queue is Empty" << endl;
            
            break;
        }

        // --------------------- Display ---------------------
        case 4:
            q.display();
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