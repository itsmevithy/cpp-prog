#include<iostream>
#include<fstream>
using namespace std;

int count=0;

class Heap{
	public:
		int *arr, n;
		
		Heap(int *a, int size){
			n=size;
			arr=new int[n];
			for(int i=0; i<n; i++) arr[i]=a[i];
			for(int i=(n/2); i>=0; i--) heapify(i, n);
		}
		void heapify(int ind, int last){
			count++;
			int n1=2*ind+1, n2=n1+1;
			int maxn=(n1<last && arr[n1]>arr[ind])?n1:ind;
			maxn=(n2<last && arr[n2]>arr[maxn])?n2:maxn;
			if(ind!=maxn){
				swap(arr[maxn], arr[ind]);
				heapify(maxn, last);
			}
		}
		void swap(int &x, int&y){
			int temp=x;
			x=y;
			y=temp;
		}
		
		void sort(){
			for(int i=n-1; i>0; i--){
				swap(arr[i], arr[0]);
				heapify(0, i);
			}
		}
		void print(){
			int p=2; 
			cout<<"The max heap is, \n";
			for(int i=0; i<n; i++){
				if(i+1==p){
					cout<<endl;
					p*=2;
				}
				cout<<arr[i]<<"\t";
			}
			cout<<endl;
			sort();
			cout<<"The sorted array is, ";
			for(int i=0; i<n; i++) cout<<arr[i]<<" ";
			cout<<endl;
		}
};

int main(){
/*
	int *arr, n;
	cout<<"Enter numbers of elements: ";
	cin>>n;
	arr=new int[n];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++) cin>>arr[i];
	Heap h(arr, n);
	h.print();
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

	Heap h(arr, limit);
//	h.print();

    ofstream fo;
    fo.open(outps);
    h.sort();
    for(int i=0; i<limit; i++) fo<<h.arr[i]<<'\t';
    fo.close();
	cout<<count<<endl;
}
