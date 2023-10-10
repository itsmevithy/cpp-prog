#include<iostream>
using namespace std;
int factcount(long long x){
	int s=0;
	//cout<<"The factors of "<<x<<" are,\n";
	for(int i=1; i<=x; i++) if(x%i==0){
		//cout<<i<<", ";
		s++;
	}
	cout<<x<<"-"<<s<<endl;
	return s;
}
/*long long triangle(int n){
	long long s=0;
	while(n>0) s+=n--;
	return s;
}*/
int main(){
	long long x, y=0;
//	cout<<"Enter a number: ";
//	cin>>x;
	for(x=1; ;x++){
		y+=x;
		if(factcount(y)>=500){
			cout<<x<<endl;
			return 0;
		}
	}
}
