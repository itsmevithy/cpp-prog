#include<iostream>
using namespace std;

class Stack{
	int top=-1; 
	public:
		int size;

		bool EmptyStack(int *stack){
			if(top==-1) return true;  
			else return false;
		}	

		bool FullStack(int *stack){
			if(top==size-1) return true;  
			else return false;
		}

		bool PushStack(int *stack, int data){
			bool success;
			if(FullStack(stack)) success=false;
			else{
				stack[++top]=data;
				success=true;}
			return success;
		}

		bool PopStack(int *stack, int &dataout){
			bool success;
			if(EmptyStack(stack)) success=false;  
			else{
				dataout=stack[top--];
				success=true;
			}
			return success;
		}

		bool StackTop(int *stack, int &dataout){
			bool success;
			if(EmptyStack(stack)) success=false;  
			else{
				dataout=stack[top];
				success=true;
			}
			return success;
		}
};
int main(){
	int num, choice, *array;
	Stack s1;
	cout<<"Enter number of elements in stack: ";
	cin>>s1.size;
	array= new int[s1.size];

	do{
		cout<<"Enter your choice (1-Push 2-Pop 3-Peek [Any key]-End): ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter element to push: ";
				cin>>num;
				if(s1.PushStack(array, num)) cout<<"Done!\n";
				else cout<<"Overflow!\n";
				break;
			case 2:
				if(s1.PopStack(array, num)) cout<<"Done!\n The element is "<<num<<endl;
				else cout<<"Underflow!\n";
				break;
			case 3:
				if(s1.StackTop(array, num)) cout<<"Done!\n The element is "<<num<<endl;
				else cout<<"Underflow!\n";
				break;
			default:
				choice=0;
				break;
		}
	}while(choice);
}
