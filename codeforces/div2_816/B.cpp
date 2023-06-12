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
		ll n,k,b,s; cin>>n>>k>>b>>s;
		vector<ll> a(n);
		a[0]=k*b;
		s-=k*b;
		fore(i,1,n){
			a[i]=0;
		}
		for(ll i=0; i<n&&s>0; i++){
			ll add=min(k-1,s);
			a[i]+=add;
			s-=add;
		}
		if(s!=0)cout<<-1<<"\n";
		else {imp(a);}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
