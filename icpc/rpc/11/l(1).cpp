#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ld sq(ld a){return a*a;}
ld dis(ii a, ii b){
	return sqrtl(sq(a.fst-b.fst)+sq(a.snd-b.snd));
}
const ll INF=1e18, eps=1e-4;
int main(){FIN;
	ll n,k,m; cin>>n>>k>>m;
	vector<ii> pts(n);
	fore(i,0,n)cin>>pts[i].fst>>pts[i].snd;
	vector<array<ll,3>> ed;
	fore(i,0,k) {
		ll u,v,w; cin>>u>>v>>w; u--,v--;
		ed.pb({u,v,w});
	}
    ll mn=INF;
    ld g[n][n];
    
    fore(mk,1,(1<<k)){
        ll c=0;
        fore(i,0,n)fore(j,0,n)g[i][j]=INF;
        fore(i,0,n)g[i][i]=0;
        fore(i,0,n) g[i][(i+1)%n]=g[(i+1)%n][i]=dis(pts[i],pts[(i+1)%n]);
        
        fore(i,0,k)if(mk&(1<<i)){
            g[ed[i][0]][ed[i][1]]=g[ed[i][1]][ed[i][0]]=dis(pts[ed[i][0]],pts[ed[i][1]]);
            c+=ed[i][2];
        }
        
        fore(r,0,n)fore(i,0,n)if(g[i][r]<INF)fore(j,0,n)if(g[r][j]<INF) 
            g[i][j]=min(g[i][j],g[i][r]+g[r][j]);
        bool f=1;
        fore(i,0,n)fore(j,0,i){
            if(g[i][j]>ld(m)+eps) {f=0; break;} 
        }
        if(f){
            mn=min(c,mn);
        }
    }
    cout<<mn<<"\n";
	return 0;
}
