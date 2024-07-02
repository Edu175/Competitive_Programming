#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;
int main(){FIN
	#ifdef ONLINE_JUDGE
	freopen("alex.in","r",stdin);     freopen("alex.out","w",stdout);
	#endif
	
	ld n,m; cin>>n>>m;
	if(n<m)swap(n,m);
	ld res=max(min(m,n/3.0),m/2.0);
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}