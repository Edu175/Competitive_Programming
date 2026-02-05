#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MOD=998244353;

int main(){FIN;
	string s; cin>>s;
	reverse(ALL(s));
	ll n=SZ(s);
	vector<vv> to(n,vv(n+1)); // ver de achicar
	fore(z,1,n)forr(l,0,n){
		ll r=l+z;
		if(r>=n)continue;
		ll prev=r+1<n?to[l+1][r+1]:0;
		to[l][r]=s[l]==s[r]?1+prev:0;
		to[l][r]=min(to[l][r],z);
		// cout<<"to "<<l<<","<<r<<": "<<to[l][r]<<"\n";
	}
	vector<vv> out(n,vv(n)),in(n,vv(n));
	fore(r,0,n){
		vv ev(n+3);
		fore(l,0,r){
			ev[l+1]++;
			ev[l+to[l][r+1]+1]--;
		}
		ll cnt=0;
		fore(l,0,r){
			cnt+=ev[l];
			out[l][r]=cnt;
			// cout<<"out "<<l<<","<<r<<": "<<out[l][r]<<"\n";
		}
	}
	fore(l,0,n){
		vv ev(n+3);
		fore(r,l+1,n){
			ev[r]++;
			ev[r+to[l][r]]--;
		}
		ll cnt=0;
		fore(r,l+1,n){
			cnt+=ev[r];
			in[l][r]=cnt;
			// cout<<"in "<<l<<","<<r<<": "<<in[l][r]<<"\n";
		}
	}

	vector<vv> sumin(n,vv(n)); // vals are O(n^2)
	vector<vv> sumout(n,vv(n));// vals are O(n^3)
	fore(l,0,n)fore(r,l+1,n){
		sumin[l][r]=in[l][r]+sumin[l][r-1];
	}
	fore(l,0,n)forr(r,l+1,n){
		sumout[l][r]=out[l][r]+(r+1<n?sumout[l][r+1]:0);
	}
	fore(l,0,n)fore(r,l+1,n){
		sumout[l][r]+=(l>0?sumout[l-1][r]:0);
	}
	ll res=0;
	fore(l,0,n)fore(r,l+1,n){
		ll cur=sumin[l][r-1]%MOD*sumout[l][r]%MOD;
		res=(res+cur)%MOD;
	}
	cout<<res<<"\n";
	return 0;
}
