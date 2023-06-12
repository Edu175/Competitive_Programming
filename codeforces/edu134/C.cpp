#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n],b[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll mind[n];
		fore(i,0,n){
			mind[i]=*lower_bound(b,b+n,a[i])-a[i];
		}
		ll can[n+1];
		mset(can,0);
		fore(i,1,n){
			if(b[i-1]>=a[i])can[i]=1;
		}
		ll pos[n+1];
		mset(pos,0);
		ll r=n-1;
		for(ll i=n; i>0; i--){
			if(!can[i])r=i-1;
			pos[i]=r;
		}
		ll maxd[n];
		fore(i,0,n){
			maxd[i]=b[pos[i+1]]-a[i];
		}
		imp(mind);
		//imp(can);
		//imp(pos);
		imp(maxd);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
