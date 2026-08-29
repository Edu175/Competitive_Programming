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
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		vv per(n); iota(ALL(per),0);
		vv res;
		do{
			if(per[0]!=0)break;
			ll good=1;
			fore(i,0,n){
				good&=per[(i+1)%n]>=a[per[i]];
				// cerr<<per[(i+1)%n]<<" "<<a[per[i]]<<" >=\n";
			}
			if(good){
				res=per;
				break;
			}
		}while(next_permutation(ALL(per)));
		if(!SZ(res)){
			cout<<"No\n";
			continue;
		}
		cout<<"Yes\n";
		for(auto i:res)cerr<<i+1<<" ";
		cerr<<"\n";
	}
	return 0;
}
