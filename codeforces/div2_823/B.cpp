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
typedef long double ld;

int main(){FIN;
	ll _; cin>>_;
	while(_--){
		ll n; cin>>n;
		ld a[n],t[n];
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>t[i];
		ld l=1e8+5,r=-1;
		fore(i,0,n)l=min(l,a[i]-t[i]),r=max(r,a[i]+t[i]);
		cout<<fixed<<setprecision(15)<<(l+r)/2<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
