#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5;
ll cr[MAXN]; 
vv pr;
vv N,D;
vector<vv> pot, C;
void init(){
	mset(cr,-1);
	fore(i,2,MAXN){
		if(cr[i]==-1){
			pr.pb(i);
			for(ll j=1ll*i*i; j<MAXN; j+=i){
				cr[j]=i;
			}
		}
	}
	N.resize(SZ(pr),0);
	D.resize(SZ(pr),0);
	pot.resize(SZ(pr));
	C.resize(SZ(pr));
}

const ll INF=1e10;
int main(){
	#ifdef ONLINE_JUDGE
	freopen("holes.in","r",stdin);     freopen("holes.out","w",stdout);
	#endif
	//JET
	ll n,m; cin>>n>>m; vv p(n); vv q(n);
	init();
	fore(i,0,SZ(pr)){
		ll x=1, y=1;
		while(x<=MAXN){
			x*=pr[i];
			pot[i].pb(x);C[i].pb(y); y=y*pr[i]+1;
		}
	}
	fore(i,0,n){
		ll p; cin>>p;
		fore(i,0,SZ(pr)){
			ll j=0;
			while(pot[i][j]<=p){
				N[i]+=p/pot[i][j];
				j++;
			}
		}
	}
	fore(i,0,m){
		ll p; cin>>p;
		fore(i,0,SZ(pr)){
			ll j=0;
			while(pot[i][j]<=p){
				D[i]+=p/pot[i][j];
				j++;
			}
		}
	}
	fore(i,0,SZ(pr)){
		N[i]-=D[i];
		if(N[i]<0) {cout<<"-1\n"; return 0;}
	}
	vector<ii> res;
	while(N[0]!=0){
		cout<<"a\n";
		ll r=INF, s=INF;
		fore(i,0,SZ(pr)){
			if(N[i]==0) break;
			ll aux=N[i], ar=0;
			while(aux){
				cout<<"b\n";
				ll j=upper_bound(ALL(C[i]),aux)-C[i].begin()-1;
				if(j==-1){j=SZ(C[i])-1;}
				ll m=aux/C[i][j];
				if(!m) break;
				ar+=m*pot[i][j];
				aux-=m*C[i][j];
			}
			ar+=pr[i]-1;
			r=min(r,ar);
		}if(r<=1) break;
		fore(i,0,SZ(pr)){
			ll j=0, cnt=0;
			while(pot[i][j]<=r){
				cout<<"c\n";
				cnt+=r/pot[i][j];
				j++;
			}
			if(cnt==0)continue;
			s=min(N[i]/cnt,s);
		}
		if(s==0) break;
		fore(i,0,SZ(pr)){
			ll j=0, cnt=0;
			while(pot[i][j]<=r){
				cout<<"d\n";
				cnt+=r/pot[i][j];
				j++;
			}
			N[i]-=cnt*s;
		}
		res.pb({r,s});
	}
	cout<<SZ(res)<<"\n";
	fore(i,0,SZ(res)){
		cout<<res[i].fst<<" "<<res[i].snd<<"\n";
	}
	return 0;
}