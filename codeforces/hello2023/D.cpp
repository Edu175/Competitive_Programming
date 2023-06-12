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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		map<ll,vector<ll>>oc;
		vector<ll>num;
		ll flag=1;
		fore(i,0,n){
			cin>>b[i];
			if(b[i]>a[i])flag=0;
			oc[b[i]].pb(i);
		}
		for(auto i:oc)num.pb(i.fst);
		sort(ALL(num));
		reverse(ALL(num));
		ll m; cin>>m;
		ll c[m];
		map<ll,ll>q;
		fore(i,0,m)cin>>c[i],q[c[i]]++;
		set<ll>vis;
		for(auto i:num){
			set<ll>rn;
			for(auto j:oc[i]){
				if(a[j]==i)continue;
				auto l=vis.lower_bound(j+1);//,r=*vis.lower_bound(j+1);
				if(l==vis.end())rn.insert(-1);
				else rn.insert(*l);
			}
			if(SZ(rn)>q[i])flag=0;
			/*cout<<i<<":\n";
			imp(vis);
			imp(oc[i]);
			cout<<SZ(rn)<<" "<<q[i]<<": "<<flag<<"\n\n";*/
			for(auto j:oc[i])vis.insert(j);
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
