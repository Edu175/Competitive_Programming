#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const ll MAXN=3005;

vector<vector<ll>>comp(MAXN);
vector<ll> id(MAXN);

void uf_init(ll n){fore(i,0,n)comp[i].pb(i),id[i]=i;}
bool uf_join(ll a, ll b){
    if(id[a]==id[b])return false;
    ll ida=id[a], idb=id[b];
    if(SZ(comp[ida])>SZ(comp[idb]))swap(ida,idb);
    for(auto i:comp[ida]){
        comp[idb].pb(i);
        id[i]=idb;
    }
    return true;
}
vector<pair<ll,pair<ll,ll>>>es;//edges(cost,(u,v))
ll kruskals(ll n){
    sort(ALL(es)); uf_init(n);
    ll res=0;
    for(auto i:es){
        ll a=i.snd.fst, b=i.snd.snd, w=i.fst;
        if(uf_join(a,b)){
            res+=w;
        }
    }
    return res;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll f,t,w; cin>>f>>t>>w;
		f--,t--;
		es.pb({w,{f,t}});
	}
	cout<<kruskals(n);
	return 0;
}
