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
		bool insertCDLL(int dataIn, int dataPre){
			node *pNew=new node;
			if(pNew==NULL) return false;
			node *pPre=NULL, *pSuc=NULL;
			if(searchList(pPre, pSuc, dataIn)){
				cout<<"DataIn element already exists..";
				return false;
			}
			if(!searchList(pPre, pSuc, dataPre)){
				cout<<"The element "<<dataPre<<" was not found.\n";
				if(emptyCDLL()) cout<<"Empty list found. Inserting "<<dataIn<<" at beginning.\n";
				else return false;
			}
			pNew->data=dataIn;
			if(pPre==NULL){
				if(list->first==NULL){
					list->first=pNew;
					list->last=pNew;
				}
				else{
					list->first->back=pNew;
					list->last->fore=pNew;
				}
				pNew->back=list->last;
				pNew->fore=list->first;
				list->first=pNew;
			}
			else{
				pNew->fore=pSuc;
				pNew->back=pPre;
				pPre->fore=pNew;
				if(pSuc==list->first) list->last->fore=pNew;
				pSuc->back=pNew;
			}
			(list->count)++;
			cout<<dataIn<<" inserted before "<<dataPre<<endl;
			cout<<"First: "<<list->first->data<<", Last: "<<list->last->data<<endl;
			return true;
		}
		bool deleteCDLL(int target){
			node *pPre, *pLoc;
			if(searchList(pPre, pLoc, target)){
				if(cdllCount()==1){
					list->first=NULL;
					list->last=NULL;
				}
				else{
					if(pPre!=NULL){
						pPre->fore=pLoc->fore;
						pLoc->fore->back=pPre;
						if(pLoc==list->last) list->last=pPre;
					}
					else{
						list->first=pLoc->fore;
						pLoc->fore->back=pLoc->back;
						list->last->fore=pLoc->fore;
					}
				}
				delete pLoc;
				(list->count)--;
			}
			else{
				cout<<"Data not found\n";
				return false;}
			return true;
		}
		bool searchList(node *&pPre, node *&pLoc, int target){
			pPre=NULL;
			pLoc=list->first;
			if(emptyCDLL()) return false;
			if(pLoc->data==target) return true;
			do{
				pPre=pLoc;
				pLoc=pLoc->fore;
			}while((pLoc!=list->first)&&(target!=pLoc->data));
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
			if(emptyCDLL()){
				cout<<"Empty list!!\n";
				return;
			}
			do{
				cout<<temp->data<<", ";
				temp=temp->fore;
			}while(temp!=list->first);
			cout<<endl;	
		}
		void display_rev(){
			node *temp=list->last;
			if(emptyCDLL()){
				cout<<"Empty list!!\n";
				return;
			}
			do{
				cout<<temp->data<<", ";
				temp=temp->back;
			}while(temp!=list->last);
			cout<<endl;	
		}
		void destroyList(){
			node *temp=new node;
			while(list->count!=0){
				deleteCDLL(list->first->data);
			}
			list->last=list->first;
			list->count=0;
			cout<<"Done\n";
		}
		int pos_fow(int target){
			node *pLoc=list->first;
			int pos=1;
			if(target==pLoc->data) return pos;
			do{
				pLoc=pLoc->fore;
				pos++;
			}while((pLoc!=list->first)&&(target!=pLoc->data));
			if(target==pLoc->data) return pos;
			else return -1;
		}
		int pos_rev(int target){
			node *pLoc=list->last;
			int pos=1;
			if(target==pLoc->data) return pos;
			do{
				pLoc=pLoc->back;
				pos++;
			}while((pLoc!=list->last)&&(target!=pLoc->data));
			if(target==pLoc->data) return pos;
			else return -1;
		}
};

int main(){
	CDLL arr;
	arr.createCDLL();
	int x, y, choice;
	do{
		cout<<"Enter choice: [0-Exit, 1- Insert, 2-Delete, 3-Search, 4-Count, 5-Display, 6-Destroy]";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter element to enter, and element to be placed after it: ";
				cin>>x>>y;
				cout<<((arr.insertCDLL(x, y))?"Done":"Failed")<<endl;
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
				if(!arr.searchList(pre, loc, x)){
					cout<<"Not found!\n";
					break;}
				cout<<"Found at "<<arr.pos_fow(x)<<" pos from beginning and "<<arr.pos_rev(x)<<" pos from end\n";
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
