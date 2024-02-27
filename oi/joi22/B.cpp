#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu.fst<<","<<edu.snd<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	vector<ii>a(n),b;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	sort(ALL(a));
	fore(i,0,n){
		if(SZ(b)&&b.back().fst==a[i].fst)b.pop_back();
		b.pb(a[i]);
	}
	// cout<<SZ(b)<<"\n"; //sb1
	a=b; n=SZ(a);
	set<ii>bet;
	set<ll>st;
	fore(i,0,n)bet.insert({a[i].snd,i}),st.insert(i);
	ll res=0;
	while(SZ(st)){
		res++;
		ll p=prev(bet.end())->snd;
		vector<ll>pop={p};
		for(auto it=st.lower_bound(p);it!=st.begin();){
			it--;
			ll i=*it;
			if(!(abs(a[i].fst-a[p].fst)<=a[p].snd-a[i].snd))break;
			pop.pb(i);
		}
		for(auto it=++st.lower_bound(p);it!=st.end();it++){
			ll i=*it;
			if(!(abs(a[i].fst-a[p].fst)<=a[p].snd-a[i].snd))break;
			pop.pb(i);
		}
		for(auto i:pop)bet.erase({a[i].snd,i}),st.erase(i);
	}
	cout<<res<<"\n";
	return 0;
}
