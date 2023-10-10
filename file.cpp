#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

int main(){
	string str;
	cout<<"Enter name of file with extension: ";
	cin>>str;
	const char* name=str.c_str();
	ofstream fw;
	fw.open(name);
	if(fw) cout<<name<<" opened successfully in write mode. Start typing, enter x to exit.\n";
	while(fw){
		getline(cin, str);
		if(str=="x") break;
		fw<<str<<endl;
	}
	fw.close();

	ifstream fr;
	fr.open(name);
	cout<<"haha\n";
	while(getline(fr, str)) cout<<str<<endl;
	fr.close();
}
