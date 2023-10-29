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
	ll n,m; cin>>n>>m;
	string a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll>p;
	fore(i,0,n)p.pb(i);
	ll res=0;
	do{
		ll flag=1;
		//imp(p);
		fore(i,1,n){
			ll c=0;
			fore(j,0,m)c+=(a[p[i]][j]!=a[p[i-1]][j]);
			//cout<<i<<": "<<c<<"\n";
			if(c!=1)flag=0;
		}
		if(flag)res=1;
	}
	while(next_permutation(ALL(p)));
	if(res)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
