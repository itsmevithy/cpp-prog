#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void find_ss(vector<vector<int> >& a, int* arr, int n, int d, int cs, int i, vector<int> &ca){
	if(cs==d){
		a.push_back(ca);
		return;
	}
	for(int k=i; k<n; k++){
		if(cs+arr[k]<=d){
			ca.push_back(arr[k]);
			find_ss(a, arr, n, d, cs+arr[k], k+1, ca);
			ca.pop_back();
		}
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
	vector<vector<int> > a;
	vector<int> ca;
	sort(arr, arr+n);
	find_ss(a, arr, n, d, 0, 0, ca);
	for(int p=0; p<a.size(); p++){
		cout<<"{ ";
		for(int q=0; q<a[p].size(); q++, cout<<", ") cout<<a[p][q];
		cout<<"}"<<endl;
	}
}