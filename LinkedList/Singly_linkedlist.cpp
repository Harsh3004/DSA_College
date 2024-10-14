#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(){
            this->data = -1;
            this->next = NULL;
        }
};

void Deletion(node* &head, node* &tail, int pos,int &cnt){
    node* temp = NULL;
    temp = head;

    // Deletion from beginning
    if(pos == 1){
        // For handling case when only one node in a Linked List
        if(tail == head)
            tail = NULL;
        
        head = head->next;
        delete temp;
    }
    // Deletion from End and InBetween Linked List
    else{
        node* prev = head;
        while (pos > 1)
        {
            prev = temp;
            temp = temp->next;
            pos--;
        }

        prev->next = temp->next;
        // For handling Deletion from end
        if(temp == tail)
            tail = prev;

        delete temp;                
    }
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
                // If linked List is Empty
                if(head == NULL && tail == NULL){
                    node* newNode = new node();
                    cout << "Enter the data for node to be inserted: ";
                    cin >> newNode->data;
                
                    cnt++;
                    head = newNode;
                    tail = newNode;
                }
                else{
                    int pos;
                    cout << "Position of node where you want to insert a node: ";
                    cin >> pos;

                    if(pos <= 0 || pos > cnt+1)
                        cout << "You are trying to insert at Invalid Position" << endl;
                    else{
                        node* newNode = new node();

                        cout << "Enter the data for node to be inserted: ";
                        cin >> newNode->data;

                        // Insertion At End
                        if(pos == cnt+1){
                            tail->next = newNode;
                            tail = newNode;
                        }
                        // Insertion in Beginning
                        else if(pos == 1){
                            newNode->next = head;
                            head = newNode;
                        }
                        // Insertion at particular position
                        else{
                            node* temp = head;
                            int nodeCnt = 1;
                            while (nodeCnt < pos-1)
                            {
                                temp = temp->next;
                                nodeCnt++;
                            }

                            newNode->next = temp->next;
                            temp->next = newNode;
                        }

                        cnt++;
                    }

                }

                break;

            // ----------------------- Deletion -----------------------
            case 2:
                if(head == NULL)
                    cout << "Nothing to delete in a Linked List" << endl;
                else{
                    int choice;

                    cout << "Choose Deletion Method: " << endl << "1. By Postion" << endl << "2. By Value "<<endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice)
                    {
                        // Deletion by position
                        case 1:
                            int pos;
                            cout << "Position of node which you want to delete: ";
                            cin >> pos;
                            if(pos <= 0 || pos > cnt)
                                cout << "Entered position does not exist in the Linked List" << endl;
                            else{
                                Deletion(head,tail,pos,cnt);
                            }
                            break;

                        // Deletion by value
                        case 2:
                        {
                            int value;
                            cout << "Enter the value you want to delete from Linked List: ";
                            cin >> value;
                            
                            // For checking wheater value atleast once found or not
                            bool flag = 0;
    
                            int pos = 1;
                            node* temp = head;

                            while(temp != NULL){
                                if(temp->data == value){
                                    temp = temp->next;
                                    Deletion(head,tail,pos,cnt);
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

                break;

            // ----------------------- Display -----------------------
            case 4:
                if(head == NULL)
                    cout << "Linked List is empty" << endl;
                else{
                    node* temp = head;
                    while(temp != NULL){
                        cout << temp->data << ' ';
                        temp = temp->next;
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