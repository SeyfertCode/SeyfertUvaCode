#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

int r1[8] = {-2,-1,1,2,2,1,-1,-2};
int r2[8] = {1,2,2,1,-1,-2,-2,-1};
vector<vector<int> >v(9,vector<int>(9));

int bfs(int x1,int y1, int x2, int y2){
	queue<pair<int,int> > cola;
	pair<int,int> ini(x1,y1);
	cola.push(ini);
	v[x1][y1] = 1;
	while(!cola.empty()){
		pair <int,int> aux = cola.front();
        cola.pop();
        if(aux.first == x2 && aux.second == y2)return v[x2][y2];
        for(int i=0;i<8;i++){
            int mA=aux.first+r1[i],mB=aux.second+r2[i];
            if(mA>0&&mA<9&&mB>0&&mB<9){
                if(v[mA][mB] == 0){
                    v[mA][mB] = v[aux.first][aux.second]+1;
                    pair <int,int> nuevo(mA,mB);
                    cola.push(nuevo);
                }
            }
        }
	}
}
int main(){
	string posi, posf;
	while(cin>>posi>>posf){
		for(int i = 1; i<9;++i){
			for(int j = 1; j<9;++j)v[i][j] = 0;
		}
		int x = bfs(posi[0]-'a'+1,posi[1]-'0',posf[0]-'a'+1,posf[1]-'0')-1;
		if(x<0)x=0;
		cout<<"To get from "<<posi<<" to "<<posf<<" takes "<<x<<" knight moves."<<endl;
	}
}
