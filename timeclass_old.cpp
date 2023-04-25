#include<iostream>
using namespace std;

class Time{
	int h, m, s;
	public:
		Time(){
			h=0;
			m=0;
			s=0;
		}
		Time(int a, int b, int c){
			h=a; m=b; s=c;
		}
		void add(Time a, Time b){
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
			cout<<"The Time is "<<h<<':'<<m<<':'<<s<<endl;
		}
};

int main(){
	int a, b, c;
//	Time a;
	cout<<"Enter Time 1: ";
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
	Time t(a,b,c);
//	cout<<"Enter Time 2: ";
//	cin>>h>>m>>s;
//	Time c(h, m, s);
//	a.add(b, c);
	t.display();
}
