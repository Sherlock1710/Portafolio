#include<iostream>
using namespace std;

// Structs
struct Stack{
    int n;
    Stack* nxt;
};

struct Queue{
    int n;
    Queue* nxt;
};

// Stack Functions
void addStack(Stack* &top, int n){
    Stack* New = new Stack;
    New->n = n;
    New->nxt = top;
    top = New;
}

void deleteStack(Stack* &top){
    if (top) {
        Stack* aux = top;
        top = aux->nxt;
        delete aux;
    }
}

// Queue Functions
void addQueue(Queue* &front, Queue* &rear, int n){
    Queue* New = new Queue;
    New->n = n;
    New->nxt = NULL;
    
    if(rear==NULL){
        front = New;
        rear = New;
    }else{
        rear->nxt = New;
        rear = New;    
    }
}

void deleteQueue(Queue* &front){
    if (front) {
        Queue* aux = front;
        front = aux->nxt;
        delete aux;
    }
}

//Pass Functions
void pass1(Stack* &top, Queue* &front, Queue* &rear){
    int n = top->n;
    deleteStack(top);
    addQueue(front, rear, n);
    cout<<"The number "<<n<<" was deleted from stack and added to the queue. \n";
}

void pass2(Stack* &top, Queue* &front){
    int n = front->n;
    deleteQueue(front);
    addStack(top, n);
    cout<<"The number "<<n<<" was deleted from queue and added to the stack. \n";
}

// Modify Functions
void mod1(Stack* &top){
    while (top && top->n % 2 == 0) {
        cout << "Value: " << top->n << endl;
        deleteStack(top);
    }
}

void mod2(Queue* &front){
    while (front && front->n % 2 != 0) {
        cout << "Value: " << front->n << endl;
        deleteQueue(front);
    }
}

void mod3(Stack* &top,Queue* &front, Queue* &rear, int n){
    if(n % 2 == 0){
        if(front && front->nxt){
            n = front->n;
            deleteQueue(front);
            int n2 = front->n;
            deleteQueue(front);
            cout<<"The value of the deleted nodes are: "<<n<<", "<<n2<<endl;
        } else {
            cout<<"Not enough nodes in the queue to delete.\n";
        }
    }else{
        addQueue(front, rear, n);
        cout<<"Number "<<n<<" added to queue \n";
    }
}

void mod4(Stack* &top, int n){
    if(n % 2 == 0){
        if(top && top->nxt){
            n = top->n;
            deleteStack(top);
            int n2 = top->n;
            deleteStack(top);
            cout<<"The value of the deleted nodes are: "<<n<<", "<<n2<<endl;
        } else {
            cout<<"Not enough nodes in the stack to delete.\n";
        }
    }else{
        addStack(top, n);
        cout<<"Number "<<n<<" added to stack \n";
    }
}

void mod5(Stack* &top){
    if(top && top->nxt){
        int n = top->n;
        deleteStack(top);
        int n2 = top->n;
        deleteStack(top);
        cout<<"The value of the deleted nodes are: "<<n<<", "<<n2<<endl;
        cout<<"The sum of the values is: "<<n+n2<<endl;
    } else {
        cout<<"Not enough nodes in the stack to delete.\n";
    }
}

void mod6(Queue* &front){
    if(front && front->nxt){
        int n = front->n;
        deleteQueue(front);
        int n2 = front->n;
        deleteQueue(front);
        cout<<"The value of the deleted nodes are: "<<n<<", "<<n2<<endl;
        cout<<"The sum of the values is: "<<n+n2<<endl;
    } else {
        cout<<"Not enough nodes in the queue to delete.\n";
    }
}

// Search Functions
void search1(Queue* front, int n){
    bool found = false;
    while (front) {
        if (front->n == n) {
            cout << "The searched number is in the queue. \n";
            found = true;
            break;
        }
        front = front->nxt;
    }
    if (!found) {
        cout << "The number is not in the queue. \n";
    }
}

void search2(Stack* top, int n){
    bool found = false;
    while (top) {
        if (top->n == n) {
            cout << "The searched number is in the stack. \n";
            found = true;
            break;
        }
        top = top->nxt;
    }
    if (!found) {
        cout << "The number is not in the stack. \n";
    }
}

