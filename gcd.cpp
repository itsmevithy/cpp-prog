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

int main(){
	int a, b;
	cin>>a>>b;
	cout<<gcd(a,b);
}
