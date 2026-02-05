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
	while(t--){
		ll n,x,y; cin>>n>>x>>y;
		string a; cin>>a;
		x=abs(x);
		y=abs(y);
		fore(i,0,n){
			if(a[i]=='4'){
				if(x>y)x--;
				else y--;
			}
			else x--,y--;
			x=max(x,0ll);
			y=max(y,0ll);
		}
		if(x==0&&y==0)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
