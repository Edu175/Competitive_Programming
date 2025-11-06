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
		ll n,x; cin>>n>>x;
		ll sum=0;
		vv a(n);
		fore(i,0,n)cin>>a[i],sum+=a[i];
		sort(ALL(a));
		ll m=0;
		vv res;
		ll l=0,r=n-1;
		ll score=0;
		while(l<=r){
			if(m+a[l]<x)res.pb(a[l]),m+=a[l],l++;
			else {
				res.pb(a[r]);
				m=(m+a[r])%x;
				score+=a[r];
				r--;
			}
		}
		cout<<score<<"\n";
		imp(res)
	}
	return 0;
}
