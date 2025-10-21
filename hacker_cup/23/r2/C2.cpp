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
const ll MAXN=1e6+5;

vector<int> g[MAXN];

int main(){FIN;
	ll t; cin>>t;
	fore(_,1,t+1){
		cout<<"Case #"<<_<<": ";
		ll n; cin>>n;
		fore(i,0,n){
			g[i].clear();
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		vector<string> s[n];
		set<ll>w[n];
		map<string,ll>mp;
		fore(i,0,n){
			ll m; cin>>m; s[i].resize(m);
			fore(j,0,m)cin>>s[i][j],mp[s[i][j]]=-1;
		}
		ll k=0;
		for(auto &i:mp)i.snd=k++;
		set<ll>inv[k];
		fore(i,0,n){
			fore(j,0,SZ(s[i])){
				ll v=mp[s[i][j]];
				w[i].insert(v);
				inv[v].insert(i);
			}
		}
		ll res=0;
		fore(c,0,k){
			vector<ll>nod;
			for(auto i:inv[c])nod.pb(i);
			sort(ALL(nod),cmp);
			reverse(ALL(nod));
			for(auto x:nod){
				if(dad[x]!=-1&&st.query(pos[dad[x]],pos[dad[x]]+1))upd(x,-1);
			}
			if(st.query(0,n)<=1){
				if(!st.query(pos[0],pos[0]+1)||inv[c].count(0))res++;
			}
			st.reset();
			//cout<<res-ans<<"\n\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
