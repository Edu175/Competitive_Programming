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
	fore(__,0,t){
		cout<<"Case #"<<__+1<<": ";
		ll n; cin>>n;
		vv a(n),b(n);
		vector<ii> sb;
		vv idx(n,-1);
		fore(i,0,n)cin>>a[i],a[i]--,idx[a[i]]=i;
		fore(i,0,n)cin>>b[i],b[i]--,sb.pb({b[i],i});
		sort(ALL(sb));
		vector<ii> res;
		ll fg=1;
		for(auto [asd,i]:sb)if(a[i]!=b[i]){
			ll j=idx[b[i]];
			res.pb({i,j});
			fg&=j!=-1;
			fg&=a[i]<=b[i];
		}
		if(!fg)cout<<"-1\n";
		else {
			cout<<SZ(res)<<"\n";
			for(auto [i,j]:res)cout<<i+1<<" "<<j+1<<"\n";
		}
	}
	return 0;
}
