#include<iostream>
using namespace std;

int prime(int x){
	for(int j=2; j<x; j++)
		if(x%j==0) return false;
	return true;
}

int main(){
	int count=0, i;
	for(i=2; count<10001 ;i++) if(prime(i)) count++;
	cout<<i-1;
}
