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
		ll n,m,k; cin>>n>>m>>k;
		ll a[n],b[m];
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		sort(a,a+n); sort(b,b+m);
		if(a[0]<b[m-1]){
			swap(a[0],b[m-1]);
			sort(a,a+n); sort(b,b+m);
		}
		k--;
		if(k&1)swap(a[n-1],b[0]);
		ll res=0;
		fore(i,0,n)res+=a[i];
		cout<<res<<"\n";
	}
	return 0;
}
