#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){//FIN;
	ll n,m,k; cin>>n>>m>>k;
	vector<ll>pos[m];
	ll a[n];
	fore(i,0,n)cin>>a[i],a[i]--,pos[a[i]].pb(i);
	vector<ll> num[m];
	vector<ll> gap[m];
	fore(i,0,m){
		ll add=1;
		fore(j,1,SZ(pos[i])){
			ll dist=pos[i][j]-pos[i][j-1]-1;
			if(dist)gap[i].pb(dist),num[i].pb(add),add=1;
			else add++;
		}
		num[i].pb(add);
		//imp(num[i]);
		//imp(gap[i]);
	}
	ll res=0;
	fore(i,0,m){
		ll sum=num[i][0], w=0;
		ll h=0;
		ll j=0;
		while(j+1<SZ(num[i])){
			//cout<<sum<<" "<<w<<" "<<j<<" "<<h<<"\n";
			if(w+gap[i][j]<=k){
				sum+=num[i][j+1];
				w+=gap[i][j];
				j++;
			}
			else {
				res=max(res,sum);
				sum-=num[i][h];
				w-=gap[i][h];
				h++;
			}
		}
		
		res=max(res,sum);
	}
	pres;
	return 0;
}
