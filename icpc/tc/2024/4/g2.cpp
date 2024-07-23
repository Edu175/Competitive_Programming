#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll v; cin>>v;
	vv c(10);
	fore(i,1,10) cin>>c[i];
	ii p={1e7,-1};
	fore(i,1,10) p=min(p,{c[i],i});
	string rta;
	while(v>=p.fst){
		rta.pb(p.snd+'0');
		v-=p.fst;
	}
	ll j=0;
	ll aux=-1;
	
	while(j!=aux && j<SZ(rta)){
		aux=j;
		for(int i=9;i>p.snd;i--){
			if(c[i]-c[p.snd]<=v){
				v-=(c[i]-c[p.snd]);
				rta[j]='0'+i;
				j++;
				break;
			}
		}	
	}
	(rta.empty())? cout<<"-1\n" : cout<<rta<<"\n";
	return 0;
}