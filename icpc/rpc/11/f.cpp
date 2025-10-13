#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
 
const int maxn = 1e3+10;

ll n,m; 

char g[maxn][maxn];
ll d[maxn][maxn];
ll vis[maxn][maxn];
vector<ii> w;
vector<ii> dire = {{0,-1}, {0,1}, {-1,0}, {1,0}};

ii move(ii a, ii b){
    a.fst+=b.fst;
    a.snd+=b.snd;
    if(a.fst < 0 || a.fst>=n || a.snd<0 || a.snd>=m) return {-1,-1};
    return a;
}

void dist(){
    queue<ii> q;
    mset(d,-1);
    for(auto [i,j] : w){
        d[i][j] = 0;
        q.push({i,j});
    }
    while(SZ(q)){
        auto pos = q.front();q.pop();
        for(auto dir : dire){
            auto[i,j] = move(pos,dir);
            if(i < 0) continue;
            if(d[i][j] >= 0) continue;
            q.push({i,j});
            d[i][j] = d[pos.fst][pos.snd] + 1;
        }
    }
}

void clear(){
    fore(i,0,n)fore(j,0,m) vis[i][j] = 0;
}

void dfs(int i, int j, const int &k){
    vis[i][j] = 1;
    for(auto dir:dire){
        auto [x,y] = move({i,j},dir);
        if(x<0 || vis[x][y]|| d[x][y]<k) continue;
        dfs(x,y,k);
    }
}

int main(){
    JET
    cin>>n>>m;
    fore(i,0,n)fore(j,0,m){
        cin>>g[i][j];
        if(g[i][j] == 'W') w.pb({i,j});
    }
    dist();
    ll l = 0, r = n*m; 
    while(l<=r){
        clear();
        ll k = (l+r)/2;
        // cout<<"Asdnoasd "<<l<<" "<<r<<endl;
        // fore(i,0,n)fore(j,0,m) if(d[i][j] < k && (i!=n-1 && j!=m-1)) vis[i][j] = 1;
        if(d[0][0]>=k)dfs(0,0,k);
        if(vis[n-1][m-1]) l = k+1;
        else r = k-1; 
    }
    cout<<r<<"\n";
    return 0;
}
