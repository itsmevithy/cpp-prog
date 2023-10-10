#include<iostream>
using namespace std;

bool is_palin(int x){
	int y=0;
	for(int t=x; t>0; t/=10) y=(y*10)+(t%10);
	return (x==y)?true:false;
}
bool factors(int x, int &a, int &b){
	for(int i=x; i>0; i--)
		if((x%i)==0)
			if((i>99)&&(i<1000)&&((x/i)>99)&&((x/i)<1000)){
				a=i;
				b=x/i;
				return true;
			}
	return false;
}
int main(){
	int a, b;
	for(int x=(999*999); x>0; x--)
		if(is_palin(x))
			if(factors(x, a, b)){
			cout<<"The numbers are "<<b<<" and "<<a<<", giving product "<<x<<endl;
			break;
			}
}

