#include<iostream>
using namespace std;
int main(){
	int x, y=0;
	cout<<"ENTER NUMBER: ";
	cin>>x;
	cout<<"Before reversing: "<<x<<endl;
	while(x%10>0){
		y*=10;
		y+=x%10;
		x/=10;
	}
	cout<<"After reversing: "<<y<<endl;
	return 0;
}
