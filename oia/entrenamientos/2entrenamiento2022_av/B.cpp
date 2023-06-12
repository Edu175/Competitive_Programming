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
		fore(i,0,n)cin>>a[i];
		set<ll>st;
		vector<pair<ll,ll>>b;
		for(ll i=n-1;i>=0;i--){
			if(!st.count(a[i]))b.pb({a[i],i});
			st.insert(a[i]);
		}
		ll m=SZ(b);
		/*fore(i,0,m){
			cout<<b[i].fst<<","<<b[i].snd<<" ";
		}
		cout<<"\n";*/
		ll res=-1;
		fore(i,0,m){
			fore(j,i,m){
				//cout<<i<<" "<<j<<": "<<gcd(b[i].fst,b[j].fst)<<" "<<b[i].snd+b[j].snd+2<<"\n";
				if(gcd(b[i].fst,b[j].fst)==1)res=max(res,b[i].snd+b[j].snd+2);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
