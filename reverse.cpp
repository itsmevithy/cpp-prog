#include<iostream>
using namespace std;
int main(){
	int x, y=0, i;
	cout<<"ENTER NUMBER\n";
	cin>>x;
	cout<<x;
	while(x/10>0){
		y*=10;
		y+=x%10;
		x/=10;
	}
	cout<<y;
	return 0;
}
