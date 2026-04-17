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
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}

vector<string> trans(vector<string> a){
	ll n=SZ(a),m=SZ(a[0]);
	vector<string> b(m,string(n,'.'));
	fore(i,0,n)fore(j,0,m)b[j][i]=a[i][j];
	return b;
}

bool bad(vector<string> a, ll bo){ // fila
	ll n=SZ(a);
	fore(i,0,n){
		ll cnt=count(ALL(a[i]),'?');
		ll typ=count(ALL(a[i]),'1')&1;
		if(cnt==0&&typ!=bo)return 1;
	}
	return 0;
}
ll cont01(vector<string> a, ll bo){
	ll n=SZ(a),m=SZ(a[0]);
	assert((n%2)^(m%2));
	if(m%2==0)return cont01(trans(a),bo);
	assert(n%2==0);
	if(bad(a,bo))return 0;
	ll res=1;
	fore(i,0,n){
		ll cnt=count(ALL(a[i]),'?');
		fore(j,0,cnt-1)res=mul(res,2);
	}
	return res;
}
ll cont(vector<string> a, ll bo){
	ll n=SZ(a),m=SZ(a[0]);
	// if(bad(a,bo)||bad(trans(a),bo))return 0;
	// wanna send every color to 0
	fore(i,0,n)fore(j,0,m)if(a[i][j]!='?')a[i][j]^=bo;
	vv col(n+m);
	vector<vector<ii>> g(n+m); ll qidx=0;
	fore(i,0,n)fore(j,0,m){
		char c=a[i][j];
		// cerr<<c<<" c\n";
		if(c=='?')g[i].pb({n+j,qidx}),g[n+j].pb({i,qidx++});
		else col[i]^=c-'0',col[n+j]^=c-'0';
	}
	// imp(col)
	ll res=1;
	vv vis(n+m),vised(n*m);
	ll xr=0;
	auto dfs=[&](ll x, auto &&dfs)->void {
		// cout<<"dfs "<<x<<" "<<col[x]<<"\n";
		vis[x]=1; xr^=col[x];
		for(auto [y,i]:g[x])if(!vised[i]){
			vised[i]=1;
			if(!vis[y])dfs(y,dfs);
			else res=mul(res,2);
		}
	};
	fore(i,0,n+m)if(!vis[i]){
		// cout<<"root dfs\n";
		dfs(i,dfs);
		// cout<<"xr: "<<xr<<"\n\n";
		res*=xr==0;
		xr=0;
	}
	return res;
}
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<string> a(n);
	fore(i,0,n)cin>>a[i];
	if(n%2==0&&m%2==0){
		ll cnt=0;
		fore(i,0,n)cnt+=count(ALL(a[i]),'?');
		cout<<fpow(2,cnt)<<"\n";
		return 0;
	}
	if((n%2)^(m%2)){
		ll res=add(cont01(a,0),cont01(a,1));
		cout<<res<<"\n";
		return 0;
	}
	ll res=add(cont(a,0),cont(a,1));
	cout<<res<<"\n";
	
	return 0;
}
