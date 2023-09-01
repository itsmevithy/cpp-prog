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
	public:
		bool isEmpty(head* list){
			return (list->first==NULL)?true:false;
		}
		void createList(head *list){
			list=new head();
			list->count=0;
			list->first=NULL;
		}
		bool insertNode(head *list, node *pPre, int dataIn){
			node* pNew=new node();
			pNew->data=dataIn;
			if(pPre==NULL){
				pNew->link=list->first;
				list->first=pNew;
				(list->count)++;
			}
			else{
				pNew->link=pPre->link;
				pPre->link=pNew;
				(list->count)++;
			}
			return true;
		}
		void deleteNode(head* list, node *pPre, node* pLoc, int &dataOut){
			dataOut=pLoc->data;
			if(pPre==NULL) list->first=pLoc->link;
			else pPre->link=pLoc->link;
			delete pLoc;
			(list->count)--;
		}
		bool searchList(head* list, node *pPre, node *pLoc, int target){
			pPre=NULL;
			pLoc=list->first;
			while((pLoc!=NULL)&&(target>pLoc->data)){
				pPre=pLoc;
				pLoc=pLoc->link;
			}
			if(pLoc==NULL) return false;
			else
				if(target==pLoc->data) return true;
				else return false;
		}
		bool retrieveNode(head *list, int key, int&dataOut){
			node *pPre, *pLoc;
			if(searchList(list, pPre, pLoc, key)){
				pLoc->data=dataOut;
				return true;
			}
		}
		bool emptyList(head *list){
			return (list->count==0)?true:false;
		}
		int listCount(head* list){
			return list->count;
		}
		bool getNext(head *list, fromWhere, int &dataOut){
			if(isEmpty(list)) return false;
				
		}
		void destroyList(head *list){
			while(list->count>0){
				list->first=list->first->link;
			}
			list->count=0;
		}
};

int main(){}
