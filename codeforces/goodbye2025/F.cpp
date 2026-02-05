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
const ll MOD=998244353,MAXF=1e6+5;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll fc[MAXF],fci[MAXF];
void factos(){
	fc[0]=1;
	fore(i,1,MAXF)fc[i]=mul(fc[i-1],i);
	fci[MAXF-1]=fpow(fc[MAXF-1],MOD-2);
	for(ll i=MAXF-2;i>=0;i--)fci[i]=mul(fci[i+1],(i+1));
}
const ll MAXN=2e5+5;
vv g[MAXN];

vv a;
ll dfs(ll x, ll fa){
	ll c=1;
	for(auto y:g[x])if(y!=fa){
		ll q=dfs(y,x);
		if(q&1)c+=q;
	}
	if(c%2==0||fa==-1)a.pb(c);
	return c;
}

int main(){FIN;
	factos();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		a.clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		dfs(0,-1);
		
		// cout<<"a: ";imp(a)
		ll val=1;
		fore(i,0,SZ(a)){
			val=mul(val,a[i]);
			if(i<SZ(a)-1)val=mul(val,a[i]);
		}
		ll res=0;
		fore(i,0,SZ(a)-1){ // ult
			ll cur=mul(val,fpow(a[i],MOD-2));
			cur=mul(cur,fc[SZ(a)-2]);
			res=add(res,cur);
		}
		if(SZ(a)==1)res=1;
		cout<<res<<"\n";
	}
	return 0;
}
