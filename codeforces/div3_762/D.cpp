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
const ll MAXN=100005;
ll n,m;
map<ll,map<ll,ll>> a;

bool solve(ll res){
	ll fr[n],sh[m];
	mset(fr,0);
	mset(sh,0);
	fore(i,0,m){
		fore(j,0,n)if(a[i][j]>=res)fr[j]++,sh[i]++;
	}
	bool flag=0;
	fore(i,0,m)if(sh[i]>min(ll(1),m-n+1))flag=1;
	fore(j,0,n)if(fr[j]==0)flag=0;
	//imp(fr);
	//imp(sh);
	return flag;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>m>>n;
		fore(i,0,m){
			fore(j,0,n)cin>>a[i][j];
		}
		ll l=1,r=1000000005;
		while(l<=r){
			ll x=(l+r)/2;
			if(solve(x))l=x+1;
			else r=x-1;
		}
		cout<<r<<"\n";
		/*ll q; cin>>q;
		while(q--){
			ll b; cin>>b;
			cout<<solve(b)<<endl;
		}*/
	}
	return 0;
}
