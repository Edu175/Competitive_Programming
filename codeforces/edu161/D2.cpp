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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll MAXN=3e5+5;

ll a[MAXN],d[MAXN];
set<ll>st;
bool dies(ll p){
	ll di=d[p];
	auto lwb=st.lower_bound(p);
	if(lwb!=st.begin())di-=a[*prev(lwb)];
	if(lwb!=prev(st.end()))di-=a[*next(lwb)];
	return di<0;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>d[i];
		st.clear();
		fore(i,0,n)st.insert(i);
		vector<ll>c;
		fore(i,0,n)c.pb(i);
		fore(_,0,n){
			ll sz=SZ(st);
			vector<ll>ci;
			//cout<<"\n"<<_<<": { "; for(auto i:c)cout<<i.fst<<","<<i.snd<<" "; cout<<"} "; imp(st);
			vector<ll>out;
			/*if(sz)*/for(auto p:c)if(st.count(p)&&dies(p))out.pb(p);
			for(auto p:out)if(st.count(p)){
				auto lwb=st.lower_bound(p);
				if(lwb!=st.begin())ci.pb(*prev(lwb));
				if(lwb!=prev(st.end()))ci.pb(*next(lwb));
				st.erase(lwb);
			}
			c=ci;
			cout<<sz-SZ(st)<<" ";
		}
		//imp(st);
		cout<<"\n";
	}
	return 0;
}
