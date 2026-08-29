#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
bool les(ii a, ii b){
	return a.fst*b.snd<a.snd*b.fst;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vector<pair<ii,ll>> all;
		fore(i,0,n)fore(j,i+1,n)all.pb({{a[i],a[j]},0});
		fore(i,0,n)fore(j,0,n)if(i!=j)all.pb({{b[j],b[i]},1});
		sort(ALL(all),[&](pair<ii,ll> a, pair<ii,ll> b)->bool {
			if(les(a.fst,b.fst))return 1;
			if(les(b.fst,a.fst))return 0;
			return a.snd<b.snd;
		});
		ll res=0,q=0;
		for(auto e:all){
			// cout<<e.fst.fst<<","<<e.fst.snd<<" "<<e.snd<<"\n";
			if(e.snd)q++;
			else {
				// cerr<<"a "<<q<<"\n";
				ll tot=n*(n-1)%MOD;
				ll den=fpow(tot,MOD-2);
				ll cur=mul(q,den);
				res=add(res,cur);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
