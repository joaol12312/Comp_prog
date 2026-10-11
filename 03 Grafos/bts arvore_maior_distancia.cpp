#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)
const int MAXN=2e5+7;
vector <int> adj [MAXN];
bool vis[MAXN];
pair<int,vector<int>> bfs(int num,int n){
    vector <int> distancias (MAXN,-1);
    queue <int> valores;
    distancias[num]=0;
    valores.push(num);
    int maior=num;
    while(!valores.empty())
    {
        int valor=valores.front();
        valores.pop();
        if(distancias[valor]>distancias[maior]){
                maior=valor;
        }
        for(auto value : adj[valor]){
            if(distancias[value]==-1)
            {
                valores.push(value);
                distancias[value]=distancias[valor]+1;
            }
        }
    }
    return {maior,distancias};
}
void solve()
{
    int c;cin >> c;
    FORi(c-1){
        int n,m; cin >> n >> m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    /*auto [valorA, dist0] = bfs(1,c);
    auto [valorb, distA] = bfs(valorA,c);
    auto [valor0, distB] = bfs(valorb,c);

    for(int i = 1; i<=c; i++){
        cout << min(distA[i],distB[i]) << " ";
    }
    cout << "\n";*/

}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    // cout << fixed << setprecision(9);

    int t=1; //cin>>t; 
    FORi(t) { solve(); }
}