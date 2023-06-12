#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a, ggdem=b; i<ggdem; i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;
ll n,k;
ll a[n];
ll sumi;

bool solve(ll mini){
	for(ll i=n-1; sum>k&&i>0; i--)sumi-=a[i]-mini;
	return sumi<=k;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		ll sum=0;
		fore(i,0,n)cin>>a[i], sum+=a[i];
		sort(a,a+n);
		ll mini=a[0];
		ll res=0;
		while(mini*n>k)mini--,res++,sum--;
		ll l=-sum-k-5,r=mini;
		while(l<=r){
			ll m=l+r/2;
			if(solve)r=m-1;
			else l=m+1;
		}
		for(ll i=n-1; sum>k&&i>0; i--)sum-=a[i]-mini,res++;
		pres;
	}
	return 0;
}
