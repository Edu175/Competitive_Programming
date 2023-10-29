#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

void saco(ll x, multiset<ll> &st){
	st.erase(st.lower_bound(x));
}
void meto(ll x, multiset<ll> &st){
	st.insert(x);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		multiset<ll> st,dif;
		fore(i,0,n)cin>>a[i],st.insert(a[i]);
		for(auto i=st.begin();i!=st.end();i++){
			if(i==st.begin())continue;
			dif.insert(*i-*prev(i));
		}
		ll q; cin>>q;
		while(q--){
			ll k,x; cin>>k>>x; k--;
			auto p=st.lower_bound(a[k]);
			if(p!=st.begin())saco(*p-*prev(p),dif);
			if(p!=prev(st.end()))saco(*next(p)-*p,dif);
			if(p!=st.begin()&&p!=prev(st.end()))meto(*next(p)-*prev(p),dif);
			st.erase(p);
			
			a[k]=x;
			meto(x,st);
			p=st.lower_bound(a[k]);
			if(p!=st.begin())meto(*p-*prev(p),dif);
			if(p!=prev(st.end()))meto(*next(p)-*p,dif);
			if(p!=st.begin()&&p!=prev(st.end()))saco(*next(p)-*prev(p),dif);
			
			ll mx=*prev(st.end()),md=0;
			if(SZ(dif))md=*prev(dif.end());
			cout<<mx+md<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
