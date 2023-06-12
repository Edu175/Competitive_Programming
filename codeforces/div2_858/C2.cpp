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
		ll a[2*n];
		fore(i,0,2*n)cin>>a[i];
		sort(a,a+2*n);
		if(n==1){
			cout<<abs(a[1]-a[0])<<"\n";
			continue;
		}
		ll res0=0,res1=0,res2=0;
		fore(i,0,2*n){
			res0+=abs(a[i]);
			if(i==2*n-1)res1+=abs(a[i]-n);
			else res1+=abs(a[i]-(-1));
			if(n==2)res2+=abs(a[i]-2);
		}
		ll res=min(res0,res1);
		if(n==2)res=min(res,res2);
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

