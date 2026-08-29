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
int main(){FIN;
	ll n,m; cin>>n>>m;
	vv num(n*m,1),is(n*m);
	fore(i,0,n){
		vv oc(n*m);
		fore(j,0,m){
			ll x; cin>>x; x--;
			is[x]=1;
			oc[x]++;
		}
		fore(v,0,SZ(oc))num[v]=mul(num[v],m-oc[v]);
	}
	ll res=0;
	fore(v,0,SZ(num))if(is[v]){
		ll cur=num[v];
		ll tot=fpow(m,n);
		cur=sub(tot,cur);
		res=add(res,cur);
	}
	cout<<res<<"\n";
	return 0;
}
