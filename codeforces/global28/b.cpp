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
		ll n,k; cin>>n>>k;
		vv res(n,-1);
		ll cnt=0,pos=k-1;
		fore(i,0,n){
			if(pos>=n)break;
			res[pos]=cnt++;
			pos+=k;
		}
		fore(i,0,n)if(res[i]==-1)res[i]=cnt++;
		fore(i,0,n)cout<<res[i]+1<<" ";;cout<<"\n";
	}
	return 0;
}
