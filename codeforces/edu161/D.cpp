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
vector<ll> com(ll i, ll j){
	vector<ll>ret;
	if(a[j]>d[i])ret.pb(i);
	if(a[i]>d[j])ret.pb(j);
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>d[i];
		set<ll>st;
		fore(i,0,n)st.insert(i);
		vector<ii>c;
		fore(i,0,n-1)c.pb({i,i+1});
		fore(_,0,n){
			ll sz=SZ(st);
			vector<ii>ci;
			cout<<"\n"<<_<<": { "; for(auto i:c)cout<<i.fst<<","<<i.snd<<" "; cout<<"} "; imp(st);
			for(auto [i,j]:c){
				for(auto p:com(i,j))if(st.count(p)){
					auto lwb=st.lower_bound(p);
					if(lwb!=st.begin()&&lwb!=prev(st.end())){
						ci.pb({*prev(lwb),*next(lwb)});
					}
					st.erase(lwb);
				}
			}
			c=ci;
			cout<<sz-SZ(st)<<" ";
		}
		imp(st);
		cout<<"\n";
	}
	return 0;
}
