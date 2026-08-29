#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a) cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef __int128 xl;
const ll MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
ll addm(ll a, ll b){a+=b; return a<MOD?a:a-MOD;}
ll subm(ll a, ll b){a-=b; return a<0?a+MOD:a;}
ll mulm(xl a, xl b){return a*b%MOD;}
bool vis[3];
vv pi={1};

void calc_p(ll n){
	while(SZ(pi)<n+5) pi.pb(mulm(pi.back(),PI));
}
struct Hash{
	vv h; ll n;
	Hash(string &s) {
		assert(mulm(P,PI)==1);
		n=SZ(s);
		calc_p(n);
		h.resize(n+1);
		h[0]=0;
		ll p=1;
		fore(i,1,n+1){
			h[i]=addm(h[i-1],mulm(p,s[i-1]));
			p=mulm(p,P);
		}
	}
	ll get(ll s, ll e){
		return mulm(subm(h[e],h[s]),pi[s]);
	}
};
bool contiene(Hash &H, Hash &I){
	fore(i,0,I.n-H.n){
		if(H.get(0,H.n)==I.get(i,i+H.n)) return true;
	}
	return false;
}
ll min(Hash &H, Hash &I){
	fore(i,max(0ll,H.n-I.n),H.n){
		if(H.get(i,H.n)==I.get(0,H.n-i)) return I.n+i-H.n;
	}
	return I.n;
}
int main(){
	JET
	string s[3]; fore(i,0,3) cin>>s[i],vis[i]=1;
	vector<Hash> H;
	fore(i,0,3) H.pb(Hash(s[i]));
	fore(i,0,3) fore(j,0,3)if(i!=j&&vis[j]&&vis[i]){
		if(contiene(H[i],H[j])) vis[i]=0;
	} 
	// show(vis);
	vv v; fore(i,0,3) if(vis[i]) v.pb(i);
	ll sz=1e9; 
	do{
		ll nsz=SZ(s[v[0]]);
		// show(v);
		fore(i,1,SZ(v)){
			// cout<<min(H[v[i-1]],H[v[i]])<<" "; 
			nsz+=min(H[v[i-1]],H[v[i]]);
		}
		// cout<<"dsts\n";
		sz=min(sz,nsz);
	}while(next_permutation(ALL(v)));
	cout<<sz<<"\n";
	return 0;
}
