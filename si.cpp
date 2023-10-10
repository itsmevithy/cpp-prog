#include<iostream>
using namespace std;

inline int si(float p, float r=0.35, int n=10){
	return p*n*r;
}

int main(){
	int n; float r, p;
	cin>>p;
	cout<<si(p)<<endl;
	cin>>r;
	cout<<si(p,r)<<endl;
	cin>>n;
	cout<<si(p,r,n);
}
