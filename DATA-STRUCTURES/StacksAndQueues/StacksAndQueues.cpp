#include<iostream>
using namespace std;

//Structs
struct Stack{
	int n;
	Stack* nxt;
};

struct Queue{
	int n;
	Queue* nxt;
};

//Stack Functions

void addStack(Stack* &top, int n){
	Stack* New = new Stack;
	New->n = n;

	if (top==NULL){
		New->nxt = NULL;
		top = New;
	}else{
		New->nxt = top;
		top = New;
	}
	
}


void deleteStack(Stack* &top){
	Stack* aux = top;
	top = aux->nxt;
	delete aux;
}

//Queue Functions

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
	Queue* aux = front;
	front = aux->nxt;
	delete aux;	
}

//MAIN THREAD
int main(){
	Stack* top=NULL;
	Queue* front=NULL;
	Queue* rear=NULL;
	
	int op, n, sz_s=-1, sz_q=-1;
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
		cout<<"8. Pass node (from queue to stack)\n";/*
		cout<<"9. Modify 1 \n";
		cout<<"10. Modify 2 \n";
		cout<<"11. Modify 3\n";
		cout<<"12. Modify 4 \n";
		cout<<"13. Modify 5 \n";
		cout<<"14. Modify 6 \n";
		cout<<"15. Search 1 \n";
		cout<<"16. Search 2 \n";*/
		cout<<"17. Exit \n";
		cout<<"Choose an option: \n";
		cin>>op;
		
		switch(op){
			case 1:
					cout<<"Type a number to add to the stack: \n";
					cin>>n;
					addStack(top, n);
					sz_s++;
			break;
			
			case 2:
				if(top==NULL){
					cout<<"The stack is empty. Add a node and try again. \n";
				}else{
					n = top->n;
					deleteStack(top);
					cout<<"The value of the deleted node is: "<<n<<endl;
					sz_s--;
				}
			break;
			
			case 3:
					cout<<"Type a number to add to the queue: \n";
					cin>>n;
					addQueue(front, rear, n);
					sz_q++;
			break;
			
			case 4:
				if(front==NULL){
					cout<<"The queue is empty. Add a node and try again. \n";
				}else{
					n = front->n;
					deleteQueue(front);
					cout<<"The value of the deleted node is: "<<n<<endl;
					sz_q--;
				}
				
			break;
			
			case 5:
				cout<<"The number in the top is: "<<top->n<<endl;
			break;
			
			case 6:
				cout<<"The number in the front is: "<<front->n<<endl;
				cout<<"The number in the rear is: "<<rear->n<<endl; 
			break;
			
			case 7:
				n = top->n;
				deleteStack(top);
				addQueue(front, rear, n);
				cout<<"The number "<<n<<" was deleted from stack and added to the queue. \n";
			break;
			
			case 8:
				n = front->n;
				deleteQueue(front);
				addStack(top, n);
				cout<<"The number "<<n<<" was deleted from queue and added to the stack. \n";
			break;
			
			case 9:
				
			break;
			case 17: 
				cout<<"Shutting down program... \n";
				cond=false;
			break;
			
			default:
				cout<<"Error: option doesnt exists, try again. \n";
			break;
		}
	}
	return 0;
}