#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,k; cin>>n>>k; k--;
	vector<ll>a(n),d;
	fore(i,0,n)cin>>a[i];
	ll res=a[n-1]-a[0];
	fore(i,0,n-1)d.pb(a[i+1]-a[i]);
	sort(ALL(d)); reverse(ALL(d));
	fore(i,0,min(k,(ll)SZ(d)))res-=d[i];
	cout<<res<<"\n";
	return 0;
}
