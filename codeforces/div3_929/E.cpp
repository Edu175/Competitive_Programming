#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
ll n;
ll a[MAXN],sp[MAXN];
ll fn(ll n){return n*(n-1)/2;}
ll suma(ll s, ll p, ll u){
	ll res=a[p]*u;
	ll sum=sp[p+1]-sp[s];
	ll sub=fn(sum)-fn(sum-a[p]);
	return res-sub;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,1,n+1)sp[i]=sp[i-1]+a[i-1];
		ll q; cin>>q;
		while(q--){
			ll s,u; cin>>s>>u; s--;
			ll l=s,r=n-1;
			while(l<=r){
				ll m=(l+r)/2;
				if(suma(s,m,u)<=0)r=m-1;
				else l=m+1;
			}
			r=max(r,s);
			cout<<r+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
