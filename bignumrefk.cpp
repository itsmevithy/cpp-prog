#include<iostream>
using namespace std;

int bignum(int n, int&arr){
	for(int i=0; i<n; i++) cout<<arr[i];
	return 0;
}

int main(){
	int i, arr[10];
	for(i=0; i<10; i++){
		cout<<"Enter element: ";
		cin>>arr[i];
	}
	cout<<"the greatest number in the array is "<<bignum(n, *arr)<<endl;
}
