#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
    int t; cin>>t;
    while(t--){
		vv c(10);
		ll sum=0;
		fore(i,0,10)cin>>c[i],sum+=c[i];
		if(sum==1&&c[0]){
			cout<<"0\n";
			continue;
		}
		auto can=[&](ll u){
			ll sum=0;
			for(auto i:c)sum+=i;
			ll flag=c[u]<=sum/2;
			fore(i,0,10)if(i!=u)flag&=c[i]<=(sum+1)/2;
			return flag;
		};
		if(!can(0)){cout<<"-1\n";continue;}
		vv res; ll u=0;
		fore(_,0,sum){
			fore(i,0,10)if(i!=u&&c[i]){
				c[i]--;
				if(can(i)){res.pb(i);u=i;break;}
				c[i]++;
			}
		}
		for(auto i:res)cout<<i;;cout<<"\n";
		
    }
    return 0;
}
