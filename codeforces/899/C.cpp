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
		ll sump=0;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]>0)sump+=a[i];
		}
		if(n==1){
			cout<<max(a[0],(ll)0)<<"\n";
			continue;
		}
		ll res=0;
		if(a[0]<0&&a[1]>0)res=max(sump-a[1],sump+a[0]);
		else res=sump;
		cout<<res<<"\n";
	}
	return 0;
}
