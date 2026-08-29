#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll comb(ll n,ll k){
	if(k>n) return 0;
	ll res = 1;
	fore(i,0,k) res*=(n-i);
	fore(i,1,k+1) res/=i;
	return res;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n+2);
		fore(i,0,n){
			ll x; cin>>x;
			x--;
			a[x]++;
		}
		// show(a);
		ll res = 0;
		fore(i,0,n){
			ll x = a[i], y = a[i+1], z = a[i+2];
			res+=comb(x,3);
			res += comb(x,2)*comb(y,1);
			res += comb(y,2)*comb(x,1);
			res+=comb(x,2)*comb(z,1);
			res+=comb(z,2)*comb(x,1);
			res += comb(x,1)*comb(y,1)*comb(z,1);
		}
		cout<<res<<"\n";
	}
	
	
	return 0;
}


