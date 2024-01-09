#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){
	ofstream fo;
	int i=0;
	fo.open("randno.txt");
	while(fo&&i++<10000) fo<<(rand()%10000)<<'\t';
	fo.close();
	cout<<"Done\n";
}

