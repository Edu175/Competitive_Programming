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
	#ifdef ONLINE_JUDGE
    freopen("key.in","r",stdin);     freopen("key.out","w",stdout);
    #endif
	ll n,m; cin>>n>>m;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	ll u=1,j=0;
	while(m){
		if(j<n&&a[j]<=u)u+=a[j++];
		else m--,cout<<u<<" ",u*=2;
	}
	cout<<"\n";
	return 0;
}