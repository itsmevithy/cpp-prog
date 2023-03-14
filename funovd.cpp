#include<iostream>
using namespace std;

int exponent(int a, int n){
	return a;
}

float exponent(float a, int n){ 
	return a;
}

char exponent(char a, int n){
	for(; n>0; n--) cout<<a;
	return '\0';
}

int main(){
	int a, n;
	float b;
	char c;
	cout<<"Enter int, float, char and n: ";
	cin>>a>>b>>c>>n;
	cout<<exponent(a,n)<<endl<<exponent(b,n)<<endl<<exponent(c, n)<<endl;
}
