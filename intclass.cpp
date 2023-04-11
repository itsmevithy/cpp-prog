#include<iostream>
using namespace std;

class Int{
	int x;
	public:
		Int(){
			x=0;
		}
		Int(int a){
			x=a;
		}
		void add(Int a, Int b){
			x=a.x+b.x;
		}
		void display(){
			cout<<x<<endl;
		}
};

int main(){
	Int a(2), b(4), c;
	c.add(a, b);
	c.display();
}
