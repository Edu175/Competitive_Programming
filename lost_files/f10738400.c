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

int main(){FIN;
	ll s,t,n,m; cin>>s>>t>>n>>m; s*=2;
	vector<ll>a(t),b(t);
	fore(i,0,t)cin>>a[i],a[i]*=2;
	fore(i,0,t)cin>>b[i],b[i]*=2;
	ll c[n],d[m];
	fore(i,0,n)cin>>c[i],c[i]*=2;
	fore(i,0,m)cin>>d[i],d[i]*=2;
	ll flag=0;
	fore(i,0,n)fore(j,0,m){
		ll x=c[i],y=d[j];
		ll l=0,r=s;
		if(x<y)l+=abs(y-x);
		else r-=abs(x-y);
		if(l<0||r>s)continue;
		ll p=(l+r)/2;
		//cout<<i<<" "<<j<<": "<<x<<" "<<y<<": "<<l<<" "<<r<<": "<<p<<"\n";
		ll lwb=lower_bound(ALL(a),p)-a.begin()-1;
		if(lwb>=0&&p<b[lwb])flag=1;
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
