#include<iostream>
using namespace std;

struct node{
	int data;
	node *link;
};

struct head{
	int count;
	node *first;
};

class Stack{
	head *list;
	public:
		Stack(){
			createStack();
		}
		void createStack(){
			list=new head();
			list->count=0;
			list->first=NULL;
		}
		bool pushStack(int dataIn){
			node *pNew=new node;
			if(pNew==NULL) return false;
			pNew->data=dataIn;
			pNew->link=list->first;
			list->first=pNew;
			(list->count)++;
			return true;
		}
		bool stackTop(int &dataOut){
			if(emptyStack()) return false;
			dataOut=list->first->data;
			return true;
		}
		bool popStack(int &dataOut){
			if(emptyStack()) return false;
			node *temp=list->first;
			dataOut=temp->data;
			list->first=temp->link;
			(list->count)--;
			delete temp;
			return true;
		}
		bool emptyStack(){
			return (list->first==NULL)?true:false;
		}
		int count(){
			return list->count;
		}
		void display(){
			node *temp=list->first;
			while(temp!=NULL){
				cout<<temp->data<<", ";
				temp=temp->link;
			}
			cout<<endl;	
		}
		void destroyStack(){
			node *temp=new node;
			while(!emptyStack()){
				temp=list->first;
				list->first=temp->link;
				delete temp;
			}
			list->count=0;
			cout<<"Done\n";
		}
};

int main(){
	Stack arr;
	int x, choice;
	bool check;
	do{
		cout<<"Enter choice: [0-Exit, 1- Push, 2-Pop, 3-Stacktop, 4-Count, 5-Display, 6-Destroy]";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter element to push: ";
				cin>>x;
				cout<<((arr.pushStack(x))?"Done":"Failed")<<endl;
				break;
			case 2:	
				check=arr.popStack(x);
				cout<<((check)?"Done":"Failed")<<endl;
				if(check) cout<<"The element is "<<x<<endl;
				break;
			case 3:
				check=arr.stackTop(x);
				cout<<((check)?"Done":"Failed")<<endl;
				if(check) cout<<"The element is "<<x<<endl;
				break;
			case 4:
				cout<<"The number of elements is "<<arr.count()<<endl;
				break;
			case 5:
				arr.display();
				break;
			case 6:
				arr.destroyStack();
				break;				
			default:
				choice=0;
				break;
		}
	}while(choice);
}
