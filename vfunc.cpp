#include<iostream>
using namespace std;

class Base{
	private:
		int a;
	public:
		virtual void print(){
			cout<<"Base print.\n";
		}
		void show(){
			cout<<"Base show.\n";
		}
};
class Derv: public Base{
	public:
		void print(){
			cout<<"Derv print.\n";
		}
		void show(){
			cout<<"Derv show.\n";
		}
};

int main(){
	Base *p;
	Derv d;
	p=&d;
	p->print();
	p->show();
	return 0;
}
