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
	ll n,m; cin>>n>>m;
	if(n>m)swap(n,m);
	vv vis(m);
	ll res=0;
	ll k=2*(n-1);
	fore(s,0,m)if(!vis[s]){
		res++;
		ll p=s,d=p==m-1?-1:1;
		// cout<<"ronda "<<s<<"\n";
		// ll pinga=0;
		ll _d=d;
		do{
			// cout<<p<<" "<<d<<"\n";
			// if(++pinga>5)exit(0);
			ll c=k;
			while(c>0){
				ll fal=d==1?m-1-p:p;
				ll q=min(fal,c);
				c-=q;
				p+=d*q;
				if(p==m-1||p==0)d=-d;
			}
			vis[p]=1;
		}
		while(d!=_d||p!=s);
	}
	cout<<res<<"\n";
	return 0;
}
