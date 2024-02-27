#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

void find_ss(int* arr, int n, int d, int i, string ca){
	if(d==0){
		cout<<"{ "<<ca<<" }\n";
		return;
	}
	for(int k=i; k<n; k++){
		if(arr[k]<=d) find_ss(arr, n, d-arr[k], k+1, (ca+to_string(arr[k])+", "));
		else return;
	}
}

int main(){
	int *arr, n, d;	
	cout<<"Enter size of set: ";
	cin>>n;
	arr=new int[n];
	cout<<"Enter elements: ";
	for(int i=0; i<n; i++) cin>>arr[i];
	cout<<"Enter sum: ";
	cin>>d;
	sort(arr, arr+n);
	find_ss(arr, n, d, 0, "");
}
