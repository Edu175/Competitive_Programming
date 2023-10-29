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
typedef int ll;

vector<ll> res[22][22];
ll a[22][22];
int main(){//FIN;
	ll tle=0;
	ll n; cin>>n;
	fore(i,0,n){
		fore(j,0,n)cin>>a[i][j];
	}
	res[0][0]={a[0][0]};
	fore(i,0,n/2+1){
		fore(j,0,n){
			//cout<<i<<" "<<j<<" ";
			if(i){
				for(auto k:res[i-1][j]){
					res[i][j].pb(k^a[i][j]);
				}
			}
			if(j){
				for(auto k:res[i][j-1]){
					res[i][j].pb(k^a[i][j]);
				}
			}
			//cout<<SZ(res[i][j])<<"\n";
			tle+=SZ(res[i][j]);
		}
		
	}
	ll sum=0;
	res[n-1][n-1]={a[n-1][n-1]};
	for(int i=n-1;i>n/2;i--){
		for(int j=n-1;j>=0;j--){
			//cout<<i<<" "<<j<<": ";
			if(i<n-1){
				for(auto k:res[i+1][j]){
					res[i][j].pb(k^a[i][j]);
				}
			}
			if(j<n-1){
				for(auto k:res[i][j+1]){
					res[i][j].pb(k^a[i][j]);
				}
			}
			//cout<<SZ(res[i][j])<<"\n";
			tle+=SZ(res[i][j]);
		}
	}
	ll logs=0;
	fore(j,0,n){
		vector<ll> &ans=res[n/2+1][j];
		sort(ALL(ans));
		//cout<<SZ(ans)<<": "<<SZ(res[n/2][j])<<"\n";
		logs+=SZ(ans)*log2(SZ(ans));
		logs+=SZ(res[n/2][j])*log2(SZ(ans));
		//imp(ans);
		for(auto k:res[n/2][j]){
			ll upp=upper_bound(ALL(ans),k)-ans.begin();
			ll low=lower_bound(ALL(ans),k)-ans.begin();
			sum+=upp-low;
			//cout<<k<<"\n\n";
		}
	}
	/*fore(i,0,n){
		fore(j,0,n){
			cout<<i<<" "<<j<<": ";
			imp(res[i][j]);
		}
	}*/
	cout<<sum<<"\n";
	//cout<<"operations: "<<tle+logs<<"\nprecomputo: "<<tle<<"\nfinding pairs: "<<logs<<"\n";
	
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
