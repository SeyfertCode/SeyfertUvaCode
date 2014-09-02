//LAXUS-Seyfert
#include<iostream>
using namespace std;
//el circulo se divide en 40 segmentos, 360/40 = 9
int main(){
	int i,a,b,c;
	while(cin>>i>>a>>b>>c){
		if(i==0&&a==0&&b==0&&c==0)break;
		int grados = 120;
		int x = i-a;
		if(x<0)x+=40;
		int y = b-a;
		if(y<0)y+=40;
		int z = b-c;
		if(z<0)z+=40;
		grados += x+y+z;
		cout<<9*grados<<endl;
	}
}
