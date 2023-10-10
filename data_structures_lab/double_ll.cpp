#include<iostream>
using namespace std;

struct node{
	int data;
	node *fore;
	node *back;
};

struct head{
	int count;
	node *first;
	node *last;
};

class DLL{
	head *list;
	public:
		void createList(){
			list=new head();
			list->count=0;
			list->first=NULL;
			list->last=NULL;
		}
		bool insertNode(int dataIn){
			node *pNew=new node;
			if(pNew==NULL) return false;
			pNew->data=dataIn;
			node *pPre=NULL, *pSuc=NULL;
			if(searchList(pPre, pSuc, dataIn)) return false;
			if(pPre==NULL){
				pNew->back=NULL;
				pNew->fore=list->first;
				list->first=pNew;
			}
			else{
				pNew->fore=pSuc;
				pNew->back=pPre;
				pPre->fore=pNew;
			}
			if(pSuc==NULL) list->last=pNew;
			else pSuc->back=pNew;
			(list->count)++;
			return true;
		}
		bool deleteNode(int target){
			node *pPre, *pLoc;
			if(!searchList(pPre, pLoc, target)) return false;
			if(pLoc->back!=NULL){
				pPre=pLoc->back;
				pPre->fore=pLoc->fore;
			}
			else list->first=pLoc->fore;
			if(pLoc->fore!=NULL){
				pPre->fore=pLoc->fore;
				pPre->fore->back=pLoc->back;
			}
			else list->last=pLoc->back;
			delete pLoc;
			(list->count)--;
			return true;
		}
		bool searchList(node *&pPre, node *&pLoc, int target){
			pPre=NULL;
			pLoc=list->first;
			while((pLoc!=NULL)&&(target>(pLoc->data))){
				pPre=pLoc;
				pLoc=pLoc->fore;
			}
			if(pLoc==NULL) return false;
			else if(target==pLoc->data) return true;
			else return false;
		}
		bool emptyList(){
			return (list->first==NULL)?true:false;
		}
		int listCount(){
			return list->count;
		}
		void display_fow(){
			node *temp=list->first;
			while(temp!=NULL){
				cout<<temp->data<<", ";
				temp=temp->fore;
			}
			cout<<endl;	
		}
		void display_rev(){
			node *temp=list->last;
			while(temp!=NULL){
				cout<<temp->data<<", ";
				temp=temp->back;
			}
			cout<<endl;	
		}
		void destroyList(){
			node *temp=new node;
			while(!emptyList()){
				temp=list->first;
				list->first=temp->fore;
				delete temp;
			}
			list->last=list->first;
			list->count=0;
			cout<<"Done\n";
		}
		int pos_fow(int target){
			node *pLoc=list->first;
			int pos;
			for(pos=1; (pLoc!=NULL && target>pLoc->data); pos++) pLoc=pLoc->fore;
			if(target==pLoc->data) return pos;
			else return -1;
		}
		int pos_rev(int target){
			node *pLoc=list->last;
			int pos;
			for(pos=1; (pLoc!=NULL && target<pLoc->data); pos++) pLoc=pLoc->back;
			if(target==pLoc->data) return pos;
			else return -1;
		}
};

int main(){
	DLL arr;
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
				node *pre, *loc;
				if(!arr.searchList(pre, loc, x)) break;
				cout<<"Found at "<<arr.pos_fow(x)<<" pos from beginning and "<<arr.pos_rev(x)<<" pos from end";
				break;
			case 4:
				cout<<"The number of elements is "<<arr.listCount()<<endl;
				break;
			case 5:
				cout<<"Forward:-\n";
				arr.display_fow();
				cout<<"Reverse:-\n";
				arr.display_rev();
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
