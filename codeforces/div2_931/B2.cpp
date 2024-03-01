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
const ll MAXV=1e6;
vector<ll>cs={1, 3, 6, 30};
vector<ll>cost={1,1,1,2};
ll solve(ll n){
	ll res=0;
	while(n){
		ll c=upper_bound(ALL(cs),n)-1-cs.begin();
		ll q=n/cs[c];
		res+=q*cost[c];
		n-=q*cs[c];
	}
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll res=n;
		fore(i,0,3)fore(j,0,2){
			ll ni=n-i*10-j*15;
			if(ni>=0){
				res=min(res,solve(ni)+i+j);
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
