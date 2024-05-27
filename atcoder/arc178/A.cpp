#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll>a(m),is(n);
	fore(i,0,m)cin>>a[i],a[i]--,is[a[i]]=1;
	if(is[0]||is[n-1])cout<<"-1\n";
	else {
		vector<ll>res,p;
		fore(i,0,n){
			if(is[i]){
				res.pb(i+1);
				if(!is[i-1])p.pb(i);
			}
			else {
				if(SZ(p))res.pb(p[0]),p.clear();
				else res.pb(i);
			}
		}
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}
