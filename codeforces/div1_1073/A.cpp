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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s; cin>>s;
		auto f=[&](ll l, ll r, auto &&f)->deque<ll> {
			while(l<=r&&s[l]=='0')l++;
			while(l<=r&&s[r]=='1')--r;
			if(l>r)return {};
			auto mov=f(l+1,r-1,f);
			// if(!SZ(mov))return {l,r};
			// else
			mov.push_front(l),mov.pb(r);
			return mov;
		};
		auto res=f(0,n-1,f);
		if(!SZ(res))cout<<"Bob\n";
		else {
			cout<<"Alice\n";
			cout<<SZ(res)<<"\n";
			for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
		}
	}
	return 0;
}
