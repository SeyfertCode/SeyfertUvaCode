#include<iostream>
#include<vector>
#include<queue>
#define MAX 1005
using namespace std;

int dis[MAX];
void bfs(int ini, int fin){
	int lol;
	queue<int>Q;
	Q.push(ini);
	dis[ini] = 0;
	while(!Q.empty()){
		int x = Q.front();
		Q.pop();
		if(x==fin)return;
		int aux = x;
		if(aux%2==0){
			while(aux%2==0)aux/=2;
			if(dis[x+2]==-1){
				Q.push(x+2);
				dis[x+2]=dis[x]+1;
				if(x+2==fin)return;
			}
		}
		for(int i = 3; i*i<=aux;i+=2){
			if(aux%i==0){
				while(aux%i==0)aux/=i;
				if(dis[x+i]==-1){
					Q.push(x+i);
					dis[x+i]=dis[x]+1;
					if(x+i==fin)return;
				}
			}
		}
		if(aux>1&&aux!=x){
			if(dis[x+aux]==-1){
				Q.push(x+aux);
				dis[x+aux]=dis[x]+1;
				if(x+aux==fin)return;
			}	
		}		
	}	
}
int main(){
	int x,y,cont=0;
	while(cin>>x>>y){
		if(x==0&&y==0)break;
		for(int i = 0; i<MAX;++i)dis[i]=-1;
		bfs(x,y);
		cout<<"Case "<<++cont<<": "<<dis[y]<<endl;
	}
}
