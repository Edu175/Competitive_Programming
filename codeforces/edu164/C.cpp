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
	ll t; cin>>t;
	while(t--){
		string a,b; cin>>a>>b;
		string x,y;
		fore(i,0,SZ(a)){
			x.pb(max(a[i],b[i]));
			y.pb(min(a[i],b[i]));
		}
		fore(i,0,SZ(x)){
			if(x[i]!=y[i]){
				swap(x[i],y[i]);
				break;
			}
		}
		cout<<x<<"\n"<<y<<"\n";
	}
	return 0;
}

