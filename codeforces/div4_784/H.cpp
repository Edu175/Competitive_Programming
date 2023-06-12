#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k;cin>>n>>k;
		vector<ll> sum(31);
		ll res=0;
		vector<ll>v(n);
		fore(i,0,n)cin>>v[i];
		fore(j,0,31){
			fore(i,0,n)sum[j]+=(v[i]&(1ll<<j))?1:0;
		}
		for(ll i=30;i>=0;i--){
			//cout<<k-n-sum[i]<<" ";
			if(k>=n-sum[i]){
				res+=1ll<<i;
				k-=n-sum[i];
			}
		}
		/*cout<<"\n";
		fore(i,0,31)cout<<sum[i]<<" ";
		cout<<"\n";*/
		if(n==0)res=0;
		cout<<res<<"\n";
	}
	return 0;
}
