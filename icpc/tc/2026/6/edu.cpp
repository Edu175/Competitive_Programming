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
const ll MAXV=2e6+5,MOD=1e9+7;

ll cr[MAXV];

void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
map<ll,ll> factor(ll n){
	map<ll,ll> r;
	while(n>1){
		ll p=cr[n]==-1?n:cr[n];
		r[p]++;
		n/=p;
	}
	return r;
}
void actu(ii &a, ll x){
	if(x>a.fst)a={x,1};
	else if(x==a.fst)a.snd++;
}
int main(){
	JET
	init_sieve();
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a)); reverse(ALL(a));
	map<ll,ii> mp;
	vv wh(n)	;
	fore(i,0,n){
		ll x=a[i];
		if(mp[x].snd)x--,wh[i]=1;
		for(auto [p,e]:factor(x))actu(mp[p],e);
	}
	ll fg=0;
	fore(i,0,n){
		ll x=a[i];
		if(wh[i]){
			x--;
			ll util=0;
			for(auto [p,e]:factor(x)){
				util|=(mp[p].fst==e&&mp[p].snd==1);
			}
			if(!util)fg=1;
		}
	}
	ll res=1;
	for(auto [p,e]:mp){
		fore(_,0,e.fst)res=res*p%MOD;
	}
	res=(res+fg)%MOD;
	cout<<res<<"\n";
	return 0;
}
