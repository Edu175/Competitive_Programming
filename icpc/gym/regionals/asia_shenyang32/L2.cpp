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

// ll dp[MAXN][MAXN][2];
// ll f(ll x, ll k, ll bo, ll fa){
// 	auto &res=dp[x][k][bo];
// 	vv si,no;
// 	for(auto y:g[x])if(y!=fa){
// 		si.pb()
// 	}
// }
ll n;
vector<vv> dfs(ll x, ll fa){ // [k][0/1]
	vector<vector<vv>> got;
	for(auto y:g[x])if(y!=fa)got.pb(dfs(y,x));
	ll m=SZ(got);
	vector<vv> ans(n+2,vv(2));
	fore(k,0,SZ(ans)){
		// not choose
		ll no=1;
		fore(i,0,m)no=mul(no,got[i][k][1]);
		
		if(!m&&k)no=0;
		
		ans[k][0]=ans[k][1]=no;
		
		if(!k)continue;
		
		// si 1 puedo choose
		vv pre(m+1,1),suf(m+1,1); // prod de k-1,1
		fore(i,1,m+1)pre[i]=mul(pre[i-1],got[i-1][k-1][1]);
		for(ll i=m-1;i>=0;i--){
			suf[i]=mul(suf[i+1],got[i][k-1][1]);
		}
		ll yes=0;
		fore(i,0,m){
			ll term=mul(pre[i],suf[i+1]);
			term=mul(term,got[i][k-1][0]);
			yes=add(yes,term);
		}
		ans[k][1]=add(ans[k][1],yes);
	}
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
	fore(k,0,SZ(got))if(k<=n){
		ll cur=mul(got[k][1],prod[n-k]);
		res=(k&1?sub:add)(res,cur);
	}
	cout<<res<<"\n";
    return 0;
}

    