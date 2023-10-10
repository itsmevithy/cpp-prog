#include<iostream>
#include<sstream>
#include<stdlib.h>
#include<string>
#include<string.h>
using namespace std;

string strconv(unsigned int a){
	stringstream temp;
	temp<<a;
	return temp.str();
}

string strconv(float a){
	stringstream temp;
	temp<<a;
	return temp.str();
}

class Book{
	protected:
		string title;
		unsigned int total_pages;
	public:
		Book():title("UNKNOWN"), total_pages(0){}
		Book(string a, unsigned int b):title(a), total_pages(b){
			cout<<"Values recorded!\n\n";
		}

		void display(int a){
			cout<<"Book "<<a<<":\n";
			cout<<"Name: "<<title<<endl;
			cout<<"No of pages: "<<((total_pages==0)?"UNKNOWN":strconv(total_pages))<<endl<<endl;
		}
};

class Ebook:public Book{
	private:
		float MBsize;
	public:
		Ebook():MBsize(0){}
		Ebook(string a, unsigned int b, float c):MBsize(c){
			title=a;
			total_pages=b;
			cout<<"Values recorded!\n\n";
		}

		void display(int a){
			cout<<"E";
			Book::display(a);
			cout<<"Size of the book: "<<((MBsize==0)?"UNKNOWN":(strconv(MBsize)+" Mb"))<<endl<<endl;
		}
};

int main(){
	unsigned int n;
	string t;
	float s;
	int i, p=0, num[2];
	cout<<"Enter number of ebooks: "; cin>>num[0];
	cout<<"Enter number of books: "; cin>>num[1];
	Ebook *e=(Ebook*)malloc(sizeof(Ebook)*num[0]);
	Book *b= (Book*)malloc(sizeof(Book)*num[1]);
	cout<<"Note: Type 0 for unknown values\n";
	for(;p<2;p++){		
		for(i=0; i<num[p]; i++){
			cout<<"Enter details for "<<((p==0)?"ebook ":"book ")<<(i+1)<<":-\n";
			cout<<"Title: ";
//			getline(cin, t);
			cin>>t;
			cout<<"No of pages: "; cin>>n;
			if(p==0){
				cout<<"Size occupied: ";
				cin>>s;
				e[i]= Ebook(t, n, s);
			}
			else if(p==1){
				b[i]= Book(t, n);
			}
		}
	}
	cout<<"Ebooks:-\n\n";
	for(i=0; i<num[0]; i++) e[i].display(i+1);

	cout<<"Books:-\n\n";
	for(i=0; i<num[1]; i++)b[i].display(i+1);
}
