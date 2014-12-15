//Laxus-Seyfert
#include<iostream>

using namespace std;

int main(){
	int a,b;
	while(cin>>a>>b){
   	int sum = a;
      int r = 0;
      while(a/b>0){
      	r = a%b;
         a/=b;
         sum+=a;
         a+=r;
      }        
      cout<<sum<<endl;
   }
	return 0;
}
