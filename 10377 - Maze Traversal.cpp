#include<bits/stdc++.h>

using namespace std;

int main(){
	std::ios::sync_with_stdio(false);cin.tie(0);
	int T,f,c,sx,sy;
	string pos = "NWSE";
	
	cin>>T;
	for(int cases = 0;cases<T;++cases){
		int ori = 0;//L => (+1)%4   , R => -1  = (+3)%4
		cin>>f>>c;
		cin.get();
		vector<string>m(f);
		for(int i = 0;i<f;++i)getline(cin,m[i]);
		cin>>sx>>sy;
		sx--;sy--;
		char c;
		while(cin>>c){
			if(c=='L')ori = (ori+1)%4;
			else if(c=='R')ori = (ori+3)%4;
			else if(c=='F'){

				if(ori==0&&m[sx-1][sy]!='*')sx--;
				else if(ori == 1 && m[sx][sy-1]!='*')sy--;
				else if(ori == 2 && m[sx+1][sy]!='*')sx++;
				else if(ori == 3 && m[sx][sy+1]!='*')sy++;
			}
			else if(c=='Q'){
				if(cases>0)cout<<endl;
				cout<<sx+1<<" "<<sy+1<<" "<<pos[ori]<<endl;
				break;
			}
		}
		
	}
   
	return 0;
}
