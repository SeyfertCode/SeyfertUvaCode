#include<bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);
   
   int f,c,n;
   while(cin>>f>>c>>n){
		int ans = 0;
		if(f==0)break;
		vector<vector<char> >m(f,vector<char>(c));
		int sx,sy,ori;
		for(int i =0;i<f;++i){
			for(int j = 0;j<c;++j){
				cin>>m[i][j];
				if(m[i][j]=='N')ori = 0, sx = i,sy = j;
				else if(m[i][j]=='O')ori = 1, sx = i,sy = j;
				else if(m[i][j]=='S')ori = 2, sx = i,sy = j;
				else if(m[i][j]=='L')ori = 3, sx = i,sy = j;
			}
		}
		char ins;
		while(n--){
			cin>>ins;
			if(ins=='D')ori = (ori+3)%4;
			else if(ins =='E')ori=(ori+1)%4;
			else if(ins=='F'){
				if(ori==0&&sx>0&&m[sx-1][sy]!='#')sx--;
				else if(ori == 1 && sy>0 && m[sx][sy-1]!='#')sy--;
				else if(ori == 2 && sx<f-1 && m[sx+1][sy]!='#')sx++;
				else if(ori == 3 && sy<c-1 && m[sx][sy+1]!='#')sy++;
				if(m[sx][sy]=='*')ans++,m[sx][sy]='.';
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
