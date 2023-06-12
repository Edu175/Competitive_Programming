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
		ll a[n/2],oc[n];
		mset(oc,0);
		fore(i,0,n/2)cin>>a[i],a[i]--,oc[a[i]]++;
		ll res[n],flag=1;
		fore(i,0,n)if(oc[i]>1)flag=0;
		set<ll>st;
		fore(i,0,n)st.insert(i);
		fore(i,0,n/2)st.erase(a[i]);
		for(int i=n/2-1;i>=0;i--){
			auto lwb=st.lower_bound(a[i]);
			if(lwb==st.begin()){
				flag=0;
				break;
			}
			lwb--;
			res[2*i+1]=a[i]+1;
			res[2*i]=*lwb+1;
			st.erase(*lwb);
		}
		if(flag){
			imp(res);
		}
		else cout<<"-1\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
