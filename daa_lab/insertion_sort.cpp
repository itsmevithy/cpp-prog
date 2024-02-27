#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

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
	for(j=1; j<10000; j++, arr[i+1]=key)
		for(i=j-1, key=arr[j]; i>=0&&arr[i]>key; i--) arr[i+1]=arr[i];
	for(i=0; i<10000; i++) fo<<arr[i]<<'\t';
	fo.close();
	
	fo.open("descending.txt");
	for(j=1; j<10000; j++, arr[i+1]=key)
		for(i=j-1, key=arr[j]; i>=0&&arr[i]<key; i--) arr[i+1]=arr[i];
	for(i=0; i<10000; i++) fo<<arr[i]<<'\t';
	fo.close();
}
