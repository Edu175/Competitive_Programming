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
const ll INF=1e15;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		vv b(n+1);
		fore(i,0,n-1)b[i+1]=a[i+1]-a[i];
		b[0]=b[n]=INF;
		n++;
		imp(b);
		ll q=0;
		fore(i,0,n-1){
			if(b[i]>=0){
				ll c=min(q,b[i]);
				b[i+1]+=c;
				q-=c;
			}
			else {
				b[i+1]+=b[i];
				q+=abs(b[i]);
			}
		}
		if(q==0)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
