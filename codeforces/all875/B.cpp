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
		ll a[n],b[n],c[2*n]={},d[2*n]={};
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--;
		ll q=1,w=a[0];
		fore(i,1,n){
			if(a[i]==a[i-1])q++;
			else c[w]=max(c[w],q),q=1,w=a[i];
		}
		c[w]=max(c[w],q);
		q=1,w=b[0];
		fore(i,1,n){
			if(b[i]==b[i-1])q++;
			else d[w]=max(d[w],q),q=1,w=b[i];
		}
		d[w]=max(d[w],q);
		ll res=0;
		fore(i,0,2*n)res=max(res,c[i]+d[i]);
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
