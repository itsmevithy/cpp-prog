#include<iostream>
using namespace std;

int gcd(int a, int b){
	int gcd=0;
	while(gcd==0){
		(a==b)?(gcd=a)
		:(a>b)?(a-=b)
		:(b>a)?(b-=a)
		:(a==0)?(gcd=b)
		:(b==0)?(gcd=a)
		:0;
	}
	return gcd;
}

class Fraction{
	int n,d;
	public:
		Fraction():n(0), d(1){};
		Fraction(int a, int b){
			if(b==0){
				cout<<"Denominator cannot be zero. Enter again!\n";
				cin>>b;
			}
			int div=gcd(a, b);
			n=a/div;
			d=b/div;
		}
		Fraction(float a){
			int b=1, div;
			while((a-int(a))!=0){
				a*=10;
				b*=10;
			}
			div=gcd(a, b);
			n=a/div;
			d=b/div;
		}
		void get(){
			cout<<"Enter in p/q form: ";
			cin>>n>>d;
			if(d==0){
				cout<<"Denominator cannot be zero. Enter again!\n";
				cin>>d;
			}
			int div=gcd(n, d);
			n/=div;
			d/=div;
		}
		void print(){
			cout<<"The p/q simplified form is "<<n<<'/'<<d<<endl;
		}
		operator float(){
			return(float(n)/d);
		}
};

int main(){
	Fraction a;
	a.print();
	a.get();
	a.print();
	cout<<"Float form is "<<float(a)<<endl;
	int p, q;
	cin>>p>>q;
	Fraction b(p,q);
	b.print();
	cout<<"Float form is "<<float(b)<<endl;
	cout<<"Enter in float form: ";	
	float r; cin>>r;
	Fraction c(r);
	c.print();	
}
