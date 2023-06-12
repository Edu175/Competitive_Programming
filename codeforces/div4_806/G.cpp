#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll a[n];
		ll sum=0;
		ll maxi=0;
		fore(i,0,n)cin>>a[i], sum+=a[i],maxi=max(maxi,a[i]);
		ll c[64-__builtin_clzll(maxi)+5];
		mset(c,0);
		fore(i,0,n){
			fore(j,0,64-__builtin_clzll(a[i])-1){
				if((a[i]&(1ll<<j))==(1ll<<j))c[j]++;
			}
		}
		ll res=0;
		ll j=0;
		fore(i,0,n){
			ll cost=(sum+c[j])/2-c[j];
			//cout<<a[i]/(1ll<<j)<<": "<<sum-k<<" "<<cost<<"--> ";
			if(sum-k<cost){
				//cout<<"cost "<<c[j]<<" ";
				sum=cost, j++;
				res+=a[i]/(1ll<<j);
			}
			else {
				res+=a[i]/(1ll<<j)-k;
				//cout<<"k ";
			}
			fore(h,0,64-__builtin_clzll(a[i])-1){
				if((a[i]&(1ll<<h))==(1ll<<h))c[h]--;
			}
			sum-=a[i]/(1ll<<j);
			//cout<<res<<"\n";
		}
		cout<<res<<"\n";
	}
	return 0;
}
