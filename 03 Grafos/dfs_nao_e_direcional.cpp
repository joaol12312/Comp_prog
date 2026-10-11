#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)
const int MAXN=1e5+7;
vector <int> adj [MAXN];
bool vis[MAXN];
void bts(int n){
    vis[n]=true;
    for(auto j : adj[n]){
        if(!vis[j]){
            bts(j);
        }
    }
}
void solve()
{
    int c,f; cin >> c >> f;
    FORi(f){
        int area1,area2;cin >> area1 >> area2;
        adj[area1].push_back(area2);
        //adj[area2].push_back(area1); não direcional
    }
    vector <int> representantes;
    for(int i = 1; i <=c ; i++)
    {
        if(!vis[i])
        {
            representantes.push_back(i);
            bts(i);
        }
    }
    int m=representantes.size()-1;
    cout << m << "\n";
    FORi(m)
    {
        cout << representantes[i] << " " << representantes[i+1] << "\n";
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    // cout << fixed << setprecision(9);

    int t=1; //cin>>t; 
    FORi(t) { solve(); }
}