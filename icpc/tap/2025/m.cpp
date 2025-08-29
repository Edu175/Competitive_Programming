#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

const ll MOD=998244353;

ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
    if(e<0)return 0;
    ll res=1;
    while(e){
        if(e&1)res=mul(res,b);
        b=mul(b,b); e>>=1;
    }
    return res;
}

const int MAXN = 2005;
vv g[MAXN];

ll dist[MAXN];

void bfs(ll x){
    mset(dist,-1);
    dist[x] = 0;
    queue<ll> q;
    q.push(x);
    while(SZ(q)){
        ll y = q.front();q.pop();
        for(auto k:g[y]){
            if(dist[k] == -1){
                dist[k] = dist[y] + 1;
                q.push(k);
            }
        }
    }
}

int main(){
    JET
    ll n,m,k; cin>>n>>m>>k;
    fore(i,0,m){
        ll x,y;cin>>x>>y;
        x--,y--;
        g[x].pb(y);
        g[y].pb(x);
    }
    bfs(0);
    if(dist[1] == -1){
        cout<<0<<"\n";
        return 0;
    }
    ll day = (dist[1]+k-1)/k;
    vector<vector<vv>> dp(n, vector<vv> (day+1, vv(k+1,-1)));
    auto f=[&](ll x, ll d, ll r, auto &&f) -> ll{
        if(d>day) return 0;
        ll & rta = dp[x][d][r];
        if(rta!=-1) return rta;
        rta = 0;
        if(d == day && x == 1) rta = 1;
        for(auto y:g[x]){
            if(r==0) rta= add(rta,f(y,d,r+1,f));
            else if(r == k) rta=add(rta,f(y,d+1,1,f));
            else rta = add(rta,add(f(y,d+1,1,f), f(y,d,r+1,f)));
        }
        return rta;
    };
    cout<<f(0,1,0,f)<<"\n";
}