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
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXV)if(cr[i]<0)for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
}
int main(){FIN;
	init_sieve();
	cr[0]=cr[1]=1;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll p=2,qi=0,pos=-1;
		fore(i,1,n){
			ll pi=i+i+1;
			if(cr[i+1]!=-1)continue;
			ll q=min(i,n-i);
			if(q>qi)p=pi,qi=q,pos=i;
		}
		assert(qi>=n/3-1);
		ll l=pos,r=pos+1;
		vv a;
		while(l>=1&&r<=n)a.pb(l--),a.pb(r++);
		fore(i,(l==0?r:1),(l==0?n+1:l+1))a.pb(i);
		swap(a[0],a[1]);
		imp(a);
		vv vis(n+1);
		for(auto i:a)assert(i>=1&&i<=n),vis[i]=1;
		vis[0]=1;
		assert(vis==vv(n+1,1));
	}
	return 0;
}
