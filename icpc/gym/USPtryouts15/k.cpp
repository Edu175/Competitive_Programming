#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

const ld EPS = 1e-14;
ld heron(ld a, ld b, ld c){
	ld s = (a+b+c)/2;
	s*=(s-a)*(s-b)*(s-c);
	return sqrtl(s);
}

int main(){
	JET
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<ld> a(n);
		fore(i,0,n) cin>>a[i];
		sort(ALL(a));
		ld res = 0;
		ll did=0;
		// for(auto i:a)cout<<i<<" ";;cout<<"\n";
		fore(i,0,n){
			fore(j,i+1,n-1){
				auto cumple=[&](ll k){
					return a[i]+a[j]>a[k]+EPS;
				};
				auto proba=[&](ll k){
					if(cumple(k)){
						auto resi=heron(a[i],a[j],a[k]);
						if(!did||resi<res)res=resi;
						did=1;
					}
				};
				proba(j+1);
				ll l=j+1,r=n-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(cumple(m))l=m+1;
					else r=m-1;
				}
				// cout<<i<<" "<<j<<": "<<r<<"\n";
				if(r>j){
					// cout<<"<losdlighk\n";
					assert(cumple(r));
					proba(r);
				}
				else assert(!cumple(j+1));
			}
		}
		if(!did){
			cout<<"-1\n";
			continue;
		}
		cout<<fixed<<setprecision(16)<<res<<"\n";
	}
	return 0;
}