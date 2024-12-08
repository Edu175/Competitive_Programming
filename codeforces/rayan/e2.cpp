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


vector<vv> make3(ll n){
	vector<vv>a;
	vv per(n); iota(ALL(per),0);
	a.pb(per);
	rotate(per.begin(),per.begin()+n/2,per.end());
	a.pb(per);
	vector<ii>ind;
	fore(i,0,n)ind.pb({a[0][i]+a[1][i],i});
	sort(ALL(ind));
	reverse(ALL(ind));
	fore(i,0,n)per[ind[i].snd]=i;
	a.pb(per);
	return a;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		if(n==1){
			cout<<"YES\n";
			fore(i,0,k)cout<<"1\n";
			continue;
		}
		if(k%2==0){
			cout<<"YES\n";
			vv per(n); iota(ALL(per),1);
			fore(i,0,k){
				imp(per);
				reverse(ALL(per));
			}
		}
		else if((n&1)&&k>1){
			auto a=make3(n);
			cout<<"YES\n";
			for(auto v:a){
				for(auto i:v)cout<<i+1<<" ";
				cout<<"\n";
			}
			k-=3;
			vv per(n); iota(ALL(per),1);
			fore(i,0,k){
				imp(per);
				reverse(ALL(per));
			}
		} else cout<<"NO\n";
	}
	return 0;
}