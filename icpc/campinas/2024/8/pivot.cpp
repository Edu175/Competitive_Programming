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
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	set<ll>l={a[0]},r;
	fore(i,0,n)r.insert(a[i]);
	vector<ll>res;
	fore(i,0,n){
		if(*prev(l.end())==a[i]&&*r.begin()==a[i])res.pb(a[i]);
		if(i<n-1)l.insert(a[i+1]);
		r.erase(a[i]);
	}
	for(auto i:res)cout<<i<<"\n";
	return 0;
}
