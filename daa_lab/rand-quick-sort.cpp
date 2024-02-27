#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int count=0;

int partition(int a[], int p, int r){
	int x=a[r-1];
	int i=p-1;
	for(int j=p; j<r-1; j++){
		count++;
		if(a[j]<=x) swap(a[++i], a[j]);
	}
	swap(a[++i], a[r-1]);
	return i;
}

int rand_part(int a[], int p, int r){
	swap(a[r-1], a[rand()%r]);
	return partition(a, p, r);
}

void quick_sort(int a[], int p, int r){
	if(p>=r) return;
	int q=rand_part(a, p, r);
	quick_sort(a, p, q);
	quick_sort(a, q+1, r);
}

int main(){
/*
	int *arr, n;
	cout<<"Enter numbers of elements: ";
	cin>>n;
	arr=new int[n];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++) cin>>arr[i];
	quick_sort(arr, 0, n);
	for(int i=0; i<n; i++) cout<<arr[i]<<" ";
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
    quick_sort(arr, 0, limit);
    for(int i=0; i<limit; i++) fo<<arr[i]<<'\t';
    fo.close();
	cout<<count<<endl;
}
