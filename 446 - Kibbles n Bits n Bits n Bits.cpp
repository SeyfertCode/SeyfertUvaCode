#include<iostream>
using namespace std;

int toInt(string x){
	int l = x.size(), num = 0;
	for(int i = 0; i<l;++i){
		if(x[i]>='0'&& x[i]<='9')num = num*16 + x[i]-'0';
		else num = num*16 + x[i]-'A'+10;		
	}
	return num;
}
string toBinary(int x){
	string res = "";
	while(x>0){
		res+= (x&1)+48;
		x>>=1;
	}	
	//completamos ceros
	int lres = 13-res.size();
	for(int i = 0; i<lres;++i)res+="0";
	string rev = "";
	for(int i = res.size()-1; i>=0;--i)rev+=res[i];
	return rev;
}
int main(){
	string x, y;
	char c;
	int N;
	cin>>N;
	while(N--){
		cin>>x>>c>>y;
		int xi = toInt(x), yi = toInt(y);
		if(c == '+'){
			cout<<toBinary(xi)<<" + "<<toBinary(yi)<<" = "<<xi+yi<<endl;		
		}else{
			cout<<toBinary(xi)<<" - "<<toBinary(yi)<<" = "<<xi-yi<<endl;	
		}
	}
}
