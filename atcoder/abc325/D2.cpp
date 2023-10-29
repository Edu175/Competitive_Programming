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
	ll n; cin>>n;
	ii a[n];
	vector<ii>ra;
	fore(i,0,n){
		ll t,d; cin>>t>>d;
		a[i].fst=t,a[i].snd=t+d+1;
		ra.pb({a[i].snd,a[i].fst});
	}
	sort(ALL(ra));
	set<ll>out,in;
	ll res=0;
	for(auto [r,l]:ra){
		if(!out.count(l)){
			res++;
			out.insert(l);
			in.erase(l);
			if(!out.count(l+1))in.insert(l+1);
		}
		else{
			ll x=*in.lower_bound(l);
			if(x>=r)continue;
			res++;
			in.erase(x);
			if(!out.count(x+1))in.insert(x+1);
			out.insert(x);
		}
	}
	cout<<res<<"\n";
	return 0;
}
