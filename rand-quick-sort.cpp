#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int partition(int a[], int p, int r){
	int x=a[r-1];
	int i=p-1;
	for(int j=p; j<r-1; j++){
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
	int q=partition(a, p, r);
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
	
	ifstream fi("randno.txt");
	int arr[10000], x;
	for(int i=0; !fi.eof()&&i<10000; arr[i++]=x){
        fi>>x; 
	}
	fi.close();

    ofstream fo;
    fo.open("ascending.txt");
    quick_sort(arr, 0, 10000);
    for(int i=0; i<10000; i++) fo<<arr[i]<<'\t';
    fo.close();
}
