#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
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
		ll n; cin>>n;
		vector<ll>a(n),res;
		fore(i,0,n)cin>>a[i];
		while(SZ(a)>1&&SZ(res)<40){
			ll x=(a.back()+a[0])/2;
			// cout<<x<<" | ";imp(a);
			res.pb(x);
			set<ll>st;
			fore(i,0,SZ(a))st.insert(abs(a[i]-x));
			a.clear();
			for(auto i:st)a.pb(i);
		}
		if(SZ(a)>1)cout<<"-1\n";
		else {
			if(a[0])res.pb(a[0]);
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
