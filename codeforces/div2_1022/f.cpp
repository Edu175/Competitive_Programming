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

const ll MAXN=1e5+5;

ll a[MAXN];
ll n;

bool can(ll m, ll dbg=0){
	// m--;
	vv b(n),h(n);
	fore(i,0,n)b[i]=a[i];
	ll sum=0;
	fore(i,0,n){
		sum+=h[i];
		b[i]+=sum;
		if(i<n-m){ // do op			
			sum+=b[i]>0;
			ll p=i+b[i]+1;
			if(p<SZ(h)&&b[i]>0)h[p]--;
			b[i]=0;
		}
	}
	if(dbg){
		cout<<"can "<<m<<": ";
		fore(i,0,n)cout<<b[i]<<" ";
		cout<<"\n";
	}
	ll fg=1;
	fore(i,0,m)fg&=b[n-1-i]>=i;
	return fg;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		ll l=1,r=n;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))l=m+1;
			else r=m-1;
		}
		fore(i,0,n+1)cout<<can(i)<<" ";;cout<<" cans\n";
		can(r,1);
		can(r+1,1);
		can(r+2,1);
		cout<<r<<"\n";
	}
	return 0;
}
