#include<iostream>
#include<iomanip>
using namespace std;

class Distance{
	int feet;
	float inches, metres;
	public:
		void getFI(){
			cin>>feet>>inches;
		}
		void getM(){
			cin>>metres;
		}
		void conv2US(){
			feet=metres*3.28084;
			inches=(metres*3.28084*12)-(feet*12);
		}
		void conv2M(){
			metres=(feet+inches/12)/3.28084;
		}
		void showM(){
			cout<<fixed<<setprecision(2)<<metres<<" metres.\n";
		}
		void showUS(){
			cout<<feet<<"\' "<<fixed<<setprecision(2)<<inches<<"\".\n";
		}
};

int main(){
	Distance d1, d2;
	cout<<"Enter feet and inches: ";
	d1.getFI(); d1.conv2M(); d1.showM();
	cout<<"Enter metres: ";
	d2.getM(); d2.conv2US(); d2.showUS();
}
