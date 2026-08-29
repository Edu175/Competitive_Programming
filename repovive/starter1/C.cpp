#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
// const ll MAXS=2e8+100;
// bitset<2*MAXS> dp;


int main(){FIN;
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	ll tot=accumulate(ALL(a),0ll);
	ll r=0,sum=0;
	ll mn=tot;
	fore(i,0,n){
		while(r<n&&sum<tot-sum)sum+=a[r++];
		ll cur=abs(sum-(tot-sum));
		mn=min(mn,cur);
		sum-=a[i];
	}
	cout<<mn<<"\n";
	return 0;
}
