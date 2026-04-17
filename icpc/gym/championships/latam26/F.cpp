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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=155;
ll uf[MAXN];
void uf_init(){mset(uf,-1);}
ll find(ll x){return uf[x]<0?x:uf[x]=find(uf[x]);}
void uf_join(ll x, ll y){if((x=find(x))!=(y=find(y)))uf[x]+=uf[y],uf[y]=x;}

int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll k=0; for(;k*(k+1)/2<n;k++);
	auto join=[&](ll i, ll j){if(a[i]==a[j])uf_join(i,j);};
	ll res=0;
	fore(mk,0,1ll<<k){
		uf_init();
		vv l,r,nv;
		ll w=0,mki=mk;
		fore(i,0,n){
			auto &v=w?r:l;
			ll p=SZ(nv);
			if(p<SZ(v))join(i,v[p]);
			if(p-1>=0)join(i,v[p-1]),join(i,nv[p-1]);
			if(SZ(l)==SZ(nv)){ // punta
				l.pb(i),r.pb(i),nv.pb(i);
				if(w)r=nv;
				else l=nv;
				w=mki&1,mki>>=1;
				nv.clear();
			}
			else nv.pb(i);
		}
		fore(i,0,n)res=max(res,-uf[find(i)]);
	}
	cout<<res<<"\n";
	return 0;
}