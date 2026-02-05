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
		ll n=10;
		vv a(n);
		fore(i,1,n)cin>>a[i];
		ll res=0;
		if(a[5]>0){
			ll sum=accumulate(ALL(a),0ll);
			sum-=a[5];
			res=max(a[5]-1-sum,0ll);
		}
		else {
			ll dif=0,bad=0;
			fore(i,1,n)if(a[i]>0){
				dif++;
				auto c=(a[10-i]>0);
				bad|=c;
			}
			if(bad&&dif==2){
				res=1;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
