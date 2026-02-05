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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,L,R; cin>>n>>L>>R;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		ll l=0,r=n-1;
		ll res=0;
		while(r-l+1>=1){
			ll s=0,e=0;
			if(a[l]>R)s=R,e=a[r--];
			else if(a[r]<L)s=a[l++],e=L;
			else s=a[l++],e=a[r--];
			res+=e-s;
		}
		cout<<res<<"\n";
	}
	return 0;
}
