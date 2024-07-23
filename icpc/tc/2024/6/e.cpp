#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5;
ll x[MAXN];
int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n) cin>>x[i];
	sort(x,x+n);
	ll M=0;
	vv rta;
	fore(i,0,n){
		vv res;
		ll aux=1;
		res.pb(i);ll sz=1;
		fore(j,0,31){
			auto it=lower_bound(x,x+n,x[i]+(1ll<<j));
			if(it!=x+n){
				if(*it==x[i]+(1ll<<j)){
					if(sz==1){
						res.pb(ll(it-x));
						sz++;aux++;
						if(aux>M) {
							M=aux;
							rta=res;
						}
					}
					else{
						if(res[sz]-*it==1ll<<(j-1)){
							res.pb(ll(it-x));aux++;
							break;
						}
						else {res.erase(res.begin()+1); aux--;}
					}
				}
			}
		}
		if(aux>M) {
			rta=res;
			M=aux;
		}
		if(M==3) break;
	}
	cout<<M<<"\n";
	fore(i,0,M){cout<<x[rta[i]]<<" ";}
	cout<<"\n";
	return 0;
}