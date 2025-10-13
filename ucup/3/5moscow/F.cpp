#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet=b; i<jet; i++)
#define forr(i,a,b) for(ll i=b-1,jet=a; i>=jet; i--)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=505,INF=1e18;
#define minig(a,b) a=min(a,b)

int main(){
    JET
	ll n; cin>>n;
	vector<vector<ii>> cuts(n+1);
	vv c(n);
	fore(i,0,n){
		cin>>c[i];
		ll d=min(i,n-1-i);
		if(d==i){ // izquierda
			cuts[i+d+1].pb({c[i],0});
		}
		else { // derecha
			cuts[i-d].pb({c[i],1});
		}
	}
	// fore(i,0,n+1)cout<<cuts[i]<<" ";;cout<<"\n";	
	vector<vv> dp(n+1,vv(n+1));
	// fore(z,0,2)fore(l,0,n)if(l+z<=n)
	fore(z,2,n+1){
		ll m=n-z+1;
		fore(l,0,m){
			ll r=l+z;
			assert(r<=n);
			auto &res=dp[l][r];
			res=INF;
			fore(m,l+1,r){
				for(auto [c,w]:cuts[m]){
					ll izq=w==0?dp[0][m-l]:dp[l][m];
					ll der=w==1?dp[n-(r-m)][n]:dp[m][r];
					
					ll cur=max(izq,der)+c;
					res=min(res,cur);
				}
			}
		}
		// dijkstra O(n^2)
		auto cost=[&](ll l1, ll l2){
			ll r1=l1+z;
			ll num=r1+l2-1;
			ll ret;
			if(num&1)ret=INF;
			else {
				ll pos=num/2;
				ret=c[pos];
			}
			// cout<<"cost "<<l1<<","<<l2<<": "<<ret<<"\n";;
			return ret;
		};
		
		#define acc(l) dp[l][l+z]
		// cout<<z<<":\n";
		// fore(i,0,m)cout<<acc(i)<<" ";;cout<<"\n";
		vv vis(m);
		fore(_,0,m){
			ll mn=-1;
			fore(i,0,m){
				if(!vis[i] && (mn==-1||acc(i)<acc(mn)))mn=i;
			}
			assert(mn!=-1);
			vis[mn]=1;
			fore(j,0,m)if(!vis[j]){
				minig(acc(j),acc(mn)+cost(j,mn));
			}
		}
		// fore(i,0,m)cout<<acc(i)<<" ";;cout<<"\n";
		// cout<<"\n";
	}
	ll res=dp[0][n];
	cout<<res<<"\n";
    return 0;
}
