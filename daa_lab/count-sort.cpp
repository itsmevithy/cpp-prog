#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int count=0;

int* count_sort(int a[], int n){
	int maxn=0;
	int *res=new int[n];
	for(int i=0; i<n; i++) maxn=max(maxn, a[i]);
	int ind[++maxn]={};
	for(int i=1; i<maxn; i++, count++) ind[i]=0;
	for(int i=0; i<n; i++, count++) ind[a[i]]+=1;
	for(int i=1; i<maxn; i++, count++) ind[i]+=ind[i-1];
	for(int i=n-1; i>=0; i--, count++) res[(--ind[a[i]])]=a[i];
	return res;
}


int main(){
/*
	int *arr, n;
	cout<<"Enter numbers of elements: ";
	cin>>n;
	arr=new int[n];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++) cin>>arr[i];
	int* a=count_sort(arr, n);
	for(int i=0; i<n; i++) cout<<a[i]<<" ";
	cout<<endl;
*/	
	string inps, outps;
	int limit;
	cout<<"Enter limit: ";
	cin>>limit;
	cout<<"Enter input filename: ";
	cin>>inps;
	cout<<"Enter output filename: ";
	cin>>outps;
	
	ifstream fi(inps);
	int arr[limit], x;
	for(int i=0; !fi.eof()&&i<limit; arr[i++]=x){
        fi>>x; 
	}
	fi.close();

    ofstream fo;
    fo.open(outps);
	int* a=count_sort(arr, limit);
    for(int i=0; i<limit; i++) fo<<a[i]<<'\t';
    fo.close();

	cout<<count<<endl;

}
