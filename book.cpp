#include<iostream>
#include<sstream>
#include<string.h>
int p=0;
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
		int idno;
	public:
		Book():title("UNKNOWN"), total_pages(0), idno(++p){}
		Book(string a, unsigned int b, int c):title(a), total_pages(b), idno(c){			
			cout<<"Parameterized constructor executed for book with id no: "<<idno<<endl;
		}

		void display(){
			cout<<"Book "<<idno<<":-\nName of the book: "<<title<<endl;
			cout<<"No of pages: "<<((total_pages==0)?"UNKNOWN":strconv(total_pages))<<endl;
		}
};

class Ebook:public Book{
	private:
		float MBsize;
	public:
		Ebook():MBsize(0){}
		Ebook(string a, unsigned int b, float c, int d): MBsize(c){
			title=a;
			total_pages=b;
			idno=d;
			cout<<"Parameterized constructor executed for ebook with id no "<<idno<<endl;
		}
		void display(){
			cout<<"E";
			Book::display();
			cout<<"Size of the book: "<<((MBsize==0)?"UNKNOWN":(strconv(MBsize)+" Mb"))<<endl;
		}
};

int main(){
	unsigned int n;
	string t;
	float s;
	int i;
	Ebook* e= new Ebook[2];
	Book* b= new Book[2];
	for(i=0; i<2; i++){
		cout<<"Enter details for "<<((i==0)?"ebook ":"book: ");
		cout<<"Title: "; cin>>t;
		cout<<"No of pages: "; cin>>n;
		if(i==0){
			cout<<"Size occupied: ";
			cin>>s;
			e[i]= Ebook(t, n, s, ++p);
			//cout<<"Ebook process ends";
			b[i+1]= Book();
			//cout<<"atleast if ends!";
		}
		else{
			//cout<<"else raaa";
			b[i-1]=Book(t, n, ++p);
			e[i]=Ebook();
		}
	}
	//cout<<"loops ends ra dont wry";
	for(i=0; i<2; i++){
		e[i].display();
		b[i].display();
	}
}
