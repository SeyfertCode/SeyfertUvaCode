#include<bits/stdc++.h>

using namespace std;

int main(){
	int N,R,cases=0;
	while(cin>>N>>R){
		if(N==0&&R==0)break;
		int x = (N-1)/R;
		cout<<"Case "<<++cases<<": ";
		if(x>26)cout<<"impossible"<<endl;
		else cout<<x<<endl;
	}
   return 0;

}
