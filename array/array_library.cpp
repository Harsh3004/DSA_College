#include <iostream>
using namespace std;

// Function for taking input in an Array
int TakeInput(int *arr, int n){
    cout << "Enter the elements you want to insert" << endl;
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    return n;
}

// Function for insertion of element at particular index
void InsertAtIndex(int *arr , int element ,int index , int size){
    for(int i = size ; i > index ; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = element;
}

// Function for deletion of element at particular index
void DeleteAtIndex(int *arr, int deleteIndex , int elementCnt){
     for(int i = deleteIndex; i < elementCnt-1 ; i++){
        arr[i] = arr[i+1];
    }
    
    // For Identifying last index after Deletion assigning -1 in it.
    arr[elementCnt-1] = -1;
}

// Function for printing all elements in an Array
void printArr(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    int size;
    int elementCnt = 0;

    cout << "Enter the size of the Array you want to Create: ";
    cin >> size;

    int *arr = new int[size];
    cout << "Array of size " << size << " has been created."<<endl;
    
    int oper;
    do
    {
        cout << "Now you can perform following operations:" << endl;
        cout << "1. Insertion" << endl << "2. Deletion" << endl << "3. Updation" << endl << "4. Print All Elements in Array" << endl << "5. Exit" << endl << "Enter the number for performing specific operation: " ;

        cin >> oper;

        switch (oper)
        {
            // ------------------------ Insertion ------------------------
            case 1:
                int n;

                cout << "Enter the number of Elements you want to Insert: ";
                cin >> n;
                if((elementCnt + n) > size)
                    cout << "You are trying to insert more element then array size" << endl;
                else{
                    // If array is empty --> Insert directly
                    if(elementCnt == 0){
                        TakeInput(arr,n);
                        elementCnt = n;
                    }
                    // Else take element and index for insertion at particular index.
                    else{
                        for(int i = 0 ; i < n ; i++){
                            int element, index;
                            cout << "Enter the element you want to insert with their respective index: " << endl;
                            cin >> element >> index;
                            if((index >= size )|| (index < 0))
                                cout << "Index is not in Array's Range" << endl;
                            else{
                                InsertAtIndex(arr,element,index,elementCnt);
                                elementCnt++;
                            }
                        }
                    }
                }
                break;

            // ------------------------ Deletion ------------------------
            case 2:
                if(elementCnt == 0)
                    cout << "Array is empty, Deletion cannot perform " << endl;
                else{
                    cout << "Choose Deletion Method: " << endl << "1. By Index" << endl << "2. By Value "<<endl;
                    cout << "Enter your choice: ";
                    int deleteMethod;
                    cin >> deleteMethod;

                    switch (deleteMethod)
                    {
                        // Deletion By Index
                        case 1:
                            int deleteIndex;
                            cout << "Enter the index which value you want to delete: ";
                            cin >> deleteIndex;

                            if((deleteIndex >= elementCnt) || (deleteIndex < 0))
                                cout << "You are trying to delete from an invalid Index" << endl;
                            else{
                                DeleteAtIndex(arr,deleteIndex,elementCnt);
                                elementCnt--;
                            }

                            break;

                        // Deletion By Value
                        case 2:
                        {
                            int deleteValue;
                            cout << "Enter the value you want to delete from an array: ";
                            cin >> deleteValue;

                            bool flag = 0;
                            for(int i = 0; i < elementCnt; i++){
                                if(arr[i] == deleteValue){
                                    DeleteAtIndex(arr,i,elementCnt);
                                    elementCnt--;

                                    //Decreasing i so that next time loop start from current index since after deletion all values shift to left 
                                    i--;    
                                    flag = 1;
                                }
                            }

                            if(flag == 0)
                                cout << "Value you want to delete is not present in an array." << endl;

                            break;
                        }
                    
                        default:
                            cout << "Invalid Choice" << endl;
                            break;
                    }
                }

                break;

            // ------------------------ Updation ------------------------
            case 3:
                cout << "Choose Updation Method: " << endl
                     << "1. Update value at Index" << endl
                     << "2. Update Value" << endl;
                cout << "Enter your Choice: ";

                int updateMethod;
                cin >> updateMethod;

                switch (updateMethod)
                {
                case 1:
                    int updateIndex;
                    cout << "Enter the Index at which you want to update value: ";
                    cin >> updateIndex;

                    if(updateIndex < 0 ||updateIndex >= elementCnt)
                        cout << "You want to update Invalid Index" << endl;
                    else{
                        int value;
                        cout << "Enter the value to update: ";
                        cin >> value;
                        arr[updateIndex] = value;
                    }

                    break;
                
                default:
                    cout <<"Invalid Choice" << endl;
                    break;
                }

                break;

            // ------------------------ Display Array ------------------------
            case 4:
                if(elementCnt == 0)
                    cout << "Array is Empty" << endl;
                else{
                    printArr(arr,elementCnt);
                }
                break;
            
            // ------------------------ Exit ------------------------
            default:
                if(oper != 5)
                    cout << "Invalid Choice" << endl;
                break;
        }
    } while (oper != 5);
    

    return 0;
}