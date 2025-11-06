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

void first(){
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vv p(n);
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		cout<<(p[0]<p[n-1])<<"\n";
	}
}
ll ty,n;
ll ask(ll l, ll r){
	if(ty)l=n-l,r=n-r,swap(l,r);
	cout<<"? "<<l+1<<" "<<r<<endl;
	ll ret; cin>>ret;
	return ret;
}

void second(){
	ll t; cin>>t;
	while(t--){
		ll x; cin>>n>>x;
		ty=!x;
		ll l=-1,r=n;
		while(r-l>1){
			ll m=(l+r)/2;
			if(ask(0,m+1)==n-1)r=m;
			else l=m;
		}
		ll m=r;
		if(ty)m=n-1-m;
		cout<<"! "<<m+1<<endl;
	}
}
int main(){FIN;
	string ty; cin>>ty;
	if(ty=="first")first();
	else second();
	return 0;
}
