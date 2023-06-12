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
const ll INF=1e9+5;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),v;
		v.pb(INF);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n){
			if(i&&a[i]==a[i-1])continue;
			v.pb(a[i]);
		}
		v.pb(INF);
		//imp(v);
		ll res=0;
		fore(i,1,SZ(v)-1){
			if(v[i-1]>v[i]&&v[i+1]>v[i])res++;//,cout<<i-1<<" ";
		}
		//cout<<"\n";
		if(res==1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
