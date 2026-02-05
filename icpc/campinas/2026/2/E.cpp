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
typedef vector<vv> mat;
const ll MOD=998244353,MAXN=505;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vv g[MAXN];
#define addig(a,b) a=add(a,b)
mat merge(mat a, mat b){ // mats cuadradas
	ll z=(SZ(a)+SZ(b)-1);
	mat res(z,vv(z));
	fore(fg,0,2){
		ll n=SZ(a),m=SZ(b);
		vv acum(m);
		fore(mx,0,n){
			ll to=mx-fg;
			if(0<=to&&to<m){
				fore(l,0,m)addig(acum[l],b[to][l]);
			}
			fore(l,0,n)fore(k,0,m){
				ll cur=mul(a[mx][l],acum[k]);
				// if(!cur)continue;
				addig(res[mx][l+k],cur);
			}
		}
		swap(a,b);
	}
	return res;
}

void final(mat &a){ // lib++; usar libs (mex++,lib--)
	ll n=SZ(a);
	auto _a=a;
	a=mat(n+1,vv(n+1));
	fore(i,0,n)fore(j,0,n)a[i][j+1]=_a[i][j];
	n++;
	fore(i,0,n)fore(j,0,n)if(j>0){
		ll now=a[i][j];
		if(!now)continue;
		assert(i+1<n);
		addig(a[i+1][j-1],now);
	}
}
mat neut(1,vv(1,1)); // neut[0][0]=1
mat dfs(ll x, ll fa){
	mat ans=neut;
	for(auto y:g[x])if(y!=fa)ans=merge(ans,dfs(y,x));
	final(ans);
	return ans;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n-1){
			ll u,v; cin>>u>>v; u--,v--;
			g[u].pb(v);
			g[v].pb(u);
		}
		auto ans=dfs(0,-1);
		ll z=SZ(ans);
		ll res=0;
		fore(i,0,z)fore(j,0,z)addig(res,ans[i][j]);
		cout<<res<<"\n";
	}
	return 0;
}