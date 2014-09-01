/*LAXUS - SEYFERT*/
#include<iostream>

using namespace std;

int main()
{
	string s;
	int cont = 0;
    while(getline(cin,s)){
        int n = s.length();
        for(int i = 0; i<n;i++){
            if(s[i]!=34)cout<<s[i];
            else if(cont&1)cout<<"''",cont++;
            else cout<<"``",cont++;    
        }   
        cout<<endl;
    }
	return 0;
}
