#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;

        node(){
            this->data = -1;
            this->next = NULL;
            this->prev = NULL;
        }
};

// Function to delete node of particular position
void deleteNodeAtPosition(int pos, node* &head, node* &tail, int &cnt){
    node* deleteNode = NULL;
    // Deletion from beginning
    if(pos == 1){
        if(tail == head){
            tail = NULL;
            head = NULL;
            return ;
        }

        deleteNode = head;
        head = head->next;
        head->prev = NULL;
    }
    // Deletion from End
    else if(pos == cnt){
        deleteNode = tail;
        tail = tail->prev;
        tail->next = NULL;
    }
    // Deletion from Inbetween Linked List
    else{
        node* temp = head;
        int nodeCnt = 1;
        while(nodeCnt < pos){
            temp = temp->next;
            nodeCnt++;
        }
        deleteNode = temp;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    delete deleteNode;
    cnt--;
}

int main(){

    // Creation of Head and Tail Pointer
    node* head = NULL;
    node* tail = NULL;

    // For storing number of nodes in Linked List
    int cnt = 0;

    int oper;
    do
    {
        cout << "Now you can perform following operations in the Linked List:" << endl;
        cout << "1. Insertion" << endl << "2. Deletion" << endl << "3. Updation" << endl << "4. Display Linked-List" << endl << "5. Exit" << endl << "Enter the number for performing specific operation: " << endl;

        cin >> oper;

        switch (oper)
        {
            // ----------------------- Insertion -----------------------
            case 1:
                if(head == NULL && tail == NULL){
                    cout << "Enter the data for the node to be inserted: ";
                    node * newNode = new node();
                    cin >> newNode->data;

                    head = newNode;
                    tail = newNode;
                }
                else{
                    int pos;
                    cout << "Enter the position at which you want to insert the node in the linked list: ";
                    cin >> pos;

                    if(pos<=0 || pos > cnt+1)
                        cout << "You are trying to insert node at invalid position" << endl;
                    else{
                        node *newNode = new node();
                        cout << "Enter the data for the node to be inserted: ";
                        cin >> newNode->data;

                        // Insertion at End
                        if(pos == cnt+1){
                            tail->next = newNode;
                            newNode->prev = tail;
                            tail = newNode;
                        }
                        // Insertion at the beginning
                        else if(pos == 1){
                            newNode->next = head;
                            head->prev = newNode;
                            head = newNode;
                        }
                        // Insertion in between Linked List
                        else{
                            node* temp = head;
                            int nodeCnt = 1;
                            while(nodeCnt < pos-1){
                                temp = temp->next;
                                nodeCnt++;
                            }

                            newNode->next = temp->next;
                            temp->next->prev = newNode;
                            temp->next = newNode;
                            newNode->prev = temp;
                        }
                    }
                }
                cnt++;

                break;

            // ----------------------- Deletion -----------------------
            case 2:
                if(head == NULL)
                    cout << "Linked List is empty" << endl;
                else{
                    cout << "Choose Deletion Method: " << endl << "1. By Postion" << endl << "2. By Value "<<endl;
                    cout << "Enter your choice: ";
                    int choice;
                    cin >> choice;
                    int pos;
                    switch (choice)
                    {
                    // Deletion by position 
                    case 1:
                        cout << "Enter the position of node to delete: ";
                        cin >> pos;
                        if(pos <= 0 || pos > cnt)
                            cout << "Node at particular position does not exist" << endl;
                        else
                            deleteNodeAtPosition(pos,head,tail,cnt);

                        break;

                    // Deletion by Value
                    // Note: This code will delete all repeated node of given value from the linked list 
                    case 2:
                    {
                        int value;
                        cout << "Enter the value you want to delete from Linked List: ";
                        cin >> value;
                        
                        // For checking wheater value atleast once found or not
                        bool flag = 0;

                        pos = 1;
                        node* temp = head;
                        while(temp != NULL){
                            if(temp->data == value){
                                temp = temp->next;
                                deleteNodeAtPosition(pos,head,tail,cnt);
                                flag = 1;
                            }
                            else{
                                temp = temp->next;
                                pos++;
                            }
                        }

                        if(flag != 1)
                            cout << "Entered value is not present in a Linked List" << endl;

                        break;
                    }

                    default:
                        cout << "Invalid Choice" << endl;
                        break;
                    }
                }

                break;

            // ----------------------- Updation -----------------------
            case 3:
                if(head == NULL){
                    cout << "Linked List is Empty" << endl;
                    break;
                }

                int choice;

                cout << "Choose Updation Method: " << endl
                     << "1. By Position" << endl
                     << "2. By Value" << endl
                     << "Enter your Choice: ";
                cin >> choice;

                switch (choice)
                {
                // Updation By Position
                case 1:
                    int pos;
                    cout << "Position of node which you want to update: ";
                    cin >> pos;
                    if(pos <= 0 || pos > cnt)
                        cout << "Invalid position!" << endl;
                    else{
                        node* temp = head;
                        while (pos>1)
                        {
                            temp = temp->next;
                            pos--;
                        }
                        cout << "Enter the updated value for the position: ";
                        cin >> temp->data;
                    }
                    break;
                
                // Updation By Value
                case 2:
                {
                    int value;
                    cout << "Enter the value you want to update in Linked List: ";
                    cin >> value;

                    // For checking wheater the value found atleast one or not
                    bool flag = 0;

                    node* temp = head;

                    while (temp != NULL)
                    {
                        if (temp->data == value)
                        {
                            cout << "Enter the updated value for the position: ";
                            cin >> temp->data;
                            flag = 1;
                        }
                        temp = temp->next;
                    }

                    if(flag != 1)
                        cout << "Entered value is not present in the linked list" << endl;

                    break;
                }
                
                default:
                    cout << "Invalid Choice" << endl;
                    break;
                }

                break;
            
            // ----------------------- Display -----------------------
            case 4:
                if(head == NULL)
                    cout << "Linked List is empty" << endl;
                else{
                    cout << "Enter the order of display: " << endl 
                        << "1. Head to Tail" << endl 
                        << "2. Tail to Head" << endl;
                    int choice;
                    cin >> choice;
                    node* temp = (choice == 1) ? head : tail;
                    switch (choice)
                    {
                    case 1:
                        while(temp != NULL){
                            cout << temp->data << ' ';
                            temp = temp->next;
                        }
                        break;
                    case 2:
                        while(temp != NULL){
                            cout << temp->data << ' ';
                            temp = temp->prev;
                        }
                        break;
                    
                    default:
                        cout << "Invalid Choice";
                        break;
                    }
                    
                    cout << endl;
                }
                break;

            // ----------------------- Exit -----------------------
            case 5:
                cout << "Thank You" << endl;
                break;

            default:
                cout << "Invalid Input Try Again.." << endl;
                break;
        }
    } while (oper != 5);
    
    return 0;
}