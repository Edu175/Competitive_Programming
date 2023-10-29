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
const ll MOD=998244353;

ll cnt(ll l,ll r,ll i){
	i-=l;
	ll m=r-l;
	return (i*(m-i-1)%MOD+(((i+1)*i)/2+i+1)%MOD)%MOD;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n+1];
		a[n]=n;
		fore(i,0,n)cin>>a[i],a[i]--;
		ll ext[n+1];
		set<ll>st;
		fore(i,0,n+1){
			vector<ll>del;
			for(auto j:st){
				if(j<a[i])ext[j]=i,del.pb(j);
				else break;
			}
			for(auto j:del)st.erase(j);
			st.insert(a[i]);
		}
		//imp(ext);
		ll l=0,r=0,res=0;
		while(l<n&&r<n){
			if(r+1==n||a[r+1]<a[r]){
				res=res+cnt(l,ext[a[r]],r)%MOD;
				//cout<<l<<" "<<ext[a[r]]<<" "<<r<<": ";
				//cout<<cnt(l,ext[a[r]],r)<<"\n";
				r++;
				l=r;
			}
			else r++;
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
