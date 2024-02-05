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
		vector<ii>b;
		ll cnt=0;
		fore(i,0,n)cin>>a[i],b.pb({a[i],i}),cnt+=(a[i]==0);
		sort(ALL(b));
		set<ii>st;
		ll flag=(cnt==1);
		for(auto p:b){
			swap(p.fst,p.snd);
			st.insert({p});
			auto [i,v]=p;
			if(v==0)continue;
			auto lwb=st.lower_bound(p);
			ll god=0;
			if(lwb!=st.begin()&&prev(lwb)->snd>=v-1)god|=1;
			if(lwb!=prev(st.end())&&next(lwb)->snd>=v-1)god|=1;
			//cout<<i<<" "<<v<<": "<<god<<"\n";
			flag&=god;
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
