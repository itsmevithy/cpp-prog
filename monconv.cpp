#include<iostream>

using namespace std;

class Dollar;

class Rupee{
	private:
		float val;
	public:
		Rupee(float a): val(a) {}
		Rupee(): val(0){}

		void inp(){
			cout<<"Enter amount in INR: ";
			cin>>val;
		}
		void print(){
			cout<<"Amount in INR is "<<val<<" rupees.\n";
		}
		Dollar R2D();
};

class Dollar{
	private: float val;
	public:
		
		Dollar(float a): val(a){}
		Dollar(): val(0){}

		void inp(){
			cout<<"Enter amount in USD: ";
			cin>>val;
		}
		void print(){
			cout<<"Amount in USD is "<<val<<" dollars.\n";
		}
		Rupee D2R();
};

inline Dollar Rupee::R2D(){
	return Dollar(val/81.87);}

inline Rupee Dollar::D2R(){
	return Rupee(val*81.87);}


int main(){
	Rupee rsource, rres;
	Dollar dsource, dres;

	rsource.inp();
	rsource.print();
	dres=rsource.R2D();
	dres.print();

	dsource.inp();
	dsource.print();
	rres=dsource.D2R();
	rres.print();
}
