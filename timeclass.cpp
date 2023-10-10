#include<iostream>
using namespace std;

class Time{
	int h, m, s;
	public:
		/*Time()
		{
			h=0;
			m=0;
			s=0;
		}*/
		Time(int a, int b, int c)
		{
			h=a; 
			m=b; 
			s=c;
		}
		
		void display()
		{
			cout<<"The Time is "<<h<<':'<<m<<':'<<s<<endl;
		}
};

int main()
{
	//int a, b, c;

	//cout<<"Enter Time 1: ";
	//cin>>a>>b>>c;
	Time t(10,20,30);

	//t.display();
}
