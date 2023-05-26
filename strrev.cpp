#include<iostream>
#include<string>
using namespace std;

char* rev(char *a){
	int i, n;
	for(i=0; a[i]!='\0'; i++) n=i;
	char t[n+1], *p;
	p=&t[0]; 
	for(i=0; i<n+1; i++) *(p++)=a[n-i];
//	cout<<"test no "<<n<<"text "<<t;
	return p;
}

int main(){
	int i;
	char x[100], *p;
	cout<<"Enter string: ";
	cin>>x;
	cout<<"Reversed string is, ";
	p=rev(x);
	for(i=0;i<10;i++) cout<<*p++;
	cout<<endl;
}
