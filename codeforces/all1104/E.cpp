#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n){
			cin>>b[i];
			if(b[i]!=-1)b[i]--;
		}
		vv vis(n);
		vv in(n);
		ll valid=1;
		auto go=[&](ll x, ll y){
			while(!vis[x]){
				if(b[x]!=-1&&b[x]!=y)valid=0;
				if(in[y])valid=0;
				b[x]=y;
				vis[x]=1; in[y]=1;
				x=a[x],y=a[y];
			}
		};
		fore(x,0,n){
			ll y=b[x];
			if(y!=-1)go(x,y);
		}
		if(!valid){
			// cerr<<"primera\n";
			cout<<"NO\n";
			continue;
		}
		// show(b)
		vector<vv> av(n+1);
		vv vis2(n);
		vv zs(n);
		fore(x,0,n)if(!vis2[x]){
			vv c;
			for(ll y=x;!vis2[y];y=a[y]){
				c.pb(y);
				vis2[y]=1;
			}
			ll mn=*min_element(ALL(c));
			// cerr<<"cycle "; show(c)
			ll z=SZ(c);
			if(!in[x])av[z].pb(mn);
			for(auto y:c)zs[y]=z;
		}
		fore(i,0,n+1){
			sort(ALL(av[i]));
			reverse(ALL(av[i]));
		}
		fore(x,0,n)if(b[x]==-1){
			ll z=zs[x];
			auto &v=av[z];
			if(!SZ(v)){valid=0;break;}
			ll y=v.back(); v.pop_back();
			// cerr<<"mando "<<x<<","<<y<<"\n";
			go(x,y);
		}
		if(!valid){
			// cerr<<"segunda\n";
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(auto i:b)cout<<i+1<<" ";;cout<<"\n";
	}
	return 0;
}
