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
const ll MAXN=2e5+5;
ll k;
ll good(vv a){
	vv b;
	ll n=SZ(a);
	vv vis(n);
	fore(i,0,n){
		ll j=n-i-1;
		if(!vis[j])b.pb(a[j]),vis[j]=1;
		if(!vis[i])b.pb(a[i]),vis[i]=1;
	}
	// cerr<<"good: ";
	// imp(a)
	// imp(b)
	// cerr<<"\n";
	fore(i,0,n-1)if(b[i]*b[i+1]>k)return 0;
	return 1;
}
ll solve(vv a){
	sort(ALL(a));
	ll res=0;
	while(!good(a)){
		a.pop_back();
		a.insert(a.begin(),1);
		res++;
	}
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q>>k;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		fore(_,0,q){
			ll l,r;
			cin>>l>>r; l--;
			vv b;
			fore(j,l,r)b.pb(a[j]);
			cout<<solve(b)<<" ";
			// cerr<<"\n\n";
		}
		cout<<"\n";
	}
	return 0;
}
