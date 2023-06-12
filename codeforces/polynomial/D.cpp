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

int main(){//FIN;
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
		//cout<<"e "<<e<<"\n";
		ll k=0;
		vector<pair<ll,ll>>pos,neg;
		vector<vector<ll>> oc;
		fore(i,0,n){
			ll sum=0;
			vector<ll>oci;
			fore(j,0,m){
				sum+=a[i][j];
				if(a[i][j])oci.pb(j);
			}
			k+=abs(sum-e);
			if(sum-e>0)pos.pb({i,sum-e}),oc.pb(oci);
			if(sum-e<0)neg.pb({i,sum-e});
		}
		vector<pair<pair<ll,ll>,ll>>res;
		ll l=0,r=0;
		/*for(auto i:pos)cout<<i.fst<<" "<<i.snd<<"\n";
		for(auto i:neg)cout<<i.fst<<" "<<i.snd<<"\n";
		for(auto i:oc){
			imp(i);
		}*/
		while(l<SZ(pos)&&r<SZ(neg)){
			for(auto i:oc[l]){
				//cout<<l<<" "<<r<<" "<<i<<": "<<a[neg[r].fst][i];
				if(a[neg[r].fst][i]==0){
					res.pb({{pos[l].fst,neg[r].fst},i});
					pos[l].snd--,neg[r].snd++;
					a[neg[r].fst][i]=1;
				}
				if(neg[r].snd==0)r++;
				if(pos[l].snd==0){
					l++;
					break;
				}
			}
		}
		/*assert(l==SZ(pos)&&r==SZ(pos));
		assert(k/2==SZ(res));*/
		//cout<<"done "<<l<<" "<<r<<"\n";
		cout<<SZ(res)<<"\n";
		for(auto i:res){
			cout<<i.fst.fst+1<<" "<<i.fst.snd+1<<" "<<i.snd+1<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
