#include<iostream>
using namespace std;

class Tele{
	int ac, exc, num;
	public:
		void get_data(){
			cout<<"Enter area code, exchange, number: ";
			cin>>ac>>exc>>num;
		}
		void print(){
			cout<<"(+"<<ac<<") "<<exc<<"-"<<num<<endl;
		}
};

int main(){
	Tele mynum;
	mynum.get_data();
	cout<<" My number is ";
	mynum.print();
}
