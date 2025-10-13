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
const ll MAXV=1e7+5,INF=1e18;
int cr[MAXV]; // -1 if prime, some not trivial divisor if not	O(nloglog(n))
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
// map<int,int> fac[MAXV];
map<int,int> fact(int n){  // must call init_cribe before		O(log(n))
	// auto &res=fac[n];
	// if(SZ(res))return res;
	map<int,int> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}

int main(){FIN;
	init_sieve();
	vv all;
	fore(i,2,MAXV)if(cr[i]==-1)all.pb(i);
	// ll mx=0;
	// fore(i,0,SZ(all)-1)mx=max(mx,all[i+1]-all[i]);
	// cerr<<"largest gap: "<<mx<<"\n";
	// return 0;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll s=*(--upper_bound(ALL(all),n));
		set<ll> ps;
		fore(i,s,n+1)for(auto [p,e]:fact(i))ps.insert(p);
		ll res=0;
		fore(a,s,n){
			ll mn=INF;
			for(auto p:ps){
				ll ca=0,cn=0;
				for(ll pot=p;pot<=m;pot*=p)ca+=a/pot,cn+=n/pot;
				for(ll pot=p,e=1;pot<=m;pot*=p,e++){
					ll cura=ca/e;
					ll curn=cn/e;
					ll cur=(cura!=curn?min(cura,curn):INF);
					mn=min(mn,cur);
				}
			}
			res+=mn;
			// cout<<a<<": "<<mn<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
