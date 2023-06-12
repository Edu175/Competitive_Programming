#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n; vector<pair<ll,ll>>a(n);
		vector<vector<ll>>v(150001);
		vector<ll>w(150001);
		fore(i,0,n){
			cin>>a[i].fst;
			a[i].snd=i;
			w[a[i].fst]++;
			v[a[i].fst].pb(a[i].snd);
		}
		ll res=0;
		ll var=0;
		fore(i,0,150001)if(w[i]>=2){
			var=1;
			ll lng=SZ(v[i]);
			fore(j,0,lng-1)res=max(res,v[i][j]-v[i][j+1]+n);
		}
		if(var)cout<<res<<"\n";
		else cout<<-1<<"\n";
		
	}
	 return 0;
}
