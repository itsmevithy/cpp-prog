#include<iostream>
using namespace std;

inline void print(int n=10){
	for(;n>0; n--) cout<<'*';
	cout<<endl;
}

inline void print(char c, int n=10){
	for(;n>0; n--) cout<<c;
	cout<<endl;
}
int main(){
	int n;
	char c;
	cin>>c>>n;
	print(c, n); print(c); print(n); print();
}
