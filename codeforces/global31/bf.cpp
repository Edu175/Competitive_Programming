#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n,k;
vv a;
ll res;
vv ans;
void f(ll i, ll s, ll x){
	if(i==k){
		if(x==n&&s>res)res=s,ans=a;
		return;
	}
	fore(v,0,n+1){
		a.pb(v);
		f(i+1,s+v,x^v);
		a.pop_back();
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>k;
		if(k&1){
			fore(i,0,k)cout<<n<<" ";
			cout<<"\n";
			continue;
		}
		res=-1;
		ans.clear();
		f(0,0,0);
		cerr<<res<<" suma\n";
		imp(ans)
	}
	return 0;
}
