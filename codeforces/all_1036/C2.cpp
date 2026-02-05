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
const ll MAXV=1e6+5;
int cr[MAXV]; // -1 if prime, some not trivial divisor if not	O(nloglog(n))
void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
map<int,int> fact(int n){  // must call init_cribe before		O(log(n))
	map<int,int> res;
	while(cr[n]>=0)res[cr[n]]++,n/=cr[n];
	if(n>1)res[n]++;
	return res;
}
int main(){FIN;
	init_sieve();
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		map<ll,vector<ii>> mp; // pos,c
		fore(i,0,n){
			cin>>a[i];
			for(auto [p,e]:fact(a[i]))mp[p].pb({i,e});
		}
		ll x=1;
		for(auto [p,v]:mp){
			reverse(ALL(v));
			ll mn=0,cur=0;
			for(auto [i,c]:v){
				mn=min(mn,c);
				ll q=c-mn;
				cur=max(cur,q);
			}
			fore(i,0,cur)x*=p;
		}
		cout<<x<<"\n";
	}
	return 0;
}
