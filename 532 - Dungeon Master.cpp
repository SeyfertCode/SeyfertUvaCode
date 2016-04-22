#include<iostream>
#include<queue>
#define MAX 32
using namespace std;
int d[MAX][MAX][MAX];
char m[MAX][MAX][MAX];
int p,f,c;
int p1,f1,c1,p2,f2,c2;
int dp[]={0,0,0,0,1,-1};
int df[]={0,0,1,-1,0,0};
int dc[]={1,-1,0,0,0,0};
struct Punto{
   int p;
   int f;
   int c;
};
void bfs(){
   queue<Punto> Q;
   Punto P1;P1.p=p1;P1.f=f1;P1.c=c1;
   Punto P2;P2.p=p2;P2.f=f2;P2.c=c2;
   Q.push(P1);
   d[p1][f1][c1] = 0;
   while(!Q.empty()){
      Punto head = Q.front();
      Q.pop();
      for(int i = 0; i<6;++i){
         Punto aux;
         aux.p=head.p+dp[i];
         aux.f=head.f+df[i]; 
         aux.c=head.c+dc[i];
         if(aux.p>=0&&aux.p<p&&aux.f>=0&&aux.f<f&&aux.c>=0&&aux.c<c){
            if(aux.p==P2.p&&aux.f==P2.f&&aux.c==P2.c){
               d[aux.p][aux.f][aux.c] = d[head.p][head.f][head.c]+1;
               return;   
            }
            if(m[aux.p][aux.f][aux.c]!='#'){
               if(d[aux.p][aux.f][aux.c]==-1){
                  Q.push(aux);
                  d[aux.p][aux.f][aux.c] = d[head.p][head.f][head.c]+1; 
               }      
            }  
         }
      }   
   }       
}
int main(){
   while(cin>>p>>f>>c){
      if(p==0&&f==0&&c==0)break;
      for(int i = 0;i<p;++i){
         for(int j = 0;j<f;++j){
            for(int k = 0;k<c;++k){
               cin>>m[i][j][k];  
               if(m[i][j][k]=='S')p1=i,f1=j,c1=k;   
               if(m[i][j][k]=='E')p2=i,f2=j,c2=k;  
               d[i][j][k] = -1; 
            }   
         }   
      }
      bfs();
      if(d[p2][f2][c2]==-1)cout<<"Trapped!"<<endl;
      else cout<<"Escaped in "<<d[p2][f2][c2]<<" minute(s)."<<endl; 
   }
   return 0;         
}