// MAIN THREAD
int main(){
    Stack* top = NULL;
    Queue* front = NULL;
    Queue* rear = NULL;
    
    int op, n, n2;
    bool cond = true;
    
    while(cond){
        cout<<"====================MENU====================\n";
        cout<<"1. Add to stack \n";
        cout<<"2. Delete from stack \n";
        cout<<"3. Add to queue \n";
        cout<<"4. Delete from queue \n";
        cout<<"5. Show top (stack)\n";
        cout<<"6. Show front and rear (queue) \n";
        cout<<"7. Pass node (from stack to queue) \n";
        cout<<"8. Pass node (from queue to stack)\n";
        cout<<"9. Modify 1 \n";
        cout<<"10. Modify 2 \n";
        cout<<"11. Modify 3\n";
        cout<<"12. Modify 4 \n";
        cout<<"13. Modify 5 \n";
        cout<<"14. Modify 6 \n";
        cout<<"15. Search 1 \n";
        cout<<"16. Search 2 \n";
        cout<<"0. Exit \n";
        cout<<"Choose an option: \n";
        cin>>op;
        
        switch(op){
            //Add a node to stack
            case 1:
                cout<<"Type a number to add to the stack: \n";
                cin>>n;
                addStack(top, n);
            break;
            //Delete a node from stack
            case 2:
                if(!top){
                    cout<<"The stack is empty. Add a node and try again. \n";
                }else{
                    n = top->n;
                    deleteStack(top);
                    cout<<"The value of the deleted node is: "<<n<<endl;
                }
            break;
            //Add a node to queue
            case 3:
                cout<<"Type a number to add to the queue: \n";
                cin>>n;
                addQueue(front, rear, n);
            break;
            //Delete a node from the queue
            case 4:
                if(!front){
                    cout<<"The queue is empty. Add a node and try again. \n";
                }else{
                    n = front->n;
                    deleteQueue(front);
                    cout<<"The value of the deleted node is: "<<n<<endl;
                }
            break;
            //Show stack's top
            case 5:
                if(!top){
                    cout<<"The stack is empty. Add a node and try again. \n";
                }else{
                    cout<<"The number in the top is: "<<top->n<<endl;
                }
            break;
            //Show queue's front and rear
            case

 6:
                if(!front){
                    cout<<"The queue is empty. Add a node and try again. \n";
                }else{
                    cout<<"The number in the front is: "<<front->n<<endl;
                    cout<<"The number in the rear is: "<<rear->n<<endl; 
                }
            break;
            //Pass 1 (delete a node from stack and add it to queue)
            case 7:
                if(!top){
                    cout<<"The stack is empty. Add a node and try again. \n";
                }else{
                    pass1(top, front, rear);
                }
            break;
            //Pass 2 (delete a node from queue and add it to stack)
            case 8:
                if(!front){
                    cout<<"The queue is empty. Add a node and try again. \n";
                }else{
                    pass2(top, front); 
                }
            break;
            //Modify 1 (delete nodes from stack until the node value it's an uneven number)
            case 9:
                if(!top){
                    cout<<"The stack is empty. Add a node and try again. \n";
                }else{
                    cout<<"------------------Deleted values from stack------------------ \n";
                    mod1(top);
                }
            break;
            //Modify 2 (delete nodes from queue until the node value it's an even number)
            case 10:
                if(!front){
                    cout<<"The queue is empty. Add a node and try again. \n";
                }else{
                    cout<<"------------------Deleted values from queue------------------ \n";
                    mod2(front);
                }
            break;
            //Modify 3 
            case 11:
                if(front && front->nxt){
                    cout<<"Type a number: \n";
                    cin>>n;
                    mod3(top, front, rear,n);
                }else{
                    cout<<"This function needs at least 2 nodes. Add more nodes and try again. \n";
                }
            break;
            //Modify 4
            case 12:
                if(top && top->nxt){
                    cout<<"Type a number: \n";
                    cin>>n;
                    mod4(top, n);
                }else{
                    cout<<"This function needs at least 2 nodes. Add more nodes and try again. \n";
                }
            break;
            //Modify 5
            case 13:
                if(top && top->nxt){
                    mod5(top);
                }else{
                    cout<<"This function needs at least 2 nodes. Add more nodes and try again. \n";
                }
            break;
            //Modify 6
            case 14:
                if(front && front->nxt){
                        mod6(front);
                }else{
                    cout<<"This function needs at least 2 nodes. Add more nodes and try again. \n";
                }
            break;
            
            //Search 1
            case 15:
                if(front){
                    cout<<"Type a number to search in the queue: \n";
                    cin>>n;
                    search1(front, n);
                }else{
                    cout<<"The queue is empty. Add a node and try again. \n";
                }
            break;
            
            //Search 2
            case 16:
                if(top){
                    cout<<"Type a number to search in the stack: \n";
                    cin>>n;
                    search2(top, n);
                }else{
                    cout<<"The stack is empty. Add a node and try again. \n";
                }
            break;
            case 0: 
                cout<<"Shutting down program... \n";
                cond=false;
            break;
            
            default:
                cout<<"Error: option doesn't exist, try again. \n";
            break;
        }
    }
    return 0;
}

