#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MOD=1e9+7;

int add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	if(e<0)return 0;
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		e>>=1,b=mul(b,b);
	}
	return res;
}
ll inv(ll a){return fpow(a,MOD-2);}
vv g[MAXN];

ii f(ll x){
	if(!SZ(g[x]))return {1,1};
	vector<ii>got;
	ll m=SZ(g[x]);
	vv pre(m+1,1),suf(m+1,1);
	for(auto y:g[x]){
		auto cur=f(y);
		got.pb(cur);
	}
	fore(i,1,m+1)pre[i]=mul(pre[i-1],got[i-1].fst);
	for(ll i=m-1;i>=0;i--)suf[i]=mul(suf[i+1],got[i].fst);
	ii ans={pre[m],0};
	fore(i,0,m){
		ll cur=mul(pre[i],suf[i+1]);
		cur=mul(cur,got[i].snd);
		ans.snd=add(ans.snd,cur);
	}
	ans.fst=add(ans.fst,ans.snd);
	return ans;
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
	}
	cout<<f(0).fst<<"\n";
	return 0;
}