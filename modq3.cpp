#include<iostream>
#include<math.h>

using namespace std;

class Complex{
	private:
		float re, im;
	public:
		void get(){
			cout<<"Enter real part: ";
			cin>>re;
			cout<<"Enter img part: ";
			cin>>im;
		}
		void show(){
			cout<<re<<" + i"<<im;
		}
		float absolute_value(){
			return sqrt((re*re)+(im*im));
		}
};

int main(){
	Complex *arr;

	int i, j, choice=1, n=0;
	arr=new Complex[n];
	do{
		arr->get();
		cout<<"Enter 1 to continue entering values, any other key to stop..\n";
		cin>>choice;
		arr->show();
		cout<<endl<<arr->absolute_value()<<endl;
		n++;
		arr++;
	} while((choice==1)&&(n<10));

	for(i=0; i<n; i++) --arr;

//	cout<<"Before sorting, \n";
//	for(i=0; i<n; i++) arr[i].show();

	for(i=0; i<n; i++)
		for(j=0; j<(n-i-1); j++)
			if((arr[j].absolute_value())<(arr[j+1].absolute_value())){
				Complex temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}

	cout<<"Sorting over..\n"<<"Highest is, ";
	arr[0].show();
	cout<<" with value "<<arr[0].absolute_value()<<endl;
}
