#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n),b(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		vv vis(n);
		ll res=0,good=1;
		fore(i,0,n){
			ll cur=0,best=-1;
			fore(j,0,n)if(!vis[j]){
				if(a[j]<=b[i]){
					best=cur;
					vis[j]=1;
					break;
				}
				cur++;
			}
			res+=best;
			good&=best!=-1;
		}
		if(!good)res=-1;
		cout<<res<<"\n";
	}
	return 0;
}
