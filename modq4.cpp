#include<iostream>
using namespace std;

class Bank{
	protected:
		int accno;
		float bal;
	public:
		void get_data(){
			cout<<"Enter account no: ";
			cin>>accno;
			cout<<"Enter available balance: ";
			cin>>bal;
		}
		void display(){
			cout<<"Account no: "<<accno<<"\nAvailable balance: "<<bal<<" rupees\n";
		}
};

class User:public Bank{
	public:
		void credit(){
			float a;
			cout<<"Enter amount to be credited: ";
			cin>>a;
			bal+=a;
		}
		void debit(){
			float a;
			cout<<"Enter amount to be debited: ";
			cin>>a;
			if(bal>=a) (bal-=a);
			else cout<<"Insufficient balance!!\n";
		}
};

int main(){
	int i, n, c;
	cout<<"Enter no of users: "; 
	cin>>n;
	User cust[n];
	for(i=0; i<n; i++){
		cout<<"User "<<i+1<<":-\n";
		cust[i].get_data();}
	for(i=0; i<n; i++){
		cout<<"User "<<i+1<<":-\n";
		cust[i].display();}
	do{
		for(i=0; i<n; i++){
			cout<<"User "<<i+1<<":-\n"<<"Enter 1 for credit, 2 for debit, any other number to skip: ";
			cin>>c;
			switch(c){
				case 1:
					cust[i].credit();
					break;
				case 2:
					cust[i].debit();
					break;
				default:
					cust[i].display();
					cout<<"Skipping to next user..";
					break;
			}
			if((c==1)||(c==2)) cust[i].display();
		}
	cout<<"To continue, press 3: ";
	cin>>c;
	}while(c==3);
}
