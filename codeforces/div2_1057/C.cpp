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
		ll n; cin>>n;
		vv a(n);
		map<ll,ll> mp;
		fore(i,0,n)cin>>a[i],mp[a[i]]++;
		vv sol;
		ll sum=0,cnt=0;
		// ll mx=0;
		for(auto [z,q]:mp){
			ll cur=q/2*2;
			cnt+=cur;
			sum+=z*cur;
			if(q&1)sol.pb(z);
			// if(cur)mx=max(mx,z);
		}
		sol.pb(0); sol.pb(0);
		sort(ALL(sol));
		reverse(ALL(sol));
		// cout<<cnt<<" "<<sum<<": ";
		// imp(sol)
		fore(i,0,SZ(sol)-1){
			if(sol[i]<sol[i+1]+sum){ // pongo ambos
				sum+=sol[i]+sol[i+1];
				cnt+=(sol[i]>0)+(sol[i+1]>0);
				break;
			}
		}
		// cout<<cnt<<" "<<sum<<"\n";
		if(cnt<3)sum=0;
		cout<<sum<<"\n";
	}
	return 0;
}
