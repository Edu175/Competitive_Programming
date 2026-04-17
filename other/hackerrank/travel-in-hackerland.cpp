#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
ll c[MAXN];

struct cmp{
	vector<ll>v;
	set<ll>st;
	cmp(){}
	cmp(ll x):v(1,x){st={c[x]};}
};
cmp comp[MAXN]; ll id[MAXN];
void uf_init(ll n){fore(i,0,n)comp[i]=cmp(i),id[i]=i;}
bool uf_join(ll a, ll b){
	a=id[a], b=id[b];
	if(a==b)return 0;
	if(SZ(comp[a].v)>SZ(comp[b].v))swap(a,b);
	for(auto i:comp[a].v)comp[b].v.pb(i), id[i]=b;
	for(auto i:comp[a].st)comp[b].st.insert(i);
	comp[a].v.clear(); comp[a].st.clear();
	return 1;
}

int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	fore(i,0,n)cin>>c[i];
	
	return 0;
}
