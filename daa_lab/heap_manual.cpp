#include<iostream>
#include<fstream>
using namespace std;

void swap(int &x, int&y){
	int temp=x;
	x=y;
	y=temp;
}

void print(int *arr, int n){
	int p=2; 
	//cout<<"The max heap is, \n";
	for(int i=0; i<n; i++){
		if(i+1==p){
			cout<<endl;
			p*=2;
		}
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}

void maxheapify(int *a, int i, int size){
	int l=2*i+1, r=2*i+1;
	int largest;
	largest=(l<size && a[l]>a[i])?l:i;
	largest=(r<size && a[r]>a[i])?r:largest;
	if(largest!=i){
		swap(a[i], a[largest]);
		maxheapify(a, largest, size);
	}
}

void heapsort(int* a, int size){
	for(int i=size/2-1; i>=0; i--)
		maxheapify(a, i, size);
	print(a, size);
	cout<<"The sorted array is, ";
	for(int i=size-1; i>0; i--){
		swap(a[0], a[i]);
		maxheapify(a, 0, i);
	}
	print(a, size);
}


int main(){

	int *arr, n;
	cout<<"Enter numbers of elements: ";
	cin>>n;
	arr=new int[n];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++) cin>>arr[i];

/*
	ifstream fi("randno.txt");
    int arr[10000], x;
    for(int i=0; !fi.eof()&&i<10000; arr[i++]=x){
        fi>>x; 
    }
    fi.close();

	heapsort(arr, 10000);

    ofstream fo;
    fo.open("ascending.txt");
	for(int i=0; i<10000; i++) fo<<arr[i]<<'\t';
    fo.close();
*/
	heapsort(arr, n);
//	print(arr, n);
}


