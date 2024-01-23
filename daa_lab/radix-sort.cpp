#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int* count_sort(int a[], int n, int exp){
	int maxn=0;
	int *res=new int[n];
	for(int i=0; i<n; i++) maxn=max(maxn, (a[i]/exp)%10);
	int ind[++maxn]={};
	for(int i=1; i<maxn; i++) ind[i]=0;
	for(int i=0; i<n; i++) ind[(a[i]/exp)%10]+=1;
	for(int i=1; i<maxn; i++) ind[i]+=ind[i-1];
	for(int i=n-1; i>=0; i--) res[(--ind[(a[i]/exp)%10])]=a[i];
	return res;
}

int * radix_sort(int a[], int n){
	int maxn=0, d;
	for(int i=0; i<n; i++) maxn=max(maxn, a[i]);
	for(d=0; maxn>0; maxn/=10, d++);
	for(int i=0; i<d; i++) a=count_sort(a, n, pow(10, i));
	return a;
}

int main(){

	int *arr, n;
	cout<<"Enter numbers of elements: ";
	cin>>n;
	arr=new int[n];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++) cin>>arr[i];
	int* a=radix_sort(arr, n);
	for(int i=0; i<n; i++) cout<<a[i]<<" ";
	cout<<endl;
/*	
	ifstream fi("randno.txt");
	int arr[10000], x;
	for(int i=0; !fi.eof()&&i<10000; arr[i++]=x){
        fi>>x; 
	}
	fi.close();

    ofstream fo;
    fo.open("ascending.txt");
	int* a=radix_sort(arr, 10000);
    for(int i=0; i<10000; i++) fo<<a[i]<<'\t';
    fo.close();
*/
}
