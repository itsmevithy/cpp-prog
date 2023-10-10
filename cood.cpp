#include<iostream>
using namespace std;

class cood{
	int x, y;
	public:
		void inp(){
			cin>>x>>y;
		}
		void res(cood a, cood b){
			x=a.x+b.x;
			y=a.y+b.y;
		}
		void print(){
			cout<<x<<' '<<y<<endl;
		}
};

int main(){
	cood x, y, z;
	cout<<"Enter coordinates of x: ";
	x.inp();
	cout<<"Enter coordinates of y: ";
	y.inp();
	z.res(x, y);
	cout<<"Coordinates of z are: ";
	z.print();
}
