#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXV=1e6;

int main(){FIN;
	while(1){
		ll n; cin>>n;
		if(!n)break;
		string nom[n];
		ll sz[n]={};
		map<ll,vector<ll>> w;
		fore(i,0,n){
			cin>>nom[i];
			while(1){
				ll x; cin>>x; x--;
				if(x==-1)break;
				w[x].pb(i);
				sz[i]++;
			}
		}
		vector<string>res;
		ll m; cin>>m;
		ll a[m];
		fore(i,0,m)cin>>a[i],a[i]--;
		fore(i,0,n)if(!sz[i])res.pb(nom[i]);
		if(SZ(res)){
			sort(ALL(res));
			fore(i,0,SZ(res)){
				if(i)cout<<" ";
				cout<<res[i];
			}
			cout<<"\n";
			continue;
		}
		fore(j,0,m){
			//cout<<a[j]<<": ";
			for(auto i:w[a[j]]){
				sz[i]--;
				//cout<<i<<","<<sz[i]<<" ";
				if(sz[i]==0)res.pb(nom[i]);
			}
			//cout<<"\n";
			if(SZ(res))break;
		}
		sort(ALL(res));
		fore(i,0,SZ(res)){
			if(i)cout<<" ";
			cout<<res[i];
		}
		cout<<"\n";
	}
	return 0;
}
