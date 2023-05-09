#include<iostream>
#include<sstream>
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
		char title[100];
		unsigned int total_pages;
	public:
		Book():title("UNKNOWN"), total_pages(0){}
		Book(char a[100], unsigned int b):title(a), total_pages(b){
			cout<<"Parameterized constructor executed!\n";
		}

		void display(){
			cout<<"Name of the book: "<<title<<endl;
			cout<<"No of pages: "<<((total_pages==0)?"UNKNOWN":strconv(total_pages))<<endl;
		}
};

class Ebook:public Book{
	private:
		float MBsize;
	public:
		Ebook():MBsize(0){}
		Ebook(char a[100], unsigned int b, float c):MBsize(c){
			Book(a, b);
			cout<<"Parameterized constructor executed!\n";
		}

		void display(){
			Book::display();
			cout<<"Size of the book: "<<((MBsize==0)?"UNKNOWN":strconv(MBsize))<<endl;
		}
};

int main(){
	unsigned int n[2];
	char t[2][100];
	float s;
	int i;
	Ebook[] e= new Ebook[2];
	Book[] b= new Book[2];
	for(i=0; i<2; i++){
		cout<<"Enter details for "<<(i<1)?"ebook ":"book: ";
		cout<<"Title: "; cin>>t[i];
		cout<<"No of pages: "; cin>>n[i];
		if(i==0){
			cout<<"Size occupied: ";
			cin>>s;
			e[i]= new Ebook(t[i], n[i], s);
			b[i]= new Book(t[i], n[i]);
		}
		else if(i==1){
			b[i]= new Book();
			e[i]= new Ebook();
		}
	}
	for(i=0; i<2; i++){
		e[i].display();
		b[i].display();
	}
}
