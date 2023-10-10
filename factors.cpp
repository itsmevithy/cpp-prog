#include<iostream>
using namespace std;
int main(){
	int x, i ;
	cout<<"Enter a number: ";
	cin>>x;
	cout<<"The factors of "<<x<<" are,\n";
	for(i=1; i<=x; i++) if(x%i==0) cout<<i<<", ";
	return 0;
}
