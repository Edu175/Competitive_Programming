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
		ll n,m,k; cin>>n>>m>>k;
		vector<vector<ii>>ev(n+1);
		fore(i,0,m){
			ll l,r; cin>>l>>r; l--;
			ev[l].pb({i,1}),ev[r].pb({i,-1});
		}
		map<ll,ll>s;
		map<ii,ll>d;
		ll o=0;
		set<ll>st;
		fore(i,0,n){
			for(auto [j,x]:ev[i]){
				if(x==-1)st.erase(j);
				else st.insert(j);
			}
			if(SZ(st)==0)o++;
			if(SZ(st)==1)s[*st.begin()]++;
			if(SZ(st)==2)d[{*st.begin(),*next(st.begin())}]++;
		}
		vector<ll>b={0,0};
		for(auto [i,q]:s)b.pb(q);
		sort(ALL(b));
		ll res=b[SZ(b)-1]+b[SZ(b)-2];
		for(auto x:d){
			auto [i,j]=x.fst;
			//cout<<i<<" "<<j<<": "<<x.snd<<" "<<s[i]<<" "<<s[j]<<"\n";
			res=max(res,x.snd+s[i]+s[j]);
		}
		res+=o;
		cout<<res<<"\n";
	}
	return 0;
}
