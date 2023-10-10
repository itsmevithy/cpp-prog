#include<iostream>
using namespace std;

class Stack{
	int top=-1;
	string stack;
	public:
		int size;
		Stack(string arr){
			stack=arr;
		}
		Stack(){}
		bool empty(){
			return (top==-1)?true:false;
		}
		void push(char data){
			stack[++top]=data;	
		}
		bool pop(char &dataout){
			if(empty()) return false;
			dataout=stack[top--];
			return true;
		}
		bool peek(char &dataout){
			if(empty()){
				dataout='\0';
				return false;
			}
			dataout=stack[top];
			return true;
		}
		void display(){
			cout<<stack<<endl;
		}
};
int priority(char x){
	return ((x=='^')?3:((x=='*')||(x=='/'))?2:((x=='+')||(x=='-'))?1:0);
}
int main(){
	string exp;
	char ch;
	int top=-1;
	cout<<"Enter the expression: ";
	cin>>exp;
	char* post=new char[sizeof(exp)/sizeof(ch)];
	Stack temp;
	for(char i:exp){
		switch(i){
		case '(':
		      temp.push(i);
		      break;
		case ')':	
			temp.pop(ch);
			while(ch!='('){
				post[++top]=ch;
				temp.pop(ch);
			}
			break;
		case '^':case '*':case '+':case '-': case '/':
			temp.peek(ch);
			while((!temp.empty())&&(priority(i)<=priority(ch))){
				temp.pop(ch);
				post[++top]=ch;
				temp.peek(ch);
			}
			temp.push(i);
			break;
		default:
			post[++top]=i;
			break;
		}
	}
	while(!temp.empty()){
		temp.pop(ch);
		post[++top]=ch;
	}
	cout<<"The postfix form is: "<<post<<endl;
}
