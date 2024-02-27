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
		fore(i,0,n)cin>>a[i],a[i]++;
		set<ll>b={a[0]};
		set<ii>st={{a[0],a[0]+1}};
		fore(i,1,n){
			ll v=0,l,r;
			if(b.count(a[i]+i)){
				v=(prev(st.end())->fst)-1;
				if(SZ(st)>1&&prev(prev(st.end()))->snd==v){
					l=prev(prev(st.end()))->fst,r=prev(st.end())->snd;
					st.erase(prev(st.end()));
				}
				else {
					l=v,r=prev(st.end())->snd;
				}
				st.erase(prev(st.end()));
			}
			else {
				v=a[i]+i;
				l=v,r=v+1;
				if(prev(st.end())->snd==v){
					l=prev(st.end())->fst;
					st.erase(prev(st.end()));
				}
			}
			st.insert({l,r});
			b.insert(v);
		}
		vector<ll>res;
		for(auto i:b)res.pb(i);
		reverse(ALL(res));
		imp(res);
	}
	return 0;
}
