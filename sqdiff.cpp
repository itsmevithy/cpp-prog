#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int i, n=0, s=0;
	for(i=0; i<=100; i++) s+=pow(i, 2);
	for(i=0; i<=100; i++) n+=i;
	n=pow(n, 2);
	cout<<(n-s)<<endl;
}
