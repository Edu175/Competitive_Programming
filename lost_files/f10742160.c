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
	ll n,m,d; cin>>n>>m>>d;
	ll a[n],b[m];
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	sort(a,a+n); sort(b,b+m);
	ll res=-1;
	fore(i,0,n){
		ll l=0,r=m-1;
		while(l<=r){
			ll c=(l+r)/2;
			if(b[c]-a[i]<=d)l=c+1;
			else r=c-1;
		}
		if(r>=0&&abs(a[i]-b[r])<=d)res=max(res,a[i]+b[r]);
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
