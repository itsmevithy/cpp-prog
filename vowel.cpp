#include<iostream>
using namespace std;
int main(){
	char x, set[10]={'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	int i, chk=0;
	cout<<"Enter character: ";
	cin>>x;
	for(i=0; i<10; i++){
		if(x==set[i]){
			chk=1;
			break;
		}
	}
	if(chk==1) cout<<x<<" is a vowel.\n";
	else if ((x<'A') || (x>'z')) cout<<"Enter valid input!\n";
	else cout<<x<<" is a consonant\n";
	return 0;
}
