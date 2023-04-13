#include<iostream>
using namespace std;

class time{
	int h, m, s;
	public:
		time(){
			h=0;
			m=0;
			s=0;
		}
		time(int a, int b, int c){
			h=a; m=b; s=c;
		}
		void add(time a, time b){
			h=a.h+b.h;
			m=a.m+b.m;
			s=a.s+b.s;
			while((h>23)||(m>59)||(s>59)){
				if(h>23) h-=23;
				else if(m>59) {m-=60; h+=1;}
				else if(s>59) {s-=60; m+=1;}
			}
		}
		void display(){
			cout<<"The time is "<<h<<':'<<m<<':'<<s<<endl;
		}
};

int main(){
	int a, b, c;
	time r;
	cout<<"Enter time 1: ";
	cin>>a>>b>>c;
	do{
		if(a<23) break;
		else{
		        cout<<"Enter valid hr value (0-23): ";
			cin>>a;
		}
	} while(true);
	do{
		if(b<59) break;
		else{
			cout<<"Enter valid min value (0-59): ";
			cin>>b;
		}
	} while(true);
	do{
		if(c<59) break;
		else{
			cout<<"Enter valid sec value (0-59): ";
			cin>>c;
		}
	} while(true);
	time p(a,b,c);
	cout<<"Enter time 2: ";
	cin>>a>>b>>c;
	time q(a, b, c);
	r.add(p, q);
	r.display();
}
