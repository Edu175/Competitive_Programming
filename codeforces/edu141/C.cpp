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
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>b=a;
		sort(ALL(b));
		ll w=0,mi=m;
		fore(i,0,n){
			if(mi>=b[i])w++,mi-=b[i];
			else break;
		}
		//cout<<w<<"\n";
		if(w>=n){
			cout<<"1\n";
			continue;
		}
		mi=m-a[w];
		vector<ll>c;
		fore(i,0,n){
			if(i!=w)c.pb(a[i]);
		}
		sort(ALL(c));
		ll wi=1;
		for(auto i:c){
			if(mi>=i)wi++,mi-=i;
			else break;
		}
		if(mi>=0&&wi==w)w++;
		cout<<n-w+1<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
