#include<bits/stdc++.h>
#define MAX 105
using namespace std;
int f,c;
vector<vector<char> >m(105, vector<char>(105));
void flood(int x, int y){
	m[x][y] = '*';
	for(int i = -1;i<=1;++i){
		for(int j = -1;j<=1;++j){
			if(x+i>=0&&x+i<f&&y+j>=0&&y+j<c&&m[x+i][y+j]=='@')flood(x+i,y+j);
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	while(cin>>f>>c){
		if(f==0&&c==0)return 0;
		for(int i = 0;i<f;++i){
			for(int j = 0;j<c;++j)cin>>m[i][j];
		}
		int ans = 0;
		for(int i = 0;i<f;++i){
			for(int j = 0;j<c;++j){
				if(m[i][j]=='@')flood(i,j),ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
