#include<iostream>
#include<limits>
using namespace std;
bool prime(unsigned long long int x){
	unsigned long long int i;
	for(i=2; i<x; i++) if(x%i==0) return false;
	return true;
}

int main(){
	unsigned long long int x;
	cin>>x;
	for(int i=1; i<x; i++) if(x%i==0) if(prime(i)){
		cout<<i<<", ";
	//	break;
	}
	//if(prime(11)) cout<<"prime";	
}
