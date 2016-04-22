//LAXUS-Seyfert
#include<iostream>
#include<vector>
/********************************************************************************/
using namespace std;
/********************************************************************************/
int main()
{
   int N;
   cin>>N;
   for(int c =0;c<N;c++){
      int x;
      cin>>x;
      vector<int>v(x);
      for(int i=0;i<x;i++)cin>>v[i];
      int h=0,l=0;
      for(int i = 1;i<x;i++){
         if(v[i]>v[i-1])h++;
         else if(v[i]<v[i-1])l++;
      }
      cout<<"Case "<<c+1<<": "<<h<<" "<<l<<endl;
   }
    return 0;
}
/********************************************************************************/
