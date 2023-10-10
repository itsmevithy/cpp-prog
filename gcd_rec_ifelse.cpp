#include<iostream>
using namespace std;

int gcd(int a, int b){
	if ((a==0)||(b==0)) return a+b;
	else if (a==b) return a;
	else if (a>b) return gcd(a-=b, b);
	else return gcd(a, b-=a);
}

int main(){
	int x, y;
	cin>>x>>y;
	cout<<"The GCD/HCF is "<<gcd(x, y)<<endl;
}
