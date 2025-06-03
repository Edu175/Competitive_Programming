#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll vis[1<<4][1<<16];

vector<ii> mov = {{1,-1},{2,-1},{4,-1},{8,-1},{3,-1},{12,-1},{5,-1},{10,-1},{15,-1}};
ll m; 
ll dp[1<<4][1<<16];
const ll INF = 1e17;
ll mcost[16];


ll f(ll mat, ll mask){
	if(!mask) return 0;
	ll &r = dp[mat][mask];
	if(r!=-1) return r;
	r = INF;
	fore(i,0,16){
		ll nmat = mat^i;
		if(mask&(1<<(nmat^15))) r = min(r,
			f(nmat,(mask^(1<<(nmat^15)))) + mcost[i] );
	}
	return r;
}

int main(){
	JET
	ll t; cin>>t;
	ll a0,a1,a2,a3;
	cin>>a0>>a1>>a2>>a3;
	fore(i,0,4) mov[i].snd = a0;
	fore(i,4,6) mov[i].snd = a1;
	fore(i,6,8) mov[i].snd = a2;
	mov[8].snd = a3;
	fore(i,0,16) mcost[i]=INF;
	ll mk=0;
	while(++mk<(1<<9)){
		ll nmat=0, cst=0;
		fore(i,0,9){
			if(mk&(1<<i)){
				nmat^=mov[i].fst;
				cst+=mov[i].snd;
			}
		}
		mcost[nmat]=min(mcost[nmat],cst);
	}
	fore(i,0,9) mcost[0]=min(mcost[0],2*mov[i].snd);
	mset(dp,-1);
	while(t--){
		ll m; cin>>m;
		ll s = 0;
		fore(i,0,m){
			ll aux = 0;
			fore(j,0,4){
				char c; cin>>c;
				if(c=='1') aux^=(1<<j);
			}
			s^=(1<<aux);
		}
		cout<<f(0,s)<<"\n";
		
	}
	
	
	
	return 0;
}