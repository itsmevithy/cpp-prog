#include<iostream>
using namespace std;

class time{
	int h, m, s;
	public:
		/*time()
		{
			h=0;
			m=0;
			s=0;
		}*/
		time(int a, int b, int c)
		{
			h=a; 
			m=b; 
			s=c;
		}
		
		void display()
		{
			cout<<"The time is "<<h<<':'<<m<<':'<<s<<endl;
		}
};

int main()
{
	//int a, b, c;

	//cout<<"Enter time 1: ";
	//cin>>a>>b>>c;
	time t(10,20,30);

	//t.display();
}
