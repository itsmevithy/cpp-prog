#include <iostream>
using namespace std;
#define max 5
class StackbySLL{
	private:
    		int stack[max];
	public:
 	   struct node{
		int data;
        	node *link;
    	};
    	struct stackhead{
        	int count;
        	node *top;
    	};
    	stackhead *stackheadnode;

    	void create(){
        	stackheadnode = new stackhead();
        	stackheadnode->count = 0;
        	stackheadnode->top = NULL;
    	}
    	bool push(int datain){
        	node *newnode = new node;
        	if (newnode == NULL) return false;
        	else{
	        	newnode->data = datain;
            		newnode->link = stackheadnode->top;
           		stackheadnode->top = newnode;
            		(stackheadnode->count)++;
            		return true;
        	}
    	}
	bool pop(int dataout){
        	bool res;
        	res = emptystack();
        	if (res) return false;
        	else{
            		int dataout = stackheadnode->top->data;
            		stackheadnode->top = stackheadnode->top->link;
            		cout << "Data deleted is" << dataout;
            		(stackheadnode->count)--;
            		return true;

        	}
    	}	
	bool emptystack(){
        	if(stackheadnode->count==0) return true;
        	else return false;
    	}
	bool fullstack(){
        	if (stackheadnode->count == max) return true;
     		else return false;
	}
	bool stacktop(){
    		bool res=emptystack();
    		if(res) return false;
		else{
			int dataout=stackheadnode->top->data;
       			cout<<dataout;
       			return true;  
    		}
	}
	void display(){
		node *current = stackheadnode->top;
		while (current != NULL){
			cout << current->data << " ";
       			current = current->link;
    		}
    		cout << endl;
	}
};
int main(){
	StackbySLL obj;
	int choice,x;
	bool res;
	for (int i = 0; i < 7; i++){
		do{
       			cout << " 0.create 1.push 2.pop 3.emptystack 4.fullstack 5.stacktop 6.display";
       			cout << "Enter choice" << endl;
       			cin >> choice;
       			switch (choice){
       				case 0:
        				obj.create();
           				break;
       				case 1:
           				cout << "Enter element to push";
           				cin >> x;
           				res = obj.push(x);
           				if (res) cout << "pushed succesfully" << endl;
           				else cout << "Cannot push" << endl;
       					break;
    				case 2:
       					cout << "Enter element to pop";
       					cin >> x;
       					res = obj.pop(x);
       					if (!res) cout << "popped successfully" << endl;
       					else cout << "cannot pop";
       					break;
    				case 3:
      					res=obj.emptystack();
      					if(res) cout<<"Stack is empty"<<endl;
      					else cout<<"Not empty"<<endl;
       					break;
    				case 4:
       					res = obj.fullstack();
       					if (res) cout << "stack is full" << endl;
       					else cout << "stack Not full" << endl;
       					break;
    				case 5:
      					res=obj.stacktop();
					if(res) cout<<"Stack top is found"<<endl;
					else cout<<"Stack empty"<<endl;
					break;
   				 case 6:
       					cout << "Elements in the stack are" << endl;
       					obj.display();
       					break;
    				default:
       					cout << "Check!!!!!" << endl;
    			}
		}while (choice != 7);
	}
}
