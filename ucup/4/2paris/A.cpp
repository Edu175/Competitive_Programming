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
const ll MAXN=5e5+5,MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
const ll MAXF=2*MAXN;
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

vv operator+(vv a, vv b){
	vv c(max(SZ(a),SZ(b)));
	fore(i,0,SZ(a))c[i]+=a[i];
	fore(i,0,SZ(b))c[i]+=b[i];
	return c;
}
void up(vv &a){
	a.insert(a.begin(),0);
}
void down(vv &a){
	a.erase(a.begin());
}
void cut(vv &a){
	while(SZ(a)&&!a.back())a.pop_back();
}
vv hist;

vv g[MAXN];
ll k;
ll res=0;
vv child[MAXN];
vv dfs0(ll x){
	// if(d>=SZ(hist))hist.resize(d+1);
	// hist[d]++;
	// for(auto y:g[x])dfs0(y,d+1);
	vv ans;
	for(auto y:g[x]){
		auto cur=dfs0(y);
		ans=ans+cur;
	}
	up(ans);
	ans[0]++;
	child[x]=ans;
	return ans;
}


void dfs1(ll x){
	// cout<<x<<": "; imp(hist)
	fore(i,1,SZ(hist)){
		res=add(res,nCr(hist[i],k));
	}
	for(auto y:g[x]){
		auto &cur=child[y];
		up(hist);
		assert(SZ(cur)+2<=SZ(hist));
		fore(i,0,SZ(cur)){
			hist[i+2]-=cur[i];
			hist[i]+=cur[i];
		}
		cut(hist);
		dfs1(y);
		if(SZ(cur)+2>SZ(hist))hist.resize(SZ(cur)+2);
		fore(i,0,SZ(cur)){
			hist[i+2]+=cur[i];
			hist[i]-=cur[i];
		}
		assert(hist[0]==0);
		down(hist);
		cut(hist);
	}
}

int main(){FIN;
	factos();
	
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n>>k; k--;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		// hist.clear();
		dfs0(0);
		hist=child[0];
		res=0;
		dfs1(0);
		fore(i,0,n)child[i].clear();
		if(k==0)res=n;
		cout<<res<<"\n";
	}
	return 0;
}
