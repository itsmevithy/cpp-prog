#include<iostream>
using namespace std;

int gcd(int a, int b){
	int g=0;
	while(g==0){
		((a==0)||(b==0))?(g=a+b):
		(a==b)?(g=a):
		(a>b)?(g=gcd(a-=b, b)):
		(g=gcd(a, b-=a));
	}
	return g;
}

int main(){
	int a, b;
	cin>>a>>b;
	cout<<gcd(a,b);
}
