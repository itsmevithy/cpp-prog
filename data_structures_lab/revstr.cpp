#include<iostream>
#include<string.h>

using namespace std;

class Stack{
	int top=-1; 
	public:
		int size=50;

		bool EmptyStack(char *stack){
			if(top==-1) return true;  
			else return false;
		}	

		bool FullStack(char *stack){
			if(top==size-1) return true;  
			else return false;
		}

		bool PushStack(char *stack, char data){
			bool success;
			if(FullStack(stack)) success=false;
			else{
				stack[++top]=data;
				success=true;}
			return success;
		}

		bool PopStack(char *stack, char &dataout){
			bool success;
			if(EmptyStack(stack)) success=false;  
			else{
				dataout=stack[top--];
				success=true;
			}
			return success;
		}

		bool StackTop(char *stack, char &dataout){
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
	Stack s1, s2;
	char array[50], rev_array[50], x;
	cout<<"Enter a string: ";
	while((x=getchar())!='\n') s1.PushStack(array, x);
	s1.PushStack(array, '\0');
	cout<<"Before reversing: "<<array<<endl;
	s1.PopStack(array, x);
	while(s1.PopStack(array, x)) s2.PushStack(rev_array, x);
	s2.PushStack(rev_array, '\0');
	cout<<"After reversing: "<<rev_array<<endl;
}
