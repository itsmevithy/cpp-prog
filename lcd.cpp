#include<iostream>
using namespace std;

int gcd(int a, int b){
	if (b!=0) return gcd(b, a%b);
	else return a;
}

void check(int x){
	if (((x==2)||(x==3)||(x==5)||(x==7))||((gcd(2,x)==1)&&(gcd(3,x)==1)&&(gcd(5,x)==1)&&(gcd(7,x)==1))) return true;
	else return false;
}

int main(){
	int a, b, i, k, res, check;
	cin>>a>>b;
	k=(a>b)?gcd(a, b):gcd(b, a);
	for(i=2; i<=k; i++){
		if(check(i))
			if(k%i==0){
				check=1;
				res=i;
				break;		
			} 
	}
	
}
