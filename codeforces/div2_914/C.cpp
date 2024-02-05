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
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		if(k>=3){
			cout<<"0\n";
			continue;
		}
		sort(ALL(a));
		vector<ll>d;
		fore(i,0,n)fore(j,i+1,n)d.pb(a[j]-a[i]);
		ll res=d[0];
		for(auto i:d)res=min(i,res);
		for(auto i:a)res=min(res,i);
		if(k==1){
			cout<<res<<"\n";
			continue;
		}
		for(auto i:d){
			ll lwb=lower_bound(ALL(a),i)-a.begin();
			if(lwb<n)res=min(res,abs(a[lwb]-i));
			if(lwb)res=min(res,abs(a[lwb-1]-i));
		}
		cout<<res<<"\n";
	}
	return 0;
}
