#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *next;

        node(){
            this->next = NULL;
        }
};

class stack{
    node *top;

    public:
        stack(){
            top = NULL;
        }

        bool isEmpty(){
            if(top == NULL)
                return 1;
            
            return 0;
        }

        void push(int data){
            node* newNode = new node();
            newNode->data = data;

            if(isEmpty())
                top = newNode;
            else{
                newNode->next = top;
                top = newNode;
            }
            cout << "Element Pushed Successfully" << endl;
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
                return 0;
            }

            node *temp = top;
            int popped = temp->data;
            top = top->next;
            delete temp;

            cout << "Popped Element is: " << popped << endl;
            return popped;
        }

        int peek(){
            if(isEmpty()){
                cout << "Stack is Empty"<< endl;
                return 0;
            }

            cout << "Peek Element in Stack is: " << top->data << endl;
            return top->data;
        }

        void display(){
            if(isEmpty())
                cout << "Stack is Empty" << endl;
            else{
                node* temp = top;
                while (temp != NULL)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }
};

int main(){

    cout << "Stack Program using Linked List" << endl;
    stack myStack;

    int choice;
    do
    {
        cout << "Now you can perform following operations:"<<endl
             << "1. Push an Element in Stack" << endl
             << "2. Pop an Element from stack" << endl
             << "3. Peak Element in Stack" << endl
             << "4. Display stack" << endl
             << "5. Exit" << endl
             << "Enter the number for performing specific operation: ";

        cin >> choice;

        switch (choice)
        {
        // -------------------- Push --------------------
        case 1:
            int element;
            cout << "Enter the element to push in Stack: ";
            cin >> element;
            myStack.push(element);

            break;
        // -------------------- Pop --------------------
        case 2:
            myStack.pop();
            break;

        // -------------------- Peek Element --------------------
        case 3:
            myStack.peek();
            break;
        
        // -------------------- Display --------------------
        case 4:
            myStack.display();
            break;
        
        // -------------------- Exit --------------------
        case 5:
            cout << "Thank You" << endl;
            break;

        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}