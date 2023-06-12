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
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n][m];
		ll c=0;
		fore(i,0,n){
			fore(j,0,m)cin>>a[i][j],c+=a[i][j];
		}
		if(c%n!=0){
			cout<<"-1\n";
			continue;
		}
		ll e=c/n;
		ll k=0;
		vector<pair<ll,ll>>pos,neg;
		fore(i,0,n){
			ll sum=0;
			vector<ll>oci;
			fore(j,0,m){
				sum+=a[i][j];
				if(a[i][j])oci.pb(j);
			}
			k+=abs(sum-e);
			if(sum-e>0)pos.pb({i,sum-e});
			if(sum-e<0)neg.pb({i,sum-e});
		}
		vector<vector<ll>>res;
		ll l=0,r=0;
		while(l<SZ(pos)&&r<SZ(neg)){
			fore(j,0,m){
				if(a[pos[l].fst][j]-a[neg[r].fst][j]==1){
					res.pb({pos[l].fst,neg[r].fst,j});
					pos[l].snd--,neg[r].snd++;
					swap(a[pos[l].fst][j],a[neg[r].fst][j]);
				}
				if(neg[r].snd==0)r++;
				if(pos[l].snd==0){
					l++;
					break;
				}
			}
		}
		cout<<SZ(res)<<"\n";
		for(auto i:res){
			cout<<i[0]+1<<" "<<i[1]+1<<" "<<i[2]+1<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
