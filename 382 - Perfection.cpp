//BITECODE-ALBERT
#include<iostream>
#include<stdio.h>
/********************************************************************************/
using namespace std;
int perfection(int);
/********************************************************************************/
int main()
{
   int n;
   printf("PERFECTION OUTPUT\n");
   while(cin>>n){
      if(n==0)break;
      int sum = perfection(n);
      if(sum<n)printf("%5d  DEFICIENT\n",n);
      else if(sum==n)printf("%5d  PERFECT\n",n);
      else if(sum>n)printf("%5d  ABUNDANT\n",n);   
   }
   printf("END OF OUTPUT\n");

    return 0;
}
/********************************************************************************/
int perfection(int n)
{
   if(n==1)return 0;
   int sum = 0, i=0;
   for(i=2;i*i<n;i++){
      if(n%i==0)sum+=(i+n/i);   
   }
   if(i*i==n)sum+=i;
   return sum+1;
}
/********************************************************************************/
