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
		ll n,m,h; cin>>n>>m>>h;
		ll a[n][m];
		fore(i,0,n)fore(j,0,m)cin>>a[i][j];
		vector<ii>r;
		ii po={0,0};
		fore(i,0,n){
			sort(a[i],a[i]+m);
			ll s=0;
			ii p={0,0};
			fore(j,0,m){
				if(s+a[i][j]<=h)s+=a[i][j],p.fst--,p.snd+=s;
			}
			//cout<<i<<": "<<p.fst<<","<<p.snd<<endl;
			if(i)r.pb(p);
			else po=p;
		}
		sort(ALL(r));
		/*for(auto i:r)cout<<i.fst<<","<<i.snd<<" ";
		cout<<endl;
		cout<<po.fst<<","<<po.snd<<endl;*/
		ll res=lower_bound(ALL(r),po)-r.begin();
		cout<<res+1<<"\n";
	}
	return 0;
}
