#include<bits/stdc++.h>
using namespace std;

vector<int>v(10010);
vector<int>e(10010);

int find(int a){
	if(a<0)return a;
	return a==v[a]?a:v[a]=find(v[a]);
}


int areFriend(int a, int b){
	return(find(a)==find( b));
}
int areEnemy(int a, int b){
	int x = find(a), y = find(b);
	if(x==y)return 0;
	
	e[x] = find(e[x]);
		
	if(e[x] ==y)return 1;
	
	return 0;
	
}

int setFriend(int a, int b){
	int x = find(a),y = find(b);
	if(areFriend(x,y))return 0;
	else if(areEnemy(x,y))return 1;
	if(x==y)return 0;
	int p = find(e[x]),q = find(e[y]);
	
	v[y] = x;
	
	if(p<0&&q<0){
		e[x]=-1;
	}else if(p<0){
		e[x] = q;
		e[q] = x;
	}else if(q<0){
		e[x] = p;
		e[p] = x;
	}else{
		v[q] = p;
		e[x] = p;
		e[p] = x;
	}
	
	return 0;
	
	
}

int setEnemy(int a, int b){
	int x = find(a),y=find(b);
	if(areFriend(x,y))return 1;
	else if(areEnemy(x,y))return 0;
	if(x==y)return 1;
	int p = find(e[x]), q=find(e[y]);
	
	if(p>=0)v[p] = y;
	if(q>=0)v[q] = x;
	
	e[x] = y;
	e[y] = x;
	
	return 0;	
}

int main(){
	int N;
	cin>>N;
	for(int i = 0;i<N;++i)v[i] = i,e[i]=-1;
	int a,b,c;
	while(cin>>c>>a>>b){
		if(a==0&&b==0&&c==0)break;
		
		if(c<1 or c>4 or a<0 or a>=N or b<0 or b>=N)cout<<-1<<endl;
		else if(c==1&&setFriend(a,b))cout<<-1<<endl;
		else if(c==2&&setEnemy(a,b))cout<<-1<<endl;
		else if(c==3)cout<<areFriend(a,b)<<endl;
		else if(c==4)cout<<areEnemy(a,b)<<endl;
		
	}
	
}
