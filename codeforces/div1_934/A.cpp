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
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),c(n);
		fore(i,0,n)cin>>a[i],c[a[i]]++;
		sort(ALL(a));
		ll p=-1,d=0;
		fore(i,0,n){
			if(c[a[i]]==1){
				if(d==1)p=i;
				d++;
			}
		}
		set<ll>st;
		fore(i,0,n+5)st.insert(i);
		fore(i,0,n)if(i!=p)st.erase(a[i]);
		cout<<*st.begin()<<"\n";
	}
	return 0;
}
