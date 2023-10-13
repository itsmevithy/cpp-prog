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

class CDLL{
	head *list;
	public:
		void createCDLL(){
			list=new head();
			list->count=0;
			list->first=NULL;
			list->last=NULL;
		}
		bool insertCDLL(int dataIn){
			node *pNew=new node;
			if(pNew==NULL) return false;
			node *pPre=NULL, *pSuc=NULL;
			if(searchList(pPre, pSuc, dataIn)) return false;
			pNew->data=dataIn;
			if(pPre==NULL){
				if(list->first==NULL){
					list->first=pNew;
					list->rear=pNew;
				}
				else{
					list->first->back=pNew;
					list->rear->fore=pNew;
				}
				pNew->back=list->last;
				pNew->fore=list->first;
				list->first=pNew;
			}
			else{
				pNew->fore=pSuc;
				pNew->back=pPre;
				pPre->fore=pNew;
				if(pSuc==list->first) list->last=pNew;
				pSuc->back=pNew;
			}
			(list->count)++;
			return true;
		}
		bool deleteCDLL(int target){
			node *pPre, *pLoc;
			if(!searchList(pPre, pLoc, target)) return false;
			if(cdllCount()==1){
				list->first=NULL;
				list->last=NULL;
			}
			else{
				if(pPre!=NULL){
					pPre->fore=pLoc->fore;
					pLoc->fore->back=pPre;
				}
				if(pLoc==list->last) list->last=pPre;
				else{
					list->first=pLoc->fore;
					pLoc->fore->back=pLoc->back;
					list->last->fore=pLoc->fore;
				}
			}
			delete pLoc;
			(list->count)--;
			return true;
		}
		bool searchList(node *&pPre, node *&pLoc, int target){
			pPre=NULL;
			pLoc=list->first;
			if(emptyCDLL()) return false;
			if(pLoc->data==target) return true;
			if(target<pLoc->data) return false;
			pPre=pLoc;
			pLoc=pLoc->fore;
			while((pLoc!=list->first)&&(target>(pLoc->data))){
				pPre=pLoc;
				pLoc=pLoc->fore;
			}
			if(pLoc==list->first) return false;
			else if(target==pLoc->data) return true;
			else return false;
		}
		bool emptyCDLL(){
			return (list->first==NULL)?true:false;
		}
		int cdllCount(){
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
			while(!emptyCDLL()){
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
	arr.createCDLL();
	int x, choice;
	do{
		cout<<"Enter choice: [0-Exit, 1- Insert, 2-Delete, 3-Search, 4-Count, 5-Display, 6-Destroy]";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter element to enter: ";
				cin>>x;
				cout<<((arr.insertCDLL(x))?"Done":"Failed")<<endl;
				break;
			case 2:
				cout<<"Enter element to delete: ";
				cin>>x;
				cout<<((arr.deleteCDLL(x))?"Done":"Failed")<<endl;
				break;
			case 3:
				cout<<"Enter element to search: ";
				cin>>x;
				node *pre, *loc;
				if(!arr.searchList(pre, loc, x)) break;
				cout<<"Found at "<<arr.pos_fow(x)<<" pos from beginning and "<<arr.pos_rev(x)<<" pos from end";
				break;
			case 4:
				cout<<"The number of elements is "<<arr.cdllCount()<<endl;
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
