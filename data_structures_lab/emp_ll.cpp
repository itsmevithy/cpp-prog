#include<iostream>
using namespace std;

class Employee{
	string name, dept;
	int empid, YOE;
	float basicpay;
	public:
		Employee(){};
		Employee(string name, string dept, int id, int yrs, float bpay){
		this->name=name;
		this->dept=dept;
		empid-id;
		YOE=yrs;
		basicpay=bpay;
		};
		float calc_bonus(){
			return (YOE>5)?(basicpay*0.2):(basicpay*0.1);
		}
		int id(){
			return empid;
		}
		void display(){
			cout<<"The employee details are, \nName: "<<name<<"\nEmp ID: "<<empid<<"\nDept: "<<dept<<"\nYears of experience: "<<YOE<<"\nBasic pay: "<<basicpay<<endl;
		}
};
struct node{
	Employee data;
	node *link;
};
struct head{
	int count;
	node *first;
};
class Sll{
	head *list;
	public:
		Sll(){
			list=new head;
			list->first=NULL;
			list->count=0;
		}
		bool push(Employee dataIn){
			node *T=new node, *pPre=NULL, *pLoc=NULL;
			if(T==NULL) return false;
			T->data=dataIn;
			if(search(pPre, pLoc, dataIn.id())) return false;
			if(pPre==NULL) list->first=T;
			else pPre->link=T;
			T->link=NULL;
			(list->count)++;
			return true;
		}
		bool search(node *&pPre, node *&pLoc, int key){
			pPre=NULL;
			pLoc=list->first;
			while((pLoc!=NULL)&&(pLoc->data.id()!=key)){
				pPre=pLoc;
				pLoc=pLoc->link;
			}
			if(pLoc->data.id()==key) return true;
			return false;
		}
		void displayAll(){
			node *T=list->first;
			while(T->link!=NULL){
				T->data.display();
				T=T->link;
			}
		}
		bool display(int id){
			node *pPre=NULL, *pLoc=NULL;
			if(!search(pPre, pLoc, id)) return false;
			pLoc->data.display();
			return true;
		}
		bool printBonus(int id){
			node *pPre=NULL, *pLoc=NULL;
			if(!search(pPre, pLoc, id)) return false;
			pLoc->data.display();
			cout<<"Bonus for the employee is "<<pLoc->data.calc_bonus()<<endl;
			return true;
		}
};
int main(){
	Sll emprec;
	int n, i;
	string name, dept;
	int empid, YOE;
	float bpay;
	cout<<"Enter number of employees: ";
	cin>>n;
	cout<<"Initalise data:-\n";
	for(i=0; i<n; i++){
		cout<<"For employee "<<i+1<<"\nEnter name: ";
		cin>>name;
		cout<<"Enter dept";
		cin>>dept;
		cout<<"Enter employee ID: ";
		cin>>empid;
		cout<<"Enter years of experience: ";
		cin>>YOE;
		cout<<"Enter basic pay: ";
		cin>>bpay;
		Employee *e=new Employee(name, dept, empid, YOE, bpay);
		cout<<((emprec.push(*e))?"Data recorded":"Failed")<<endl;
		delete e;
	}
	int choice;
	do{
		cout<<"Enter choice[1-Search employee, 2-Display all records, 3-Print bonus, ANY KEY- Exit]: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"ENter employee id to search: ";
				cin>>i;
				cout<<(emprec.display(i))?"Done!":"Not found.";
				break;
			case 2:
				emprec.displayAll();
				break;
			case 3:
				cout<<"Enter employee id to calculate bonus: ";
				cin>>i;
				cout<<(emprec.printBonus(i))?"Done!":"Not Found.";
				break;
			default:
				choice=0;
				break;
		}
	}while(choice);
}
