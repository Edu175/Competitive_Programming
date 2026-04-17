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
		vv a(n);
		fore(i,0,n)cin>>a[i];
		string s; cin>>s;
		ll l=0,r=n-1,sum=accumulate(ALL(a),0ll),res=0;
		while(l<=r){
			if(s[l]=='R')sum-=a[l++];
			else if(s[r]=='L')sum-=a[r--];
			else res+=sum,sum-=a[l++],sum-=a[r--];
		}
		cout<<res<<"\n";
	}
	return 0;
}