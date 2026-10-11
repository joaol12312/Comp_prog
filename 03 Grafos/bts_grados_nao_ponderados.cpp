#include <bits/stdc++.h>
using namespace std;
#define FORi(n) for(int i=0;i<n;i++)
int MAX=1e4+7;
void solve()
{
    int c, b; cin >> c >> b;

    vector <int> q (MAX,-1);
    queue <int> d;
    q[c]=0;
    d.push(c);
    while(!d.empty()){
        int n=d.front();
        d.pop();
        if(n==b){
            cout << q[n] << "\n";
            return;
        }

        int n1=n*2;
        if(n1<=MAX && q[n1]==-1){
            d.push(n1);
            q[n1]=q[n]+1;
        }
        int n2=n-1;
        if(n2>0 && q[n2]==-1){
            d.push(n2);
            q[n2]=q[n]+1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);

    // cout << fixed << setprecision(9);

    int t=1; //cin>>t; 
    FORi(t) { solve(); }
}