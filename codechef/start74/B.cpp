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
		ll a[n];
		vector<ll>oc(n,0),ob(n,0);
		fore(i,0,n)cin>>a[i],a[i]--,oc[a[i]]++;
		ll res=0,resi=0;
		for(int i=n-1;i>=0;i--){
			oc[a[i]]--; ob[a[i]]++;
			if(a[i])resi-=ob[a[i]-1];
			if(a[i]<n-1)resi+=oc[a[i]+1];
			res=max(res,resi);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home