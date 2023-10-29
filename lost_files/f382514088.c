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
	vector<ll> a[m];
	set<ll> st[m];
	fore(i,0,m){
		ll k; cin>>k;
		fore(j,0,k){
			ll x; cin>>x; x--;
			a[i].pb(x);
			st[i].insert(x);
		}
	}
	ll flag=1;
	fore(i,0,n){
		fore(j,i+1,n){
			ll fl=0;
			fore(k,0,m){
				if(st[k].count(i)&&st[k].count(j))fl=1;
			}
			if(fl==0)flag=0;//,cout<<i<<" "<<j<<"\n";
		}
	}
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
