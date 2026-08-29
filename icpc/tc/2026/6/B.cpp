#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<ii> vi;
const ll maxn=3e6+5,MOD=1e9+7; 
ll mulm(ll a, ll b){return a*b%MOD;}
ll cr[maxn];
void init_cr(){
	fore(i,2,maxn)if(!cr[i]){
		for(ll j=i*i; j<maxn; j+=i){
			cr[j]=i;
		}
	}
}
vi fact(ll x){
	vi r;
	while(cr[x]){
		ll p=cr[x];
		r.pb({p,0});
		while(!(x%p)){
			x/=p;
			r.back().snd++;
		}
	}
	if(x>1) r.pb({x,1});
	return r;
}

ll vis[maxn];
int main(){
	JET
	init_cr();
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n) cin>>a[i];
	sort(a,a+n); reverse(a,a+n);	
	
	map<ll,ll> m;
	ll sumo=0;
	fore(i,0,n){
		ll x=a[i];
		if(vis[x]) x--;
		auto f=fact(x);
		for(auto [p,e]:f)vis[p]=1,m[x]=max(m[x],e);
	}
	ll rt=1;
	for(auto [p,e]: m){
		fore(i,0,e) rt=mulm(rt,p);
	}
	cout<<rt<<"\n";
	return 0;
}
