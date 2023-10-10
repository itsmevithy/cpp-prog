#include<iostream>
using namespace std;

int *convert(float feet){
	static int res[2];
	res[0]=(int)feet;
	res[1]=((feet-int(feet))*12);
	return res;
}

int *convert(int inches){
	static int res[2];
	res[0]=inches/12;
	res[1]=inches%12;
	return res;
}

int main(){
	float feet;
	int inches;
        cin>>feet>>inches;
	int *p=convert(feet), *q=convert(inches);
	cout<<"Feet: "<<*p<<" feet "<<*(p+1)<<" inches\n";
	cout<<"Inches: "<<*q<<" feet "<<*(q+1)<<" inches\n";
}
