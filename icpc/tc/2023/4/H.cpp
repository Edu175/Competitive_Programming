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

const ll MOD=(119<<23)+1,MAXF=1e6;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int b, ll e){
	if(e<0)return 0;
	int r=1;
	for(;e;e>>=1,b=mul(b,b))if(e&1)r=mul(r,b);
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
ll nCr(ll n, ll k){ // must call factos before
	if(n<0||k<0||k>n)return 0;
	return mul(mul(fc[n],fci[k]),fci[n-k]);
}
const ll MAXS=41;

unordered_map<ll,ll> dp[MAXS];
vv g;
ll f(ll mk, ll k){
	if(!mk)return k==0;
	if(!k)return 1;
	if(dp[k].find(mk)!=dp[k].end())return dp[k][mk];
	auto &res=dp[k][mk];
	ll p=__builtin_ctzll(mk);
	ll mki=mk^(1ll<<p);
	res=f(mki,k)+f(mki&(~g[p]),k-1);
	return res;
}

int main(){FIN;
	factos();
	ll n,m; cin>>n>>m;
	vector<ii> ed(m);
	vv has(n);
	vector<ii> a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd,a[i].snd++;
	fore(i,0,m){
		ll u,v; cin>>u>>v; u--,v--;
		ed[i]={u,v};
		has[u]=has[v]=1;
	}
	vv per(n); iota(ALL(per),0);
	sort(ALL(per),[&](ll i, ll j){
		if(has[i]!=has[j])return has[i]>has[j];
		return a[i]>a[j];
	});
	vv nl(n); fore(i,0,n)nl[per[i]]=i;
	auto _a=a; auto _has=has;
	fore(i,0,n){
		a[i]=_a[per[i]];
		has[i]=_has[per[i]];
	}
	for(auto &[u,v]:ed)u=nl[u],v=nl[v];
	g=vv(n);
	for(auto [u,v]:ed)g[u]|=1ll<<v,g[v]|=1ll<<u;
	
	ll s=count(ALL(has),1);
	assert(count(has.begin(),has.begin()+s,1)==s);
	vv lib(n+2);
	vector<ll> ev(n+2);
	fore(i,0,n)if(!has[i]){
		ev[a[i].fst]++;
		ev[a[i].snd]--;
	}
	ll cnt=0;
	fore(z,0,SZ(lib)){
		cnt+=ev[z];
		lib[z]=cnt;
	}
	ll res=0;
	fore(z,1,SZ(lib)){
		ll mk=0,cnt=0;
		fore(i,0,s){
			if(a[i].fst<=z&&z<a[i].snd)mk|=1ll<<i,cnt++;
		}
		// cerr<<"\nz "<<z<<":\n";
		fore(c,0,min(cnt,z)+1){
			ll cur=f(mk,c)%MOD,coef=nCr(lib[z],z-c);
			// cerr<<"c "<<c<<": "<<cur<<" "<<coef<<": ";
			cur=mul(cur,coef);
			// cerr<<cur<<"\n";
			res=add(res,cur);
		}
	}
	cout<<res<<"\n";
	return 0;
}
