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
	ll a,b,c,x,y,z; cin>>a>>b>>c>>x>>y>>z;
	a-=x,b-=y,c-=z;
	ll have=0,need=0;
	if(a<0)need+=-a;
	else have+=a/2;

	if(b<0)need+=-b;
	else have+=b/2;

	if(c<0)need+=-c;
	else have+=c/2;
	
	if(have>=need)cout<<"Yes\n";
	else cout<<"No\n";
	
	return 0;
}