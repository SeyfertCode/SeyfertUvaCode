#include<bits/stdc++.h>
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
   int N;
   while(cin>>N){
      vector<int> s(40);
      int c=0, cont_zero=0,x;
      if(N==0)break;
      while(N!=0){
         x = N%2;
         if(x==1)cont_zero++;
         s[c] = x;
         c++;
         N /=2;      
      }
      cout<<"The parity of ";
      for(int i=c-1;i>-1;i--)cout<<s[i];
      cout<<" is "<<cont_zero<<" (mod 2)."<<endl;
   }
   return 0;
}
