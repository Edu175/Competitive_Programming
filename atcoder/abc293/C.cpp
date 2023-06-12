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
	ll a[n][m];
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	vector<ll>mk(n-1,0); fore(i,0,m-1)mk.pb(1);
	sort(ALL(mk));
	ll res=0;
	do{
		set<ll>st;
		ll i=0,j=0;
		st.insert(a[i][j]);
		fore(k,0,SZ(mk)){
			if(mk[k])j++;
			else i++;
			st.insert(a[i][j]);
		}
		res+=(SZ(st)==n+m-1);
	}
	while(next_permutation(ALL(mk)));
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
