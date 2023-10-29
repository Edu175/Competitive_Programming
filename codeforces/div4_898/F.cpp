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
		ll n,k; cin>>n>>k;
		ll a[n],h[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>h[i];
		ll l=0,r=0,sum=a[0],res=0;
		while(l<n&&r<n){
			//cout<<l<<" "<<r<<": "<<sum<<"\n";
			if(r-l+1>=2&&h[r-1]%h[r]){
				sum-=a[l];
				l++;
				continue;
			}
			if(sum>k){
				sum-=a[l];
				l++;
				continue;
			}
			//cout<<"good\n";
			res=max(res,r-l+1);
			r++;
			if(r<n)sum+=a[r];
		}
		cout<<res<<"\n";
	}
	return 0;
}
