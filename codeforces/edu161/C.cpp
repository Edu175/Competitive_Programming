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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>lef(n),rig(n);
		fore(i,0,n){
			if(i<n-1){
				if(!i||a[i+1]-a[i]<a[i]-a[i-1])rig[i]=-(a[i+1]-a[i])+1;
			}
			if(i){
				if(i==n-1||a[i+1]-a[i]>a[i]-a[i-1])lef[i-1]=-(a[i]-a[i-1])+1;
			}
		}
		vector<ll> sl(n),sr(n);
		fore(i,1,n)sl[i]=sl[i-1]+lef[i-1],sr[i]=sr[i-1]+rig[i-1];
		ll q; cin>>q;
		while(q--){
			ll l,r; cin>>l>>r; l--; r--;
			ll sw=0;
			if(l>r)swap(l,r),sw=1;
			ll res=a[r]-a[l];
			if(!sw)res+=sr[r]-sr[l];
			else res+=sl[r]-sl[l];
			cout<<res<<"\n";
		}
	}
	return 0;
}
