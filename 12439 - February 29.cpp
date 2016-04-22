#include<bits/stdc++.h>

using namespace std;

bool bisiesto(int a){
	return a % 4 == 0 && (a % 100 != 0 || a % 400 == 0);
}
int main(){
	string a,b;
	map<string,int>m;
	m["January"] = 1;m["February"] = 2;
	m["March"] = 3;m["April"] = 4;
	m["May"] = 5;m["June"] = 6;
	m["July"] = 7;m["August"] = 8;
	m["September"] = 9;m["October"] = 10;
	m["November"] = 11;m["December"] = 12;
	int n;
	cin>>n;
	cin.get();
	for(int cases=0;cases<n;++cases){
		getline(cin,a);getline(cin,b);
		stringstream ssa(a), ssb(b);
		string aux;
		int mx,dx=0,ax,my,dy=0,ay,ans=0;
		
		ssa>>aux;
		mx = m[aux];
		ssa>>aux;
		for(int i=0;i<(int)aux.size()-1;++i)dx=dx*10+aux[i]-48;
		ssa>>ax;
		
		
		ssb>>aux;
		my = m[aux];
		ssb>>aux;
		for(int i=0;i<(int)aux.size()-1;++i)dy=dy*10+aux[i]-48;
		ssb>>ay;
		
		if(mx==1 or mx ==2)ax--;
		ans = ax/4 - ax/100 + ax/400;
		if(my==1 or my == 2)ay--;
		if(my == 2 and dy==29)ay++;
		ans -= ay/4 - ay/100 +ay/400;
		cout<<"Case "<<cases+1<<": "<<-ans<<endl;
		
	}
   
	return 0;
}
