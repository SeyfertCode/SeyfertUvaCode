//Laxus-Seyfert
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int f,c;
    int field = 0;
    while(cin>>f>>c){
        if(f==0&&c==0)break;
        if(field>0)cout<<endl;
        field++;
        cout<<"Field #"<<field<<":"<<endl;
        vector<vector<char> > m(f,vector<char>(c));
        for(int i=0;i<f*c;i++)cin>>m[i/c][i%c];
        //iniciamos la busqueda de numeros.
        for(int i=0;i<f;i++){
            for(int j=0;j<c;j++){
                if(m[i][j]!='*'){
                    int contador = 0;
                    for(int p = i-1;p<=i+1;p++){
                        for(int q = j-1;q<=j+1;q++){
                            if(p>=0&&p<f&&q>=0&&q<c){
                                if(m[p][q]=='*')contador++;        
                            }    
                        }    
                    }
                    m[i][j] = contador+48;    
                }   
            }    
        }
        //mostramos la matriz     
        for(int i=0;i<f;i++){
            for(int j=0;j<c;j++){
                cout<<m[i][j];    
            } 
            cout<<endl;   
        }
   }
	return 0;
}
