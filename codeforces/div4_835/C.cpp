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
		ll n; cin>>n;
		vector<ll>a(n);
		vector<pair<ll,ll>>srt(n);
		fore(i,0,n)cin>>a[i],srt[i].fst=a[i],srt[i].snd=i;
		sort(ALL(srt));
		reverse(ALL(srt));
		fore(i,0,n){
			ll res=a[i]-srt[0].fst;
			if(srt[0].snd==i)res=a[i]-srt[1].fst;
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
