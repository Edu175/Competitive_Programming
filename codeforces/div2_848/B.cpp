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
		ll n,m,d; cin>>n>>m>>d;
		ll a[n],p[n];
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		ll b[m];
		fore(i,0,m)cin>>b[i],b[i]--;
		ll res=n;
		fore(i,0,m-1){
			ll dif=p[b[i+1]]-p[b[i]];
			if(dif<0||dif>d)res=0;
			res=min(res,dif);
			if(d+1<=n-1)res=min(res,d+1-dif);
		}
		cout<<max(res,(ll)0)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
