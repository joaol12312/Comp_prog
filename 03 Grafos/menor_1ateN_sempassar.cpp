#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)
#define FORj(n) for(int j=0;j<n;j++)
const int INF=1e9;
void solve()
{
    int n,m;cin >> n >> m;
    string adj [n+1];
    FORi(n)cin >> adj[i+1];
    vector <int> distanc1 (n+1,INF);
    distanc1[1]=0;
    for(int i = 1;i<=n; i++){
        if(distanc1[i]==INF)continue;
        else{
            FORj(m){
                if(adj[i][j]=='1'){
                    int v=j+1+i;
                    if(v <= n)distanc1[v]=min(distanc1[v],distanc1[i]+1);
                }
            }
        }
    }
    vector <int> distancN (n+1,INF);
    distancN[n]=0;
    for(int i = n;i>=1; i--){
        FORj(m){
            if(adj[i][j]=='1' && i+j+1<=n && distancN[i+j+1]!=INF){
                distancN[i]=min(distancN[i],distancN[i+j+1]+1);
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        int minimo=INF;
        for(int j=max(1,i-m+1);j<i;j++){
            if(distanc1[j]==INF)continue;
            for(int k = 0; k < m ;k++)
            {
                if(j+k+1<=n && adj[j][k]=='1' && j+k+1>i){
                    if(distancN[j+k+1]!=INF)minimo=min(distanc1[j]+distancN[j+k+1]+1,minimo);
                }
            }
        }
        if(minimo==INF)minimo=-1;
        cout << minimo << " ";
    }
    cout << "\n";

}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    // cout << fixed << setprecision(9);

    int t=1; //cin>>t; 
    FORi(t) { solve(); }
}