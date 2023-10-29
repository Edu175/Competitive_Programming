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

ll factor2(ll x){
	ll res=0;
	while(x%2==0){
		res++;
		x/=2;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[2*n];
		ll e=0, o=0;
		vector<ll> ev;
		fore(i,0,2*n){
			cin>>a[i];
			if(a[i]%2)o++;
			else e++, ev.pb(factor2(a[i]));
		}
		ll res=0;
		if(o>e)res=o-n;
		else if(o==n)res=0;
		else {
			sort(ALL(ev));
			fore(i,0,e-n)res+=ev[i];
		}
		//imp(ev);
		pres;
	}
	return 0;
}
