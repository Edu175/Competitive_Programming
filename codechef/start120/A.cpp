#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),res(n+1);
		fore(i,0,n)cin>>a[i];
		fore(l,0,n){
			ll sum=0;
			fore(r,l,n){
				sum+=a[r];
				if(sum<=n)res[sum]++;
				else break;
			}
		}
		fore(i,1,n+1)cout<<res[i]<<" ";
		cout<<"\n";
	}
	return 0;
}
