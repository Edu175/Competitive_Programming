#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		vector<string>a(n);
		set<string>st;
		fore(i,0,n){
			cin>>a[i];
			ll c=0;
			for(auto j:a[i])c+=j=='1';
			if(c==1)st.insert(a[i]);
		}
		if(SZ(st)==k)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
