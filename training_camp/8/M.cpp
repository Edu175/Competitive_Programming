#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=30005;

ll n,k;
ll a[MAXN];

bool solve(ll x){
	ll res=0;
	ll ai[n];
	fore(i,0,n)ai[i]=a[i];
	fore(i,0,n){
		res+=ai[i]/x;
		ai[i]%=x;
		if(i<n-1){
			ll flt=x-ai[i];
			if(ai[i+1]>=flt)res++, ai[i+1]-=flt;
		}
	}
	return res>=k;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		ll m=0;
		fore(i,0,n)cin>>a[i], m+=a[i];
		ll l=1, r=m/k;
		while(l<=r){
			ll mid=(l+r)/2;
			if(solve(mid))l=mid+1;
			else r=mid-1;
		}
		cout<<r*k<<"\n";
	}
	return 0;
}
