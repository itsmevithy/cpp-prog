#include<iostream>
#include<math.h>
using namespace std;

bool prime(long x){
	for (int i=2; i<=sqrt(x); i++) if(x%i==0) return false;
	return true;
}

int main(){
	long long sum=0;
	for(long i=2; i<2000000; i++)
		if(prime(i)){
			cout<<i<<endl;
			sum+=i;
		}
	cout<<sum<<endl;
}
