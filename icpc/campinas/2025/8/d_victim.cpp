#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define forn(i, n) for(int i=0; i < (int)n; ++i)
#define pb push_back
#define fst first
#define snd second
#define sz(v) (int)(v.size())
typedef long long ll;

const int MAXN = 2e5+100;
set<pair<int,int>> G[MAXN];
vector<bool> vis(MAXN), rta(MAXN);
bool col=0;

void tryy(int v){
    if(!sz(G[v])) return;
    auto u = *G[v].begin();
	cout<<"tryy "<<v<<"\n";
	cout<<"arista "<<u.snd<<"\n";
    rta[u.second]=col;
    G[u.first].erase({v,u.second});
    G[v].erase(u);
    col = not col;
    tryy(u.first);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<int> x(n), y(n);
    map<int,int> idx, idy;
    forn(i,n) cin>>x[i]>>y[i];
    int act=0;
    forn(i,n){
        if(!idx.count(x[i])) idx[x[i]]=act++;
        x[i]=idx[x[i]];
    }
    forn(i,n){
        if(!idy.count(y[i])) idy[y[i]]=act++;
        y[i]=idy[y[i]];
    }

    forn(i,n){
		cout<<"arista "<<x[i]<<" "<<y[i]<<"\n";
        G[x[i]].insert({y[i],i});
        G[y[i]].insert({x[i],i});
    }

    vector<int> imps;
    forn(i,act) if(sz(G[i])%2==1) imps.push_back(i);
    for(auto i:imps){
        if(sz(G[i])%2==0) continue;
        tryy(i);
    }
    forn(i,act) tryy(i);
    forn(i,n){
        if(rta[i]) cout<<"F";
        else cout<<"L";
    }
    cout<<endl;
}