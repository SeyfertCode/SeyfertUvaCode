#include<iostream>  
#include<algorithm>  
#include<cstring>  
#define MAX 100100
using namespace std;  
typedef long long ll;  
int ql,qr,p,v;    
int tree[4*MAX];  
int query(int o,int L,int R){  
    int M=(L+R)>>1,ans=1;  
    if(ql<=L && R<=qr)return tree[o];  
    if(ql<=M)ans*=query(o*2,L,M);  
    if(M<qr)ans*=query(o*2+1,M+1,R);  
    return ans;  
}  
void update(int o,int L,int R){  
    int M=(L+R)>>1;  
    if(L==R) tree[o]=v;  
    else{  
        if(p<=M)update(o*2,L,M);  
        else update(o*2+1,M+1,R);  
        tree[o]=tree[o*2]*tree[o*2+1];  
    }
}  
void build(int L,int R,int o){  
    int M=(L+R)/2;  
    if(L==R){  
        int t;  
        cin>>t;  
        if(t==0)tree[o]=0;  
        if(t>0)tree[o]=1;  
        if(t<0)tree[o]=-1;  
        return;  
    }  
    build(L,M,o*2);  
    build(M+1,R,o*2+1);  
    tree[o]=tree[o*2]*tree[o*2+1];  
}   
int main(){  
   int n,Q;  
   while(cin>>n>>Q){  
   	build(1,n,1);  
      char op;  
      int cnt=0;  
      for(int i=0;i<Q;i++){  
         cin>>op;
         if(op=='C'){
         	cin>>p>>v;
            if(v>0)v=1;
            else if(v<0)v=-1;  
            update(1,1,n);  
         }
         else if(op=='P'){  
         	cin>>ql>>qr;
         	int x = query(1,1,n);
         	if(x==0)cout<<"0";  
      		else if(x>0)cout<<"+";  
         	else if(x<0)cout<<"-";  
         }
      }
      cout<<endl;  
   }  
   return 0;  
}  
