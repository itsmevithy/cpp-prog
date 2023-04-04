#include<iostream>
using namespace std;

int const N=10;

float avg(float a[N+1]){
	int i;
	float av=0.0;
	for(i=0; i<N; i++) av+=a[i]/N;
	return av;
}

int main(){
	float a[N+1];
	int i;
	for(i=0; i<N; i++) cin>>a[i];
	a[N]=avg(a);
	cout<<a[N];
}
