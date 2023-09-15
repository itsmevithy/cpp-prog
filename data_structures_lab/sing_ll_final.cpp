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
    void createList(head *&list){
      list=new head();
      list->count=0;
      list->first=NULL;
    }
    bool insertNode(head *&list, node *&pPre, int dataIn){
      node *pNew=new node;
      if(pNew==NULL) return false;
      else{
        pNew->data=dataIn;
        pNew->link=NULL;
      }
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
    bool deleteNode(head *&list, node *&pPre, node *&pLoc, int dataOut){
      dataOut=pLoc->data;
      if(pPre==NULL) list->first=pLoc->link;
      else pPre->link=pLoc->link;
      delete pLoc;
      (list->count)--;
      return true;
    }
    bool searchList(head *&list, node *&pPre, node *&pLoc, int target){
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
    bool retrieveNode(head *&list, int key, int &dataOut){
      node *pPre, *pLoc;
      if(searchList(list, pPre, pLoc, key)){
        pLoc->data=dataOut;
        return true;
      }
      return false;
    }
    bool emptyList(head *&list){
      return (list->first==NULL)?true:false;
    }
    int listCount(head *&list){
      return list->count;
    }
    void getNext(head *&list){
      node *temp=list->first;
      while(temp!=NULL){
        cout<<temp->data<<", ";
        temp=temp->link;
      }
      cout<<endl;  
    }
    void destroyList(head *&list){
      node *temp=new node;
      while(!emptyList(list)){
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
  head *list;
  node *pPre=NULL, *pLoc=NULL;
  arr.createList(list);
  int x, choice;
  bool check;
  do{
    cout<<"Enter choice: [0-Exit, 1- Insert, 2-Delete, 3-Search, 4-Count, 5-Display, 6-Destroy]";
    cin>>choice;
    switch(choice){
      case 1:
        cout<<"Enter element to enter: ";
        cin>>x;
        if(arr.searchList(list, pPre, pLoc, x)) check=false;
        check=arr.insertNode(list, pPre, x);
        cout<<((check)?"Done":"Failed")<<endl;
        break;
      case 2:
        cout<<"Enter element to delete: ";
        cin>>x;
        if(!arr.searchList(list, pPre, pLoc, x)) check=false;
        check=arr.deleteNode(list, pPre, pLoc, x);
        cout<<((check)?"Done":"Failed")<<endl;
        break;
      case 3:
        cout<<"Enter element to search: ";
        cin>>x;
        cout<<((arr.retrieveNode(list, x, x))?"Found":"Not Found")<<endl;
        break;
      case 4:
        cout<<"The number of elements is "<<arr.listCount(list)<<endl;
        break;
      case 5:
        arr.getNext(list);
        break;
      case 6:
        arr.destroyList(list);
        break;        
      default:
        choice=0;
        break;
    }
  }while(choice);
}
