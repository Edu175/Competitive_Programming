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

ll d;
ll f(ll i, ll j){
	return (j-i+d-1)/d;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m>>d;
		vector<ll>a(m+2);
		a[m+1]=n;
		a[0]=0;
		fore(i,1,m+1)cin>>a[i],a[i]--;
		ll sum=0;
		fore(i,0,m+1)sum+=f(a[i],a[i+1]);
		map<ll,ll>mp;
		ll res=5*sum;
		fore(i,1,m+1){
			ll resi=sum-f(a[i-1],a[i])-f(a[i],a[i+1])+f(a[i-1],a[i+1]);
			mp[resi]++;
			res=min(res,resi);
		}
		cout<<res<<" "<<mp[res]<<"\n";
	}
	return 0;
}
