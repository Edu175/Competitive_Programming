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
const ll MAXV=4e5+5;
int cr[MAXV]; // -1 if prime, some not trivial divisor if not	O(nloglog(n))
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i){
		if(cr[j]==-1)cr[j]=i;
	}
}
int main(){FIN;
	init_sieve();
	ll t; cin>>t;
	while(t--){
		// cout<<cr[12]<<" cr6\n";
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		ll mn=4*MAXV;
		sort(ALL(a));
		ll flag=1;
		fore(i,1,n){
			ll v=a[i];
			flag&=cr[v]!=-1;
			mn=min(mn,v-((v&1)?cr[v]:0));
		}
		ll x=2,v=a[0];
		if((v&1)&&cr[v]==-1){
			flag&=2*v<=mn;
			x=v;
		}
		if(flag)cout<<x<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
