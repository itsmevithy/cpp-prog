#include<iostream>
using namespace std;

int main(){
	int n;
	long long k=1;
	cin>>n;
	for(;n>0; n--) k*=n;
	cout<<k<<endl;
}
