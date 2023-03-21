#include<iostream>
using namespace std;

float avg(int s){
	static int i=1; static float n;
	n+=s;
	return (n/i++);
}

int main(){
	int x;
	char c;
	while(c!='x'){
		cout<<"Enter number: ";
		cin>>x;
		cout<<"The average is "<<avg(x)<<". Do you wish to continue?(yes-press any key/no-press x): ";
		cin>>c;
	}
}
