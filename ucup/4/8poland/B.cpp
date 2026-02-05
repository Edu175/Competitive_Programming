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
	ll n; cin>>n;
	vv a(n),p(n);
	fore(i,0,n){
		cin>>a[i]; a[i]--;
		p[a[i]]=i;
	}
	set<ll> st;
	fore(i,0,n)st.insert(i);
	ll c=0;
	auto it=st.begin();
	auto expand=[&](){ // it esta bien
		while(it!=st.end()&&(it==st.begin()||a[*prev(it)]<a[*it])){
			it++;
			c++;
		}
	};
	expand();
	ll res=c;
	// cout<<"inicial: "<<c<<"\n";
	fore(x,0,n){
		ll i=p[x];
		if(it==st.end()||i<*it)c--;
		if(it!=st.end()&&*it==i)it=next(it);
		st.erase(i);
		expand();
		res=max(res,c);
		// cout<<"saco x="<<x<<": "<<c<<"\n";
	}
	res=n-res;
	cout<<res<<"\n";
	return 0;
}
