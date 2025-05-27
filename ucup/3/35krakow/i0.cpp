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
typedef __int128 xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
string cv(xl v) {
	// ll _v=v;
    if (v == 0) return "0";
    bool neg = v < 0;
    if (neg) v = -v;
    string s;
    while (v > 0) {
        int digit = int(v % 10);
        s.push_back('0' + digit);
        v /= 10;
    }
    if (neg) s.push_back('-');
	reverse(ALL(s));
	// cout<<"cv "<<ll(_v)<<": "<<s<<"\n";
    return s;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		sort(ALL(a));
		xl fij=0;
		
		fore(i,0,n)fij+=xl(a[i])*xl(a[i])*(n-1-i);
		
		// los triviales para un lado ^
		
		vector<xl> sp(n+1),sqp(n+1);
		fore(i,1,n+1){
			sp[i]=sp[i-1]+a[i-1];
			sqp[i]=sqp[i-1]+xl(a[i-1])*a[i-1];
		}
		
		auto get=[&](ll l, ll r, xl t){ // sumando t en el rango
			xl s=sp[r]-sp[l];
			xl sq=sqp[r]-sqp[l];
			xl ans=sq+t*t*(r-l)+2*t*s;
			return ans;
		};
		
		xl res=0;
		fore(i,0,n){
			ll l=i+1,mult=0;
			while(l<n){ // expected O(n*ln(1e12)) total
				ll r=lower_bound(ALL(a),mult)-a.begin();
				if(r<=l){
					mult+=a[i];
					continue;
				}
				res+=get(l,r,-(mult-a[i]));
				mult+=a[i];
				l=r;
			}
		}
		cout<<cv(res+fij)<<"\n";
	}
	return 0;
}

