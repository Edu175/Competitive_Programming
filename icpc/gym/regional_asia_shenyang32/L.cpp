#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=4005,MOD=998244353;

int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}


vv g[MAXN];

vv operator*(vv a, vv b){
	vv c(SZ(a)+SZ(b)-1);
	fore(i,0,SZ(a))fore(j,0,SZ(b)){
		c[i+j]=add(c[i+j],mul(a[i],b[j]));
	}
	return c;
}

vv operator+(vv a, vv b){
	vv c(max(SZ(a),SZ(b)));
	a.resize(SZ(c));
	b.resize(SZ(c));
	fore(i,0,SZ(c)){
		c[i]=add(a[i],b[i]);
	}
	return c;
}

ll n;
vector<vv> dfs(ll x, ll fa){ // [0/1][k]
	vector<vector<vv>> got;
	for(auto y:g[x])if(y!=fa)got.pb(dfs(y,x));
	ll m=SZ(got);
	vv nos={1};
	fore(i,0,m)nos=nos*got[i][1];
	vector<vv> pre(m+1,{1}),suf(m+1,{1});
	
	fore(i,1,m+1)pre[i]=pre[i-1]*got[i-1][1];
	for(ll i=m-1;i>=0;i--)suf[i]=suf[i+1]*got[i][1];

	vv yes={};
	fore(i,0,m){
		vv cur=pre[i]*suf[i+1];
		vv hijo={got[i][0]}; hijo.insert(hijo.begin(),0);
		vv term=cur*hijo;
		yes=yes+term;
	}
	
	vector<vv> ans={nos,nos+yes};

	// cout<<"nodo "<<x<<":\n";
	// fore(k,0,SZ(ans)){
	// 	cout<<k<<": ";
	// 	for(auto j:ans[k])cout<<j<<" ";
	// 	cout<<"\n";
	// }
	// cout<<"\n";

	
	return ans;
}

int main(){
    JET
	cin>>n;
	fore(i,0,2*n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	auto got=dfs(0,-1);
	// fore(k,0,SZ(got)){
	// 	cout<<k<<": ";
	// 	for(auto j:got[k])cout<<j<<" ";
	// 	cout<<"\n";
	// }
	vv prod(n+3);
	prod[0]=1;
	fore(i,1,SZ(prod)){
		prod[i]=mul(prod[i-1],2*(i)-1);
	}
	// for(auto i:prod)cout<<i<<" ";;cout<<"\n";
	ll res=0;
	fore(k,0,SZ(got[1]))if(k<=n){
		// assert(k<=n);
		ll cur=mul(got[1][k],prod[n-k]);
		res=(k&1?sub:add)(res,cur);
	}
	cout<<res<<"\n";
    return 0;
}

    