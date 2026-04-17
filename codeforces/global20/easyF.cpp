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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		vector<vv> pos(n);
		fore(i,0,n)cin>>a[i],a[i]--,pos[a[i]].pb(i);
		vv res(n);
		set<ll> st;
		fore(i,0,n)if(SZ(pos[i]))st.insert(i);
		while(SZ(st)){
			vv vs,ids;
			for(auto v:st){
				auto &vec=pos[v];
				vs.pb(v);
				ids.pb(vec.back());
			}
			rotate(vs.begin(),vs.begin()+1,vs.end());
			for(auto v:vs){
				auto &vec=pos[v];
				vec.pop_back();
				if(!SZ(vec))st.erase(v);
			}
			fore(i,0,SZ(vs))res[ids[i]]=vs[i];
		}
		for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
		
	}
	return 0;
}
