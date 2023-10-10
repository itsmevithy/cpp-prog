#include<iostream>
using namespace std;

int gcd(int a, int b){
	if (b!=0) return gcd(b, a%b);
	else return a;
}

void check(int x){
	if (((x==2)||(x==3)||(x==5)||(x==7))||((gcd(2,x)==1)&&(gcd(3,x)==1)&&(gcd(5,x)==1)&&(gcd(7,x)==1))) cout<<"PRIME\n";
	else cout<<"NON PRIME\n";
}

int main(){
	int k;
	cin>>k;
	check(k);
}
