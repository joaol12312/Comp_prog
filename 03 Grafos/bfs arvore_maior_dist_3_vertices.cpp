#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)
const int MAX = 2e5+7;
vector <int> adj[MAX];
int dis[MAX];
int pai[MAX];
void distancia(int inicio){
    memset(dis,-1,sizeof(dis));
    queue <int> fila;
    fila.push(inicio);
    dis[inicio]=0;
    pai[inicio]=-1;
    while(!fila.empty()){
        int atual=fila.front();
        fila.pop();
        for(auto filho: adj[atual]){
            if(dis[filho]==-1){
                dis[filho]=dis[atual]+1;
                pai[filho]=atual;
                fila.push(filho);
            }
        }
    }
}
void solve()
{
    int c; cin >> c;
    FORi(c-1){
        int b,d;cin >> b >> d;
        adj[b].push_back(d);
        adj[d].push_back(b);
    }
    int a=1;
    distancia(1);
    for(int i = 1; i<=c; i++){
        if(dis[i]>dis[a]){
            a=i;
        }
    }
    int b=1;
    distancia(a);
    for(int i = 1; i <=c;i++){
        if(dis[i]>dis[b]){
            b=i;
        }
    }
    int dorsal=dis[b];
    vector <int> distancia3(c+1,-1);
    queue <int> fila;
    int filho=b;
    distancia3[a]=0;distancia3[b]=0;
    while(dis[pai[filho]]>0)
    {
        fila.push(pai[filho]);
        distancia3[pai[filho]]=0;
        filho=pai[filho];
    }
    while(!fila.empty()){
        int n=fila.front();
        fila.pop();
        for(auto filho : adj[n]){
            if(distancia3[filho]==-1){
                distancia3[filho]=distancia3[n]+1;
                fila.push(filho);
            }
        }
    }
    int d=0;
    for(int i = 1; i <= c; i++){
        if(distancia3[i]>distancia3[d] && i!=a && i!=b){
            d=i;
        }
    }
    cout << dorsal+distancia3[d] << "\n";
    cout << a << " " << b << " " << d << "\n";
    
}
int main(){
    //cin.tie(NULL);ios_base::sync_with_stdio(false);
    int t=1;//cin >> t
    FORi(t){solve();}
}