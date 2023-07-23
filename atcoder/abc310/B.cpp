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
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll p[n];
	vector<ll>a[n];
	ll h[n][m]={};
	fore(i,0,n){
		cin>>p[i];
		ll sz; cin>>sz;
		fore(j,0,sz){
			ll x; cin>>x; x--;
			a[i].pb(x);
			h[i][x]=1;
		}
	}
	ll flag=0;
	fore(i,0,n)fore(j,0,n){
		if(i==j||p[i]<p[j])continue;
		ll fli=1;//,fl2=0;
		fore(k,0,m)if(h[i][k]&&!h[j][k])fli=0;
		if(fli&&(p[i]>p[j]||SZ(a[j])>SZ(a[i])))flag=1;//,cout<<i<<" "<<j<<"\n";
	}
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
