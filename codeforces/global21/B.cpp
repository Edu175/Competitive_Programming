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
		ll c=count(ALL(a),0);
		if(c==n){
			cout<<"0\n";
			continue;
		}
		ll l=0,r=n-1;
		while(!a[l])l++;
		while(!a[r])r--;
		c=count(a.begin()+l,a.begin()+r,0);
		ll res=0;
		if(c==n)res=0;
		else if(c==0)res=1;
		else res=2;
		cout<<res<<"\n";
	}
	return 0;
}
