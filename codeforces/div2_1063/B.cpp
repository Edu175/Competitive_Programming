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
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		string s; cin>>s;
		vv us(n);
		fore(i,0,n)us[i]=s[i]-'0';
		vv vis(n);
		vector<ii> ops;
		ll fg=1;
		fore(_,0,5){
			ll l=-1,r=-1;
			fore(i,0,n)if(!vis[i]){
				if(l==-1&&us[i])l=i;
				if(us[i])r=i;
			}
			if(l==-1)break;
			ll mn1=0,mx2=0;
			fore(i,0,l){
				if(a[i]<a[mn1])mn1=i;
				if(a[i]>a[mx2])mx2=i;
			}
			
		}
	}
	return 0;
}
