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

Subarr max_sa_bf(int *a, int n, int &count){
	int l, h, sum, max_sum=-INT_MAX;
	for(int i=0; i<=n; i++){
		sum=0;
		for(int j=i; j<=n; j++){
			count++;
			sum+=a[j];
			if(sum>max_sum){
				max_sum=sum;
				l=i; h=j;
			}
		}
	}
	return Subarr(l, h, max_sum);
}

int main(){

	int n, count=0;
/*	cout<<"Enter numbers of elements: ";
	cin>>n;
	arr=new int[n];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++) cin>>arr[i];
*/
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
	Subarr r=max_sa_bf(arr, limit-1, count);
	//for(int i=0; i<n; i++) cout<<a[i]<<" ";
	cout<<"low: "<<r.low<<"\nhigh: "<<r.high<<"\nsum: "<<r.sum<<"\ncount: "<<count;
	cout<<endl;
}