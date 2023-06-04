#include<iostream>
using namespace std;

class Fuel{
	private:
		float ptl, dsl, amt;
	public:
		Fuel():ptl(100), dsl(100), amt(0){}
		void showbal(){
			cout<<"The available balance is, \n";
			cout<<"Petrol: "<<ptl<<" litres.\n";
			cout<<"Diesel: "<<dsl<<" litres.\n";
			cout<<"Balance: "<<amt<<" rupees.\n";
		}
		void pd(char ch){
			float a;
			float& b=(ch=='p')?ptl:dsl;
			int mul=(ch=='p')?100:95;
			cout<<"Enter litres of "<<((ch=='p')?"petrol":"diesel")<<" needed: ";
			cin>>a;
			cout<<"Generating request..";
			if((b-a)>0){
				cout<<"Fuel available, request accepted!\nAccepting payment..\nFilling fuel..\n";
				b-=a;
				amt+=(a*mul);
				cout<<"Done!!\n";
			}
			else cout<<"Insufficient fuel stock, request rejected!\n";
			showbal();
		}
		void f(){
			float a;
			float temp;
			cout<<"Enter amount available: ";
			cin>>a;
			float& h=(ptl>dsl)?ptl:dsl;
			float& l=(ptl>dsl)?dsl:ptl;
			int hmul=(ptl>dsl)?100:95;
			int lmul=(ptl>dsl)?95:100;
			if(a>(h*hmul+l*lmul)) cout<<"Insufficient fuel stock, request rejected!\n";
			else{
				if(a>l*lmul){
					temp=(a-l*lmul)/hmul;
					cout<<"Filling "<<temp<<" litres of "<<((ptl>dsl)?"petrol":"diesel")<<endl;
					h-=temp;
				}
				temp=a/lmul;
				cout<<"Filling "<<temp<<" litres of "<<((ptl>dsl)?"diesel":"petrol")<<endl;
				l-=temp;
			}
			amt+=a;
			showbal();
		}	
};

Fuel bunk;

static void inp(){
	char ch;
	int chk;
	do{
		cout<<"Enter choice (p/d/f): ";
		cin>>ch;
		if((ch=='p')||(ch=='d')||(ch=='f')) chk=1;
	}while(chk!=1);
	if((ch=='p')||(ch=='d')) bunk.pd(ch);
	else bunk.f();
	cout<<"To continue, press 1: ";
}

int main(){
	int chk;
	do{
		inp();
		cin>>chk;
	}while(chk==1);
}
