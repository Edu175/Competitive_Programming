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
const ll MAXV=1e6+5;

int main(){FIN;
	#ifdef ONLINE_JUDGE
    freopen("deposits.in","r",stdin);     freopen("deposits.out","w",stdout);
    #endif
	ll n; cin>>n;
	vector<ll>a(n),c(MAXV),d(MAXV);
	fore(i,0,n)cin>>a[i],c[a[i]]++;
	ll m; cin>>m;
	vector<ll>b(m);
	fore(i,0,m)cin>>b[i],d[b[i]]++;
	ll res=0;
	fore(v,1,MAXV)for(ll j=0;j<MAXV;j+=v){
		res+=c[j]*d[v];
	}
	cout<<res<<"\n";
	return 0;
}