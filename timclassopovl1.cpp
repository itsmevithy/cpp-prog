#include<iostream>
#include<iomanip>
using namespace std;

class Time{
	int d, h, m, s;
	public:
		Time(){
			d=0;
			h=0;
			m=0;
			s=0;
		}
		Time(int a, int b, int c, int d1){
			do{
				if(a<24) break;
				else{
		        		cout<<"Enter valid hr value (0-23) or enter same value again to convert: ";
					int i;
					cin>>i;
					if(i==a){
						d1+=(i/24);
						a%=24;
					}
					else a=i%24;
				}
			} while(true);
			do{
				if(b<60) break;
				else{
					cout<<"Enter valid min value (0-59) or enter same value again to convert: ";
					int i;
					cin>>i;
					if(i==b){
						a+=(i/60);
						b%=60;
					}
					else b=i%60;
				}
			} while(true);
			do{
				if(c<60) break;
				else{
					cout<<"Enter valid sec value (0-59) or enter same value again to convert: ";
					int i;
					cin>>i;
					if(i==c){
						b+=(i/60);
						c%=60;
					}
					else c=i%60;
				}
			} while(true);
			h=a; m=b; s=c; d=d1;
		}
		Time operator +(Time a){
			Time b;
			b.d=a.d+d;
			b.h=a.h+h;
			b.m=a.m+m;
			b.s=a.s+s;
			while((b.h>23)||(b.m>59)||(b.s>59)){
				if(b.h>23) {b.d+=1; b.h-=24;}
				else if(b.m>59) {b.m-=60; b.h+=1;}
				else if(b.s>59) {b.s-=60; b.m+=1;}
			}
			return b;
		}
		void display(){
			cout<<"["<<setw(2)<<setfill('0')<<h<<':'<<setw(2)<<setfill('0')<<m<<':'<<setw(2)<<setfill('0')<<s<<"] and "<<d<<" Days. ";
		}
};

int main(){
	int a=0, b=0, c=0, d1=0, choice, hmscheck=0;
	Time r;

	cout<<"Enter current time: ";
	cin>>a>>b>>c;
	Time p(a,b,c,d1);
	cout<<"Currently time is: "; p.display();

	cout<<"\nChoose duration format:(1-hours, 2-mins, 3-secs, 4-hms): ";
	do{
		cin>>choice;
		a=0; b=0; c=0;
		switch(choice){
			case 1:
				cout<<"Enter duration in hours: ";
				cin>>a;
				cout<<"After duration of "<<a<<" hours, ";
				d1+=(a/24);
				a%=24;
				break;
			case 2:
				cout<<"Enter duration in mins: ";
				cin>>b;
				cout<<"After duration of "<<b<<" mins, ";
				a+=(b/60); b%=60;
				d1+=(a/24);
				a%=24;
				break;
			case 3:
				cout<<"Enter duration in secs: ";
				cin>>c;
				cout<<"After duration of "<<c<<" secs, ";
				b+=(c/60); c%=60;
				a+=(b/60); b%=60;
				d1+=(a/24);
				a%=24;
				break;
			case 4:
				cout<<"Enter duration (HMS format): ";
				hmscheck=1;
				cin>>a>>b>>c;
				break;
			 default:
				cout<<"Enter valid input!!!\n";
				break;
		}
	}while((choice<1) || (choice>4));

	Time q(a, b, c, d1);

	if(hmscheck!=0){
		cout<<"After duration of "; q.display(); cout<<", ";}
	else{
		cout<<" (i.e, collectively "; q.display(); cout<<" ), ";}
	r=p+q;
	cout<<"the time will be ";
	r.display();
	cout<<endl;
}
