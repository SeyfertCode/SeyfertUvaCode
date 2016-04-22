#include<bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
   int x,y,dir;
   int dx[] = {0, -1, -1, -1,  0,  1, 1, 1};
   int dy[] = {1,  1,  0, -1, -1, -1, 0, 1};
   
   while(cin>>x){
		if(x==-1)return 0;
		cin>>y>>dir;
		vector<int>a(9),b(9),t(9);
		for(int i = 0;i<8;++i)cin>>a[i]>>b[i]>>t[i];
	
		int tx, ty,k,i,j;
		for(i = dir+5, j = 0; j < 8; j++, i++) {
			i = (i+8)%8;
			tx = x+dx[i], ty = y+dy[i];
			for(k = 0; k < 8; k++) {
				if(a[k] == tx && b[k] == ty && t[k] == 1)break;
			}
			if(k != 8) {cout<<i<<"\n";break;}
		}
	}
	return 0;
}
