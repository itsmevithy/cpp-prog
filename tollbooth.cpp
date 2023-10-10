#include<iostream>
#include<cstdio>
using namespace std;

class tollBooth{
	unsigned int carno;
	double paid;
	public:
		tollBooth(){
			carno=0;
			paid=0;
		}
		void payingCar(){
			paid+=0.5;
		}
		void nopayCar(){
			carno+=1;
		}
		void display(){
			cout<<"Total paid toll: "<<paid<<" units";
			cout<<"\nCars passed toll: "<<carno;
		}
};

int main(){
	char x;
	tollBooth p;
	cout<<"Enter p for paid toll, s for skipped toll: ";
	do{
		cin>>x;
		switch(x){
			case('p'):
				p.payingCar();
				break;
			case('s'):
				p.nopayCar();
				break;
			case(27): break;
			default:
				cout<<"\nEnter valid input!!!\n";
				continue;
		}
		cout<<"Done! Continue or press esc to exit...\n";
	}
	while(x!=27);
	p.display();
	cout<<"\nexitting...\n";
}
