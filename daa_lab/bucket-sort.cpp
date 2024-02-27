#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include<fstream>
using namespace std;

int ccount=0;

struct node{
  float data;
  node *link;
};

struct head{
	int count;
	node *first=NULL;

	void push(float x){
		node *t=first, *pre=NULL, *temp=new node;
		temp->data=x;
		temp->link=NULL;
		while(t!=NULL && t->data<=x){
			ccount++;
			pre=t;
			t=t->link;
		} 
		if(!pre){
			temp->link=first;
			first=temp;
		}
		else{
			temp->link=pre->link;
			pre->link=temp;
		}
	}
};


void bucket_sort(float* &a, int n){
	head b[n];
	int key, i, j;
	for(int i=0; i<n; i++){
		b[int(n*a[i])].push(a[i]);
	}
	//for(int k=0; k<n; k++) sort(b[k].begin(), b[k].end(), comp);
	int ind=0;
	for(int i=0; i<n; i++) for(node* t=b[i].first; t; t=t->link) a[ind++]=t->data;//for(int j=0; j<b[i].size(); j++) a[ind++]=b[i][j];
}

int main(){
/*
	int n;
	float* arr;
	cout<<"Enter numbers of elements: ";
	cin>>n;
	arr=new float[n];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++) cin>>arr[i];
	bucket_sort(arr, n);
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
	float x, *arr=new float[limit];
	for(int i=0; !fi.eof()&&i<limit; arr[i++]=x/10000){
        fi>>x; 
	}
	fi.close();

	ofstream fo;
	fo.open(outps);
	bucket_sort(arr, limit);
	for(int i=0; i<limit; i++) fo<<arr[i]*10000<<'\t';
	fo.close();
	cout<<ccount<<endl;

}