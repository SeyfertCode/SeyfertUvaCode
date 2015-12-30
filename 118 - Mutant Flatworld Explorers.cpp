#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int f,c;
	cin>>c>>f;
		
   int x,y;
   char dir;
   map<char, int>mm;mm['N'] = 0;mm['W'] = 1;mm['S'] = 2;mm['E'] = 3;
	string ss = "NWSE";
	while(cin>>x>>y>>dir){
		vector<vector<int> >m(f+5, vector<int>(c+5));
		string s;
		cin>>s;
		m[x][y] = mm[dir];
		bool flag = true;
		for(int i = 0;i<(int)s.size()&&flag;++i){
			if(s[i]=='F'){
				int xaux = x+(m[x][y]-2)*(m[x][y]%2), yaux = y+(m[x][y]-1)*(-1)*(1-m[x][y]%2);
				cout<<"nos vamos a "<<xaux<<" "<<yaux<<endl;
				if(xaux<0 or yaux<0 or xaux>c or yaux>f)flag=false;
				else m[xaux][yaux] = m[x][y], x = xaux, y = yaux, cout<<m[x][y]<<endl;
			}
			else if(s[i]=='L')m[x][y] = (m[x][y]+1)%4, cout<<"volteamos a la izquierda, actual: "<<m[x][y]<<endl;
			else 	m[x][y] = (m[x][y]+3)%4, cout<<"volteamos a la derecha, actual: "<<m[x][y]<<endl;;
		}
		cout<<x<<" "<<y<<" "<<ss[m[x][y]];
		if(!flag)cout<<" LOST";
		cout<<endl;
	}
}
