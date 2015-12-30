#include<bits/stdc++.h>

#define _ std::
#define s(v) scanf("%d",&v)
#define f(i,j) for(int i=0;i<j;++i)
#define read(t) freopen(t,"r",stdin)
#define write(t) freopen(t,"w",stdout);
using namespace std;
/********************************************************************************/
//typedef unsigned long long int ulli;
//typedef long long int lli;
//typedef unsigned long long ull;
/********************************************************************************/
int main(){
	std::ios::sync_with_stdio(false);
   int f,c,pos_f,pos_c;
   while(cin>>f>>c>>pos_c){
      if(f==0&&c==0&&pos_c==0)break;
      int steps=0;
      char M[f][c];
      for(int i=0;i<f;++i){for(int j=0;j<c;++j)cin>>M[i][j];}
      int V[f][c];
      memset(V,-1,sizeof(V));
      pos_c-=1;
      pos_f=0;
      while(true){
         V[pos_f][pos_c]=steps++; 
         if(M[pos_f][pos_c]== 'N' )pos_f-=1;
         else if(M[pos_f][pos_c]== 'S' )pos_f+=1;
         else if(M[pos_f][pos_c]== 'W' )pos_c-=1;
         else if(M[pos_f][pos_c]== 'E' )pos_c+=1;
         
         if(pos_f<0||pos_f>=f||pos_c<0||pos_c>=c){
            cout<<steps<<" step(s) to exit"<<endl;
            break;   
         }
         else if(V[pos_f][pos_c]!=-1){
            cout<<V[pos_f][pos_c]<<" step(s) before a loop of "<<steps-V[pos_f][pos_c]<<" step(s)"<<endl; 
            break;
         }    
      } 
   }
   return 0;
}
/********************************************************************************/
