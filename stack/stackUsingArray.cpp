#include <iostream>
using namespace std;

class stack{
        int *arr;
        int top;
        int size;

    public:
        stack(){
            arr = new int[100];
            top = -1;
            size = 100;
        }

        stack(int n){
            arr = new int[n];
            top = -1;
            size = n;
        }

        bool isEmpty(){
            if(top == -1)
                return 1;
            
            return 0;
        }

        void push(int num){
            if(top == size-1)
                cout << "Stack is already full" << endl;
            else{
                top++;
                arr[top] = num;
            }
        }

        int pop(){
            if(isEmpty()){
                cout << "Stack is Empty" << endl;
                return 0;
            }
            
            int poppedElement = arr[top];
            top--;
            return poppedElement;
        }

        int peek(){
            if(top == -1){
                cout << "Stack is Empty" << endl;
                return 0;
            }
            
            return arr[top];
        }

        void display(){
            if(isEmpty())
                cout << "Stack is Empty" << endl;
            else{
                for (int i = top; i >= 0; i--)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    
    int n;
    cout << "Enter the size of the stack: ";
    cin >> n;

    stack myStack(n);

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
            cout << "Popped Element is: " << myStack.pop() << endl;
            break;

        // -------------------- Peek Element --------------------
        case 3:
            cout << "Peek Element in Stack is: " << myStack.peek() << endl;
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