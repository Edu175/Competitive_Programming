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
const ll MAXV=1e18+5;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<ii>a(n);
		vector<__int128>sz;
		fore(i,0,n){
			ll ty,x; cin>>ty>>x; ty--;
			a[i]={ty,x};
			if(SZ(sz)&&sz.back()>=MAXV)continue;
			sz.pb(i?sz[i-1]:0);
			if(!ty)sz[i]++;
			else sz[i]*=(x+1);
		}
		while(q--){
			ll p; cin>>p; p--;
			while(1){
				ll x=lower_bound(ALL(sz),p+1)-sz.begin();
				if(a[x].fst==0){
					cout<<a[x].snd<<" ";
					break;
				}
				p%=sz[x-1];
			}
		}
		cout<<"\n";
	}
	return 0;
}
