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
		ll a[n],flag=1;
		fore(i,0,n){
			cin>>a[i];
			if(i&&a[i]!=a[i-1])flag=0;
		}
		if(flag){
			cout<<"-1\n";
			continue;
		}
		vector<ll>b,c;
		sort(a,a+n);
		ll w=0;
		fore(i,0,n){
			if(i&&a[i]!=a[i-1])w=1;
			if(!w)b.pb(a[i]);
			else c.pb(a[i]);
		}
		if(!SZ(b)||!SZ(c))cout<<"-1\n";
		else {
			cout<<SZ(b)<<" "<<SZ(c)<<"\n";
			imp(b); imp(c);
		}
	}
	return 0;
}
