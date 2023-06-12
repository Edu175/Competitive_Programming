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
		vector<ll>s(n+m),l(n+m,m+1),a(n);
		fore(i,0,n)cin>>a[i],a[i]--,l[a[i]]=0;
		fore(i,1,m+1){
			ll p,v; cin>>p>>v; p--; v--;
			s[a[p]]+=i-l[a[p]];
			l[a[p]]=m+1;
			l[v]=i;
			a[p]=v;
		}
		fore(i,0,n)s[a[i]]+=m+1-l[a[i]];
		ll res=n*m*(m+1);
		ll pre=res;
		fore(i,0,n+m)res-=s[i]*(s[i]-1)/2;
		/*imp(s);
		cout<<pre<<" "<<pre-res<<" ";*/
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
