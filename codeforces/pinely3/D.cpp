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
		ll flag=1;
		vector<ll>cnt(2);
		vector<ll>a(n);
		fore(i,0,n){
			cin>>a[i];
			if(i&&a[i]!=a[i-1])flag=0;
			if(a[i]>=k)cnt[0]=1;
			if(a[i]<=k)cnt[1]=1;
		}
		if(flag){
			//cout<<"flag\n";
			cout<<"0\n";
			continue;
		}
		if(cnt[0]&&cnt[1]){
			cout<<"-1\n";
			continue;
		}
		a.pb(k);
		sort(ALL(a));
		ll g=0;
		fore(i,0,n)g=gcd(g,a[i+1]-a[i]);
		ll mt=k+g;
		if(a[n]==k)mt=k-g;
		ll res=0;
		fore(i,0,n+1)if(a[i]!=k)res+=abs(mt-a[i])/g;
		//cout<<"mt g "<<mt<<" "<<g<<"\n";
		cout<<res<<"\n";
	}
	return 0;
}
