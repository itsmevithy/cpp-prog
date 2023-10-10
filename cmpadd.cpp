#include<iostream>
using namespace std;

typedef struct{
	float x, y;
}complex;

int main(){
	int i, n;
	cout<<"Enter number of inputs: ";
	cin>>n;
	complex a[n];
	float resr, resi;
	for(i=0; i<n; i++){
		cout<<"Enter real and img part of number "<<i+1<<": ";
		cin>>a[i].x>>a[i].y;
		resr+=a[i].x;
		resi+=a[i].y;
	}
	for(i=0; i<n; i++){
		cout<<'('<<a[i].x<<"+j"<<a[i].y<<')';
		if (i!=n-1) cout<<'+';
	}
	cout<<"="<<resr<<"+j"<<resi<<endl;
	return 0;
}
