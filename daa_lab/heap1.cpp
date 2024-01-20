#include<iostream>
#include<fstream>
using namespace std;

class Heap{
	private:
		int *arr, lvl, n, temp;
	public:
		Heap(int *a, int size){
			n=size;
			arr=new int[n];
			for(int i=0; i<n; i++){
				arr[i]=a[i];
				//maxheap_up(i);
			}
			//heapify(0, n/2);
		}
		void heapify(int ind, int last){
			int n1=2*ind+1, n2=n1+1;
			int maxn=(n1<last && arr[n1]>arr[ind])?n1:ind;
			maxn=(n2<last && arr[n2]>arr[ind])?n2:ind;
			if(ind!=maxn){
				swap(arr[maxn], arr[ind]);
				heapify(maxn, n);
			}
		}
		void swap(int &x, int&y){
			int temp=x;
			x=y;
			y=temp;
		}
		
		void maxheap_down(int ind, int last){
			int n1=2*ind+1, n2=n1+1;
			while(ind<=last && (arr[ind]<arr[n1]||arr[ind]<arr[n2])){
				int maxn=(arr[n1]>arr[n2])?n1:n2;
				swap(arr[maxn], arr[ind]);
				ind=maxn;
				n1=2*ind+1, n2=n1+1;
			}
		}
		void maxheap_up(int ind){
			int par=(ind-1)/2;
			while(ind>0 && arr[ind]>arr[par]){
				swap(arr[ind], arr[par]);
				maxheap_up(par);
			}
		}
		int* sort(){
			//int* a=new int[n];
			for(int i=n/2-1; i>=0; i--) heapify(i, n);
			for(int i=0; i<n; i++){
				swap(arr[i], arr[0]);
				heapify(0, i);
			}
			//for(int i=0; i<n; i++) a[i]=arr[i];
			return arr;
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
			int *a=sort();
			cout<<"The sorted array is, ";
			for(int i=0; i<n; i++) cout<<a[i]<<" ";
			cout<<endl;
		}
};

int main(){
	/*int *arr, n;
	cout<<"Enter numbers of elements: ";
	cin>>n;
	arr=new int[n];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++) cin>>arr[i];*/
	ifstream fi("randno.txt");
    int arr[10000], x;
    for(int i=0; !fi.eof()&&i<10000; arr[i++]=x){
        fi>>x; 
    }
    fi.close();

	Heap h(arr, 10000);
	int *a=h.sort();

    ofstream fo;
    fo.open("ascending.txt");
	for(int i=0; i<10000; i++) fo<<a[i]<<'\t';
    fo.close();
}
