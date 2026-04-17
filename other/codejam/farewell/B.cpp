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
const ll INF=1e9+5;

int main(){FIN;
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n,q; cin>>n>>q;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		multiset<pair<ll,ll>>pu;
		multiset<ll>wh;
		fore(i,0,n)pu.insert({a[i],i});
		ll s=0;
		while(q--){
			ll x; cin>>x;
			ll res=0;
			if(x>0){
				vector<pair<ll,ll>>rem;
				pair<ll,ll>f={s,-1};
				auto g=pu.lower_bound(f);
				ll e=min((*g).fst+1,s+x);
				vector<ll>r;
				for(auto j=wh.lower_bound(s);j!=wh.end()&&*j<e;j++)r.pb(*j),res++;
				for(auto j:r)wh.erase(wh.lower_bound(j));
				for(auto i=g;i!=pu.end()&&(*i).fst<=s+x;i++){
					wh.insert(b[(*i).snd]);
					ll e=min(next(*i).fst+1,s+x);
					vector<ll>r;
					for(auto j=wh.lower_bound((*i).fst);j!=wh.end()&&*j<e;j++)
						r.pb(*j),res++;
					for(auto j:r)wh.erase(wh.lower_bound(j));
					rem.pb(*i);
				}
				for(auto j:rem)pu.erase(pu.lower_bound(j));
				s+=x;
			}
			else{
				vector<pair<ll,ll>>rem;
				pair<ll,ll>f={s,INF};
				auto g=pu.lower_bound(f); g--;
				ll e=max((*g).fst-1,s+x);
				vector<ll>r;
				auto em=wh.lower_bound(s+1); em--; auto cut=wh.begin(); cut--;
				for(auto j=em;j!=cut&&*j>e;j--)r.pb(*j),res++;
				for(auto j:r)wh.erase(wh.lower_bound(j));
				cut=pu.begin(); cut--;
				for(auto i=g;i!=cut&&(*i).fst>=s+x;i--){
					wh.insert(b[(*i).snd]);
					ll e=max(prev(*i).fst-1,s+x);
					vector<ll>r;
					auto em=wh.lower_bound((*i).fst+1);em--; auto cut=wh.begin(); cut--;
					for(auto j=em;j!=cut&&*j>e;j--)r.pb(*j),res++;
					for(auto j:r)wh.erase(wh.lower_bound(j));
					rem.pb(*i);
				}
				for(auto j:rem)pu.erase(pu.lower_bound(j));
				s+=x;
			}
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
// NO FAREWELL: KEEP GOOGLE COMPETITIONS ALIVE
