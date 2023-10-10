#include<iostream>
using namespace std;

int divs(int x){
	int k=1;
	for(int i=2; i<x;i++)
		for(int j=2; j<=i; j++)
			if(i%j==0){
				k*=j;
				continue;
			}
	return k;
}
int main(){
	int n;
	cin>>n;
	cout<<divs(n)<<endl;
}
