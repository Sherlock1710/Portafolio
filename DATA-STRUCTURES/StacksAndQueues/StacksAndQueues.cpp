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

void initStack(Stack* &top, int n){
	Stack* newS = new Stack;
	newS->n = n;
	newS->nxt = NULL;
	top = newS;
}

void addStack(Stack* &top, int n){
	Stack* newS = new Stack;
	newS->n = n;
	newS->nxt = top;
	top = newS;
}

void deleteStack(Stack* &top){
	Stack* aux = top;
	top = aux->nxt;
	delete aux;
}

//Queue Functions

void initQueue(){
	
}

int main(){
	Stack* top=NULL;
	Queue* front=NULL;
	Queue* rear=NULL;
	
	int op, n, sz;
	bool cond = true;
	
	while(cond){
		cout<<"====================MENU====================\n";
		cout<<"1. Add to stack \n";
		cout<<"2. Delete from stack \n";
		/*cout<<"3. Add to queue \n";
		cout<<"4. Delete from queue \n";*/
		cout<<"5. Show top (stack)\n";/*
		cout<<"6. Show front and rear (queue) \n";
		cout<<"7. Pass 1 (from stack to queue) \n";
		cout<<"8. Pass 2 (from queue to stack)\n";
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
				if(sz==10){
					cout<<"Type a number to init the stack: \n";
					cin>>n;
					initStack(top, n);
					sz-=1;
				}else{
					if(sz>0){
					cout<<"Type a number to add to the stack: \n";
					cin>>n;
					addStack(top, n);
					sz-=1;
					
				}else{
					cout<<"The stack is full. Delete a node and try again. \n";
					}		
				}
			break;
			
			case 2:
				if(sz==10){
					cout<<"The stack is empty. Add a node and try again. \n";
				}else{
				n = top->n;
				deleteStack(top);
				cout<<"The value of the deleted node is: "<<n<<endl;
				}
			break;
			
			case 3:
				
			
			case 5:
				cout<<"The number in the top is: "<<top->n<<endl;
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