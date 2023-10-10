#include<iostream>
using namespace std;

class Temp{
	float Kelvin, Celsius, Farenheit;
	public:
		void getC(){
			cin>>Celsius;
			Kelvin=Celsius+273.15;
			Farenheit=(9.0/5)*Celsius+32;
		}
		void getK(){
			cin>>Kelvin;
			Celsius=Kelvin-273.15;
			Farenheit=(9.0/5)*Celsius+32;
		}
		void getF(){
			cin>>Farenheit;
			Celsius=(Farenheit-32)*(5.0/9);
			Kelvin=Celsius+273.15;
		}
		void show(){
			cout<<"Celsius: "<<Celsius<<"C"<<endl;
			cout<<"Kelvin: "<<Kelvin<<"K"<<endl;
			cout<<"Farenheit: "<<Farenheit<<"F"<<endl;
		}
};

int main(){
	Temp c, f, k;
	cout<<"Celsius: "; c.getC(); c.show();
	cout<<"Kelvin: "; k.getK(); k.show();
	cout<<"Farenheit: "; f.getF(); f.show();
}
