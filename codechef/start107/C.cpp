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
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n&1){
			vector<vector<ll>> a(n,vector<ll>(n));
			fore(i,0,n)fore(j,0,n){
				a[i][j]=(abs(i-n/2)+abs(j-n/2)<=n/2);
			}
			ll p[2]={2,1};
			vector<vector<ll>> b(n,vector<ll>(n));
			fore(i,0,n)fore(j,0,n){
				if(a[i][j])b[i][j]=p[1],p[1]+=2;
				else b[i][j]=p[0],p[0]+=2;
			}
			fore(i,0,n){
				imp(b[i]);
			}
		}
		else {
			vector<vector<ll>> a(n,vector<ll>(n));
			fore(i,0,n)fore(j,0,n){
				a[i][j]=(min(abs(i-n/2)+abs(j-n/2),abs(i-(n/2-1))+abs(j-(n/2-1)))<=n/2-1);
			}
			ll p[2]={2,1};
			vector<vector<ll>> b(n,vector<ll>(n));
			fore(i,0,n)fore(j,0,n){
				if(a[i][j])b[i][j]=p[1],p[1]+=2;
				else b[i][j]=p[0],p[0]+=2;
			}
			/*fore(i,0,n){
				imp(a[i]);
			}*/
			fore(i,0,n){
				imp(b[i]);
			}
		}
	}
	return 0;
}
