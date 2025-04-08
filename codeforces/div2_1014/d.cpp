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
string lit="LIT";
ll trad(char c){return find(ALL(lit),c)-lit.begin();}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		vv a(n);
		vv oc(3);
		fore(i,0,SZ(s))a[i]=trad(s[i]),oc[a[i]]++;
		vector<ii>soc; fore(i,0,3)soc.pb({oc[i],i});
		sort(ALL(soc));
		vv pos(3);
		fore(i,0,3)pos[soc[i].snd]=i,oc[i]=soc[i].fst;
		fore(i,0,n)a[i]=pos[a[i]];
		
		// 0 1 2 
		// -> most occurences
		vv res;
		ll good=1;
		while(oc[0]!=oc[2]||oc[1]!=oc[2]){
			n=SZ(a);
			ll p=-1,w=-1;
			fore(i,0,n-1)if(a[i]!=a[i+1]){
				ll o=a[i]^a[i+1]^3;
				if(oc[o]<oc[2]){p=i;w=o;break;}
			}
			if(p==-1){good=0;break;}
			// imp(a)
			// cout<<p<<" "<<w<<"\n\n";
			res.pb(p); oc[w]++;
			a.insert(a.begin()+1+p,w);
		}
		// imp(a)
		// imp(oc)
		if(!good)cout<<"-1\n";
		else {
			cout<<"PINGA\n";
			// cout<<SZ(res)<<"\n";
			// for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
		}
		// cout<<"\n\n";
	}
	return 0;
}
