#include<iostream>
using namespace std;

int fact(int n){
	return (n<=1)?1:(n*fact(n-1));
}

int main(){
	int n;
	cout<<"Enter number: ";
	cin>>n;
	cout<<"The factorial is "<<fact(n)<<endl;
}
