#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)
#define all(a) (a).begin(),(a).end()
const int MAXN=2e5+7;
vector <int> adj [MAXN];
int cor[MAXN];
bool possivel(int num){
    for( auto nums : adj[num])
    {
        if(cor[nums]==-1){
            if(cor[num]==1){
                cor[nums]=0;
            }else{
                cor[nums]=1;
            }
            if(!possivel(nums))return false;
        }
        else if(cor[nums]==cor[num]){
            return false;
        }
    }
    return true;
}
void solve()
{
    int c,b;cin >> b >> c;
    FORi(c){
        int n,m; cin >> n >> m;
        adj[n].push_back(m);
        adj[m].push_back(n);
    }
    FORi(b+1)cor[i]=-1;
    bool ok = true;
    for (int i = 1; i <= b; i++) {
        if (cor[i] == -1) {
            cor[i] = 1;
            if (!possivel(i)) {
                ok = false;
                break;
            }
        }
    }
    if(ok){
        cout << "POSSIVEL" << "\n";
    }else{
        cout << "IMPOSSIVEL" << "\n";
    }

}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);

    // cout << fixed << setprecision(9);

    int t=1; //cin>>t; 
    FORi(t) { solve(); }
}