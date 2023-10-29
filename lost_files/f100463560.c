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
		vector<vector<ll>>v(n);
		vector<ll>w(n);
		fore(i,0,n){
			cin>>a[i].fst;
			a[i].snd=i;
			w[a[i].fst]++;
			v[a[i].fst].pb(a[i].snd);
		}
		/*for(auto i:w)cout<<i<<" ";
		cout<<"\n";
		for(auto i:v){
			for(auto j:i)cout<<j;
			cout<<" ";
		}
		cout<<"\n";*/
		ll res=0;
		ll var=0;
		fore(i,0,n)if(w[i]>=2){
			var=1;
			/*cout<<i<<"   ";
			for(auto j:v[i])cout<<j<<" ";
			cout<<"\n";*/
			ll lng=SZ(v[i]);
			//for(auto j:v[i])lng++;
			//cout<<lng<<"\n";
			fore(j,0,lng-1)res=max(res,v[i][j]-v[i][j+1]+n);
			///cout<<res<<"\n";
		}
		if(var)cout<<res<<"\n";
		else cout<<-1<<"\n";
		
	}
	 return 0;
}
