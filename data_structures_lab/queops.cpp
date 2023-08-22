#include<iostream>
using namespace std;

class Queue{
	int *queue, size, front=-1, rear=-1;
	public:
		bool success;
		void initqueue(){
			cout<<"Enter size of the queue: ";
			cin>>size;
			queue=new int[size];
		}
		bool FullQueue(){
			return (rear==size-1)?true:false;
		}
		bool EmptyQueue(){
			return ((front==-1)&&(rear==-1))?true:false;
		}
		bool enqueue(int dataIn){
			if(FullQueue()) success=false;
			else{
				queue[++rear]=dataIn;
				front=(front==-1)?0:front;
				success=true;
			}
			return success;
		}
		bool dequeue(int &dataOut){
			if(EmptyQueue()) success=false;
			else{
				dataOut=queue[front];
				if(front==rear) front=rear=-1;
				else front++;
				success=true;
			}
			return success;
		}
		bool QueueFront(int &dataOut){
			if(EmptyQueue()) success=false;
			else{
				dataOut=queue[front];
				success=true;
			}
			return success;
		}
		bool QueueRear(int &dataOut){
			if (EmptyQueue()) success=false;
			else{
				dataOut=queue[rear];
				success=true;
			}
			return success;
		}
		int QueueCount(){
			if (EmptyQueue()) return 0;
			else return rear-front+1;
		}
};

int main(){
        int num, choice, *array;
        Queue s1;
        s1.initqueue();

        do{
                cout<<"Enter your choice (1-Enqueue 2-Dequeue 3-QueueFront 4-QueueRear 5-QueueCount [Any key]-End): ";
                cin>>choice;
                switch(choice){
                        case 1:
                                cout<<"Enter element to push: ";
                                cin>>num;
                                if(s1.enqueue(num)) cout<<"Done!\n";
                                else cout<<"Overflow!\n";
                                break;
                        case 2:
                                if(s1.dequeue(num)) cout<<"Done!\n The element is "<<num<<endl;
                                else cout<<"Underflow!\n";
                                break;
                        case 3:
                                if(s1.QueueFront(num)) cout<<"Done!\n The element is "<<num<<endl;
                                else cout<<"Underflow!\n";
                                break;
			case 4:
				if(s1.QueueRear(num)) cout<<"Done!\n The element is "<<num<<endl;
                                else cout<<"Underflow!\n";
                                break;
			case 5:
				cout<<"Number of elements in the queue: "<<s1.QueueCount()<<endl;
				break;
                        default:
                                choice=0;
                                break;
                }
        }while(choice);
}

