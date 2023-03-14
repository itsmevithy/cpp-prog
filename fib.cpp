#include<iostream>
using namespace std;

int fib(int n, int a=0, int b=1){
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
	cin>>n;
	fib(n);
}
