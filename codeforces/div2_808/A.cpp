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

set<ll> primefactors(ll x){
	set<ll>st;
	for(ll i=1; i<=sqrt(x); i++)if(x%i==0)st.insert(i);
	st.insert(x);
	return st;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		//6 8 11 15
		fore(i,0,n)cin>>a[i];
		ll flag[n];
		ll res=1;
		fore(i,1,n){
			flag[i]=0;
			set<ll>pfs=primefactors(a[i]);
			//imp(pfs);
			for(auto p:pfs){
				ll val=p;
				for(ll j=i-1; j>=0; j--){
					//cout<<val<<" ";
					if(val%a[j]==0)flag[i]=1;
					else val=a[j]-val;
					if(val<=0)break;
				}
			}
			if(flag[i]==0)res=0;
		}
		//cout<<"\n";
		//imp(flag);
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
