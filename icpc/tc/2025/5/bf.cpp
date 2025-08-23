#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=mul(res,b);
		b=mul(b,b); e>>=1;
	}
	return res;
}

ll n; // < 30

ll dpf[3005][15][15][15];
ll f(ll i, ll s, ll v, ll u){
	if(s<0||v<0)return 0;
	auto &res=dpf[i][s][v][u];
	if(res!=-1)return res;
	if(i==n)return res=s==0&&v==0;
	res=0;
	fore(j,0,i+1){
		if(j>s)break;
		res=add(res,f(i+1,s-j,v-(j>u),j));
	}
	return res;
}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll k,x; cin>>n>>k>>x;
		mset(dpf,-1);
		ll res=f(0,k,x,0);
		cout<<res<<"\n";
		// ans[idx]=res;
	}
	// fore(i,0,t)cout<<ans[i]<<"\n";
	return 0;
}