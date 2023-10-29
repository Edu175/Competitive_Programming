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
	ll n; cin>>n;
	vector<ll>v[2];
	fore(i,0,n){
		ll x;cin>>x;
		v[x&1].pb(x);
	}
	sort(ALL(v[0])); reverse(ALL(v[0]));
	sort(ALL(v[1])); reverse(ALL(v[1]));
	//imp(v[0]);
	//imp(v[1]);
	ll res=-1;
	if(SZ(v[0])>=2)res=max(res,v[0][0]+v[0][1]);
	if(SZ(v[1])>=2)res=max(res,v[1][0]+v[1][1]);
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
