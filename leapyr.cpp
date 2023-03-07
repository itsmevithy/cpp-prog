#include<iostream>
using namespace std;
int main(){
	int y;
	cin>>y;
	cout<<y;
	if ((y%100==0)&&(y%400!=0)) cout<<" is NOT a LEAP YEAR";
	else if (y%4==0) cout<<" is a LEAP YEAR";
	else cout<<" is NOT a LEAP YEAR";
	cout<<endl;
}
