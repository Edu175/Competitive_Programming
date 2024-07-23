#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=3e5+5;
const ll mod=1e9+7;
ll cr[MAXN];
ll mul(ll n, ll m){
	return n*m%mod;
}
ll fpow(ll b, ll e){
	ll res=1;
	while(e){
		if(e&1)res=res*b;
		b=b*b,e>>=1;
	}
	return res;
}
void init(){
	mset(cr,-1);
	fore(i,2,MAXN){if(cr[i]<0)for(ll j=1ll*i*i;j<MAXN;j+=i)cr[j]=i;}
}
/*map <ll,ll> fact(ll n){
	map<ll,ll> r;
	while(cr[n]>=0) r[cr[n]]++, n/=cr[n];
	if(n>1) r[n]++;
	return r;
}*/
vector<ii>fact(ll n){
	vector<ii>ret;
	while(n>1){
		ll d=cr[n]==-1?n:cr[n];
		// cout<<n<<","<<d<<endl;
		ll c=0;
		while(n%d==0)c++,n/=d;
		ret.pb({d,c});
	}
	return ret;
}
vector<ll>divs[MAXN];
void divisores(){
	fore(i,1,MAXN)for(ll j=i;j<MAXN;j+=i)divs[j].pb(i);
}
ll dp_phi[MAXN];
ll phi(ll k){
	ll &res=dp_phi[k];
	if(res!=-1)return res;
	res=1ll;
	for(ii d: fact(k)){
		res*=(d.fst-1)*fpow(d.fst,d.snd-1);
	}
	return res;
}
int main(){
	JET
	init();
	divisores();
	mset(dp_phi,-1);
	int n; cin>>n;
	ll res=0;
	fore(i,1,n){
		for(ll d: divs[n-i]){
			if(d==n-i) continue;
			res+=mul(lcm(i,d),phi((n-i)/d));
			res%=mod;
		}
	}
	cout<<res<<"\n";
	return 0;
}