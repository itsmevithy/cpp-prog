#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void sort(int a[], int beg, int end){
	int mid=(beg+end)/2;
	int i, n1=mid-beg+1;
	int j, n2=end-mid;
	int larr[n1], rarr[n2];
	
	for(int i=0; i<n1; i++) larr[i]=a[beg+i];
	for(int j=0; j<n2; j++) rarr[j]=a[mid+1+j];
	
	i=0; j=0; int k=beg;
	
	while(i<n1 && j<n2) a[k++]=(larr[i]<rarr[j])?larr[i++]:rarr[j++];
	while(i<n1) a[k++]=larr[i++];
	while(j<n2) a[k++]=rarr[j++];
}

void merge(int a[], int beg, int end){
	if(beg<end){
		int mid=(beg+end)/2;
		merge(a, beg, mid);
		merge(a, mid+1, end);
		sort(a, beg, end);
	}

}

int main(){

	ifstream fi("randno.txt");
	int i=0, j, x, key, arr[10000];
	while(!fi.eof()&&i<10000){
		 fi>>x;
		 arr[i++]=x;
	}
	fi.close();
	
	ofstream fo;
	fo.open("ascending.txt");
	merge(arr, 0, 10000);
	for(i=0; i<10000; i++) fo<<arr[i]<<'\t';
	fo.close();
	
/*	fo.open("descending.txt");

	for(i=0; i<10000; i++) fo<<arr[i]<<'\t';
	fo.close();
*/
}
