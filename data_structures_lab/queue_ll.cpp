#include<iostream>
using namespace std;

struct node{
	int data;
	node *link;
};

struct head{
	int count;
	node *front;
	node *rear;
};

class Queue{
	head *queue;
	public:
		Queue(){
			createQueue();
		}
		void createQueue(){
			queue=new head();
			queue->count=0;
			queue->front=NULL;
			queue->rear=NULL;
		}
		bool enqueue(int dataIn){
			node *T=new node;
			if(T==NULL) return false;
			T->data=dataIn;
			T->link=queue->rear;
			if((queue->rear)==NULL) queue->front=T;
			else queue->rear->link=T;
			queue->rear=T;
			T->link=NULL;
			(queue->count)++;
			return true;
		}
		bool queueFront(int &dataOut){
			if(emptyQueue()) return false;
			dataOut=queue->front->data;
			return true;
		}
		bool queueRear(int &dataOut){
			if(emptyQueue()) return false;
			dataOut=queue->rear->data;
			return true;
		}
		bool dequeue(int &dataOut){
			if(emptyQueue()) return false;
			node *T=queue->front;
			dataOut=T->data;
			queue->front=T->link;
			if(queue->front==NULL) queue->rear=NULL;
			(queue->count)--;
			delete T;
			return true;
		}
		bool emptyQueue(){
			return (queue->front==NULL)?true:false;
		}
		int count(){
			return queue->count;
		}
		void display(){
			if(emptyQueue()) return;
			node *T=queue->front;
			while(T->link!=NULL){
				cout<<T->data<<", ";
				T=T->link;
			}
			cout<<T->data;
			cout<<endl;	
		}
		void destroyQueue(){
			node *temp=new node;
			while(!emptyQueue()){
				temp=queue->front;
				queue->front=temp->link;
				delete temp;
			}
			queue->count=0;
			queue->rear=NULL;
			cout<<"Done\n";
		}
};

int main(){
	Queue arr;
	int x, choice;
	bool check;
	do{
		cout<<"Enter choice: [0-Exit, 1- Enqueue, 2-Dequeue, 3-QueueFront, 4-QueueRear, 5-Display, 6-Count, 7-Destroy]";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter element to enqueue: ";
				cin>>x;
				cout<<((arr.enqueue(x))?"Done":"Failed")<<endl;
				break;
			case 2:	
				check=arr.dequeue(x);
				cout<<((check)?"Done":"Failed")<<endl;
				if(check) cout<<"The element is "<<x<<endl;
				break;
			case 3:
				check=arr.queueFront(x);
				cout<<((check)?"Done":"Failed")<<endl;
				if(check) cout<<"The element is "<<x<<endl;
				break;
			case 4:
				check=arr.queueRear(x);
				cout<<((check)?"Done":"Failed")<<endl;
				if(check) cout<<"The element is "<<x<<endl;
				break;

			case 6:
				cout<<"The number of elements is "<<arr.count()<<endl;
				break;
			case 5:
				arr.display();
				break;
			case 7:
				arr.destroyQueue();
				break;				
			default:
				choice=0;
				break;
		}
	}while(choice);
}
