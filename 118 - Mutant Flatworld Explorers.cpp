#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int f,c;
	cin>>c>>f;
   int x,y;
   char dir;
   map<char, int>mm;mm['N'] = 0;mm['W'] = 1;mm['S'] = 2;mm['E'] = 3;
	string ss = "NWSE";
	//vector<vector<int> >lose(f+1, vector<int>(c+1));
	vector<vector<bool> >lose(100, vector<bool>(100));
	while(cin>>x>>y>>dir){
		vector<vector<int> >m(100, vector<int>(100));
		string s;
		cin>>s;
		m[x][y] = mm[dir];
		bool flag = true;
		for(int i = 0;i<(int)s.size()&&flag;++i){
			if(s[i]=='F'){
				bool nlose=false;
				int xaux = x+(m[x][y]-2)*(m[x][y]%2), yaux = y+(m[x][y]-1)*(-1)*(1-m[x][y]%2);
				if(xaux<0 or yaux<0 or xaux>c or yaux>f){
					if(lose[x][y])nlose=true;
						
					if(nlose)continue;
					else lose[x][y] = true;
					flag=false;
				}
				else m[xaux][yaux] = m[x][y], x = xaux, y = yaux;
			}
			else if(s[i]=='L')m[x][y] = (m[x][y]+1)%4;
			else 	m[x][y] = (m[x][y]+3)%4;
		}
		cout<<x<<" "<<y<<" "<<ss[m[x][y]];
		if(!flag)cout<<" LOST";
		cout<<endl;
	}
}
