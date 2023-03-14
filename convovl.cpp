#include<iostream>
using namespace std;

int* convert(float feet){
	int res[2], *p=&res;
	*p=(int)feet;
	*(p+1)=((feet-(feet/1))*12);
	cout<<(feet-(feet/1))<<endl;
	return p;
}

int* convert1(int inches){
	int res[2], *q=&res[0];
	*q=inches/12;
	*(q+1)=inches%12;
	return q;
}

int main(){
	float feet;
	int inches;
        cin>>feet>>inches;
	int *p=convert(feet), *q=convert1(inches);
	cout<<"Feet: "<<*p<<" feet "<<*++p<<" inches"<<endl;
	cout<<"Inches: "<<*q<<" feet "<<*++q<<" inches"<<endl;
}
