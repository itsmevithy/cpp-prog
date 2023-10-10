#include<iostream>
using namespace std;

inline void absval(int &x){
	x=(x>0)?x:(x*-1); cout<<x<<endl;
}

inline void absval(float &x){
	x=(x>0)?x:(x*-1); cout<<x<<endl;
}

inline void absval(double &x){
	x=(x>0)?x:(x*-1); cout<<x<<endl;
}

int main(){
	int a; float b; double c;
	cin>>a>>b>>c;
	absval(a); absval(b); absval(c);
}
