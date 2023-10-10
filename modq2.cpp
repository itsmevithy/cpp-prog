#include<iostream>
using namespace std;

class Farenheit{
	private:
		float f;
	public:
		Farenheit(): f(0){}
		Farenheit(float a): f(a){}
		void show(){
			cout<<f<<" Farenheit.\n";}
};
class Celsius{
	private:
		float c;
	public:
		Celsius(): c(0){}
		Celsius(float a): c(a){}

		Farenheit operator+(Celsius a){
			return Farenheit((a.c+c)*9/5+32);
		}

		void operator=(float a){
			c=a;
		}
		void show(){
		cout<<c<<" Celsius.\n";}
};

int main(){
	Farenheit F;
	Celsius c1, c2;
	float a1, a2;
	cout<<"Enter 2 temperatures in Celsius: ";
	cin>>a1>>a2;
	c1=a1; c2=a2;
	F=c1+c2;
	c1.show(); c2.show();
	F.show();
}
