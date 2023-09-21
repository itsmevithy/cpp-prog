#include<iostream>
using namespace std;

struct node{
	int data;
	node *link;
};

struct head{
	int count;
	node *first;
};

class SLL{
	head *list;
	public:
		void createList(){
			list=new head();
			list->count=0;
			list->first=NULL;
		}
		bool insertNode(int dataIn){
			node *pNew=new node;
			if(pNew==NULL) return false;
			else{
				pNew->data=dataIn;
				pNew->link=NULL;
			}
			node *pPre=NULL, *pLoc=NULL;
			if(searchList(pPre, pLoc, dataIn)) return false;
			if(pPre==NULL){
				pNew->link=list->first;
				list->first=pNew;
			}
			else{
				pNew->link=pPre->link;
				pPre->link=pNew;
			}
			(list->count)++;
			return true;
		}
		bool deleteNode(int target){
			node *pPre, *pLoc;
			if(!searchList(pPre, pLoc, target)) return false;
			if(pPre==NULL) list->first=pLoc->link;
			else pPre->link=pLoc->link;
			delete pLoc;
			(list->count)--;
			return true;
		}
		bool searchList(node *&pPre, node *&pLoc, int target){
			pPre=NULL;
			pLoc=list->first;
			while((pLoc!=NULL)&&(target>(pLoc->data))){
				pPre=pLoc;
				pLoc=pLoc->link;
			}
			if(pLoc==NULL) return false;
			else if(target==pLoc->data) return true;
			else return false;
		}
		bool retrieveNode(int key, int&dataOut){
			node *pPre, *pLoc;
			if(searchList(pPre, pLoc, key)){
				pLoc->data=dataOut;
				return true;
			}
			return false;
		}
		bool emptyList(){
			return (list->first==NULL)?true:false;
		}
		int listCount(){
			return list->count;
		}
		void getNext(){
			node *temp=list->first;
			while(temp!=NULL){
				cout<<temp->data<<", ";
				temp=temp->link;
			}
			cout<<endl;	
		}
		void destroyList(){
			node *temp=new node;
			while(!emptyList()){
				temp=list->first;
				list->first=list->first->link;
				delete temp;
			}
			list->count=0;
			cout<<"Done\n";
		}
};

int main(){
	SLL arr;
	arr.createList();
	int x, choice;
	do{
		cout<<"Enter choice: [0-Exit, 1- Insert, 2-Delete, 3-Search, 4-Count, 5-Display, 6-Destroy]";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter element to enter: ";
				cin>>x;
				cout<<((arr.insertNode(x))?"Done":"Failed")<<endl;
				break;
			case 2:
				cout<<"Enter element to delete: ";
				cin>>x;
				cout<<((arr.deleteNode(x))?"Done":"Failed")<<endl;
				break;
			case 3:
				cout<<"Enter element to search: ";
				cin>>x;
				cout<<((arr.retrieveNode(x, x))?"Found":"Not Found")<<endl;
				break;
			case 4:
				cout<<"The number of elements is "<<arr.listCount()<<endl;
				break;
			case 5:
				arr.getNext();
				break;
			case 6:
				arr.destroyList();
				break;				
			default:
				choice=0;
				break;
		}
	}while(choice);
}
