#include<iostream>
using namespace std;

void fib(int n, int a=0, int b=1){
	if(n>0){
		n--;
		cout<<a;
		if(n>0) cout<<", ";
		else cout<<".\n";
		fib(n, b, a+b);
	}
}

int main(){
	int n;
	cout<<"Enter a number to calculate fib series: ";
	cin>>n;
	fib(n);
}
