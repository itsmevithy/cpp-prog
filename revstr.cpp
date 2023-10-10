#include<iostream>
using namespace std;
int main(){
	char s[100], t[100];
	int i, n;
	cout<<"Enter sting: ";
	cin>>s;
	for(i=0; s[i]!='\0'; i++);
	n=i;
	for(i=0; i<n; i++) t[i]=s[n-i-1];
	cout<<"Reversed string: "<<t<<endl;
}
