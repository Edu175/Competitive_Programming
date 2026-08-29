#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,bmi,bmi2,popcnt,lzcnt")

vector<ii> pts;

map<ll,vector<ii>> hor, ver;

const int maxn = 1e3+199;
vv g[maxn];
ll qcmp = 0;
ll vis[maxn];
ll n;
const ll INF  = 1e10+1000;
ll mind = INF;


ll dist(int x, int y){
    return abs(pts[x].fst - pts[y].fst) + abs(pts[x].snd - pts[y].snd);
}
ll dist(ii x, ii y){
    return abs(x.fst-y.fst) + abs(x.snd-y.snd);
}

void dfs(int x, ll k){
    vis[x] = qcmp;
    for(auto y :g[x]){
        if(dist(x,y) > k || vis[y]>=0){
            if(vis[y] != vis[x]&& vis[y]!=-1) mind = min(mind,dist(x,y));
            continue;
        }
        dfs(y,k);
    }
}

ii inter[maxn][maxn];
vector<ii> intep;
ll cnt[maxn*maxn][4];
bool can(ll k){
    mset(vis,-1);qcmp = 0;mind = INF;
    fore(i,0,n)if(vis[i] == -1){
        dfs(i,k);
        qcmp++;
    }
    // cout<<"vivo "<<qcmp<<"\n";
    if(qcmp == 1) return true;
    if(qcmp >= 5) return false;
    if(qcmp == 2 && mind<=2ll*k) return 1;  
    vv aux;  
    fore(i,0,n)fore(j,0,n){
        if(vis[i] == vis[j])continue;
        auto [i1,j1]=inter[i][j];
        if(dist(intep[i1],pts[i])<=k && dist(intep[i1],pts[j])<=k) 
            cnt[i1][vis[i]]++,cnt[i1][vis[j]]++;
        if(dist(intep[j1],pts[i])<=k && dist(intep[j1],pts[j])<=k) 
            cnt[j1][vis[i]]++,cnt[j1][vis[j]]++;
        aux.pb(i1); aux.pb(j1);
    }
    // cout<<"viendo el punto "<<aux[i].fst.fst<<" "<<aux[i].fst.snd<<"\n";
    bool rta=0;
    fore(i,0,SZ(aux)){
        bool b=1;
        fore(j,0,qcmp) if(!cnt[aux[i]][j]) b=0;
        if(b) {rta=true; break;}
    }
    fore(i,0,SZ(aux)){
        fore(j,0,qcmp) mset(cnt[aux[i]],0);
    }
    return rta;
}

void red(vector<ii> &a){
    if(!SZ(a)) return ;
    sort(ALL(a));
    vector<ii> r={a[0]};
    for(auto x:a) if(x!=r.back())r.pb(x);
    swap(a,r);
}
int main(){
    JET
    cin>>n;
    fore(i,0,n){
        ll x,y; cin>>x>>y;
        pts.pb({x,y});
        hor[y].pb({x,i});
        ver[x].pb({y,i});
    }

    fore(i,0,n)fore(j,0,n){
        ii p1 = {pts[i].fst,pts[j].snd};
        ii p2 = {pts[j].fst,pts[i].snd};
        intep.pb(p1); intep.pb(p2);
    }
    red(intep);
    fore(i,0,n)fore(j,0,n){
        ii p1 = {pts[i].fst,pts[j].snd};
        ll it=lower_bound(ALL(intep),p1)-intep.begin();
        ii p2 = {pts[j].fst,pts[i].snd};
        ll jt=lower_bound(ALL(intep),p2)-intep.begin();
        inter[i][j]=inter[j][i]={it,jt};
    }
    fore(_,0,2){
        for(auto &[p,v] : hor){
            sort(ALL(v));
            fore(i,1,SZ(v)){
                ll x = v[i-1].snd,y = v[i].snd;
                g[x].pb(y);
                g[y].pb(x);
            }
        }
        swap(hor,ver);
    }
    // fore(i,0,n)show(g[i]);
	ll R=2e9+100;
    ll l = 0 , r = R;
    while(l<=r){
        ll m = l+(r-l)/2;
        if(can(m)) r = m-1;
        else l = m+1;
    }
    cout<<(l<=R-50 ? l:-1)<<"\n";
    // cout<<can(1000)<<"\n";
    return 0;
}