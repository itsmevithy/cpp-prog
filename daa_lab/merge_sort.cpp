#include<iostream>
#include<fstream>
#include<climits>
using namespace std;

void sort(long *a, long beg, long end, long &count){
	long mid=(beg+end)/2;
	long i, n1=mid-beg+1;
	long j, n2=end-mid;
	long larr[n1+1], rarr[n2+1];
	larr[n1]=rarr[n2]=INT_MAX;
	for(long i=0; i<n1; i++) larr[i]=a[beg+i];
	for(long j=0; j<n2; j++) rarr[j]=a[mid+1+j];
	
	i=0; j=0; 
	
	for(long k=beg; k<=end; count++) a[k++]=(larr[i]<=rarr[j])?larr[i++]:rarr[j++];
}

void merge(long *a, long beg, long end, long &count){
	if(beg<end){
		long mid=(beg+end)/2;
		merge(a, beg, mid, count);
		merge(a, mid+1, end, count);
		sort(a, beg, end, count);
	}

}

int main(){
	string inps, outps;
	long limit;
	cout<<"Enter limit: ";
	cin>>limit;
	cout<<"Enter input filename: ";
	cin>>inps;
	cout<<"Enter output filename: ";
	cin>>outps;
	ifstream fi(inps);
	long i=0, j, x, key, arr[limit], count=0;
	for(long i=0; !fi.eof()&&i<limit; arr[i++]=x){
        fi>>x; 
	}
	fi.close();
	
	ofstream fo;
	fo.open(outps);
	merge(arr, 0, limit-1, count);
	for(i=0; i<limit; i++) fo<<arr[i]<<'\t';
	fo.close();
	cout<<count<<endl;
}
