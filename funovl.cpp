#include<iostream>
#include<cmath>
using namespace std;

double exponent(int a, int n){
	return pow(a, n);
}

double exponent(float a, int n){
	return pow(a, n);
}

char exponent(char a, int n){
	for(; n>0; n--) cout<<a;
	return '\0';
}

int main(){
	int a, n;
	float b;
	char c;
	cout<<"Enter int, float, char and n: "<<endl;
	cin>>a>>b>>c>>n;
	cout<<exponent(a,n)<<endl<<exponent(b,n)<<endl;
	exponent(c,n); cout<<endl;
}
