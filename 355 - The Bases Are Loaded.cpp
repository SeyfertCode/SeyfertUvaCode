//LAXUS-Seyfert
#include<iostream>
/********************************************************************************/
using namespace std;

typedef unsigned long long ull;
bool isValid(string,int);
string changeBase(string,int,int);
/********************************************************************************/
int main(){
   int b,N;
   string num;
   while(cin>>b>>N>>num){
      if(num=="0")cout<<num<<" base "<<b<<" = 0 "<<"base "<<N<<endl;
      else if(!isValid(num,b))cout<<num<<" is an illegal base "<<b<<" number"<<endl;
      else{  
         cout<<num<<" base "<<b<<" = ";
         string rpta = changeBase(num,b,N);
         for(int i=rpta.size()-1;i>=0;i--)cout<<rpta[i];
         cout<<" base "<<N<<endl;
      }   
   }
   return 0;
}
/********************************************************************************/
bool isValid(string n,int b){
   for(int i=0;i<n.size();i++){
      switch(n[i]){
         case 'A':
            n[i] = 58;
            break;
         case 'B':
            n[i] = 59;
            break;
         case 'C':
            n[i] = 60;
            break;
         case 'D':
            n[i] = 61;
            break;
         case 'E':
            n[i] = 62;
            break;
         case 'F':
            n[i] = 63;
            break;   
      }
      if(n[i]-48>=b)return false;   
   }  
   return true;
}
/********************************************************************************/
string changeBase(string num,int b,int n){
   ull aux = 0;
   ull pow=1;
   for(int i=num.size()-1;i>=0;i--){
      switch(num[i]){
         case 'A':
            num[i] = 58;
            break;
         case 'B':
            num[i] = 59;
            break;
         case 'C':
            num[i] = 60;
            break;
         case 'D':
            num[i] = 61;
            break;
         case 'E':
            num[i] = 62;
            break;
         case 'F':
            num[i] = 63;
            break;   
      }
      aux +=(num[i]-48)*pow;
      pow *=b;   
   }
   string result = "";
   while(aux>0){
      int p = aux%n;
      if(p>=10)result += p + 55;
      else result += p+48;
      aux/=n;    
   }
   if(result == "")return "0";
   return result;
}
/********************************************************************************/
