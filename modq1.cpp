#include<iostream>
using namespace std;

class Fuel{
  private:
    float ptl, dsl, amt;
  public:
    Fuel():ptl(100), dsl(100), amt(0){}
    void showbal(){
      cout<<"The available balance is, \n";
      cout<<"Petrol: "<<ptl<<" litres.\n";
      cout<<"Diesel: "<<dsl<<" litres.\n";
      cout<<"Balance: "<<amt<<" rupees.\n";
    }
    void pd(char ch){
      float a;
      float& b=(ch=='p')?ptl:dsl;
      int mul=(ch=='p')?100:95;
      cout<<"Enter litres of "<<((ch=='p')?"petrol":"diesel")<<" needed: ";
      cin>>a;
      cout<<"Generating request..";
      if((b-a)>0){
        cout<<"Fuel available, request accepted!\nAccepting payment..\nFilling fuel..\n";
        b-=a;
        amt+=(a*mul);
        cout<<"Done!!\n";
      }
      else cout<<"Insufficient fuel stock, request rejected!\n";
      showbal();
    }
    void f(){
      float preq, dreq;
      cout<<"Enter req litres of petrol and diesel to refill: ";
      cin>>preq>>dreq;
      float temp=(preq*100+dreq*95);
      if (temp>amt) cout<<"Insufficient balance, cannot refill!!\n";
      else{
        ptl+=preq;
        dsl+=dreq;
        amt-=temp;
      }
      showbal();
    }  
};

Fuel bunk;

static void inp(){
  char ch;
  int chk;
  do{
    cout<<"Enter choice (p/d/f): ";
    cin>>ch;
    if((ch=='p')||(ch=='d')||(ch=='f')) chk=1;
  }while(chk!=1);
  if((ch=='p')||(ch=='d')) bunk.pd(ch);
  else bunk.f();
  cout<<"To continue, press 1: ";
}

int main(){
  int chk;
  do{
    inp();
    cin>>chk;
  }while(chk==1);
}
