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
ll dp[MAXN],a[MAXN];
bool can(ll x){
	//fore(i,0,n+3)dp[i]=0;
	dp[n]=0;
	ll r=n-1,sum=0;
	multiset<ll>st={dp[n]};
	//cout<<"can "<<x<<":\n";
	for(ll i=n-1;i>=0;i--){
		dp[i]=x+5;
		while(sum>x)sum-=a[r],st.erase(st.find(dp[r+1])),r--;
		if(SZ(st))dp[i]=a[i]+*st.begin();
		st.insert(dp[i]);
		sum+=a[i];
		//cout<<i<<" ->"<<r<<": "<<dp[i]<<"\n";
	}
	while(sum>x)sum-=a[r],st.erase(st.find(dp[r+1])),r--;
	ll res=(SZ(st)?*st.begin():x+5);
	//cout<<(res<=x)<<"\n\n";
	return res<=x;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		ll l=0,r=1e15;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))r=m-1;
			else l=m+1;
		}
		cout<<l<<"\n";
	}
	return 0;
}
