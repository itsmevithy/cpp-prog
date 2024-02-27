#include<iostream>
#include<climits>
#include<fstream>
using namespace std;

struct Subarr{
	int low, high, sum;
	Subarr(int l, int h, int s){
		low=l; high=h; sum=s;
	}
};

Subarr find_max_cross_sa(int* a,  int low, int mid, int high, int &count){
	int rsum=-INT_MAX, lsum=rsum;
	int max_right, max_left, sum=0;
	for(int i=mid; i>=low; i--){
		count++;
		sum+=a[i];
		if(sum>lsum){
			lsum=sum;
			max_left=i;
		}
	}
	sum=0;
	for(int i=mid+1; i<=high; i++){
		count++;
		sum+=a[i];
		if(sum>rsum){
			rsum=sum;
			max_right=i;
		}
	}
	return Subarr(max_left, max_right, lsum+rsum);
}

Subarr find_max_sa(int* a, int low, int high, int &count){
	if(low==high) return Subarr(low, high, a[low]);
	int mid=(low+high)/2;
	Subarr l=find_max_sa(a, low, mid, count);
	Subarr r=find_max_sa(a, mid+1, high, count);
	Subarr c=find_max_cross_sa(a, low, mid, high, count);
	if(l.sum>=r.sum && l.sum>=c.sum) return l;
	if(r.sum>=l.sum && r.sum>=c.sum) return r;
	return c;
}

int main(){

	int n, count=0;
    string inps;
	int limit;
	cout<<"Enter limit: ";
	cin>>limit;
	cout<<"Enter input filename: ";
	cin>>inps;
	
	ifstream fi(inps);
	int x, *arr=new int[limit];
	for(int i=0; !fi.eof()&&i<limit; arr[i++]=x){
        fi>>x; 
	}
	fi.close();
/*
    cout<<"Enter numbers of elements: ";
	cin>>n;
	arr=new int[n];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++) cin>>arr[i];
*/
	Subarr r=find_max_sa(arr, 0, limit-1, count);
	//for(int i=0; i<n; i++) cout<<a[i]<<" ";
	cout<<"low: "<<r.low<<"\nhigh: "<<r.high<<"\nsum: "<<r.sum<<"\ncount: "<<count;
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
	count_sort(arr, 10000);
    for(int i=0; i<10000; i++) fo<<a[i]<<'\t';
    fo.close();
*/
}