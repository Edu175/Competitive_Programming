#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end();
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vector<vv> mx;
#define bint __int128
struct Hash{
	bint MOD=212345678987654321LL, P=1777771, PI=106955741089659571LL;
	vector<bint> h,p1;
	Hash(){}
	Hash(string& s){
		assert((P*PI)%MOD==1);
		h.resize(SZ(s)+1);p1.resize(SZ(s)+1);	
		h[0]=0;p1[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			p1[i]=(p1[i-1]*PI)%MOD;
			P=(P*p)%MOD;
		}
		
	}
	ll get(int s, int e){
		return (((h[e]-h[s]+MOD)%MOD)*p1[s])%MOD;
	}
};
const ll INF=1e17;
mx zeros(int n){
	mx r(n,vv(n,INF));
	fore(i,0,n) r[i][i]=0;
	return r;
}
mx operator*(mx &a, mx &b){
	int n=SZ(a), m=SZ(b[0]), z=SZ(a[0]);
	mx r(n,vv(m,INF));
	fore(i,0,n)fore(j,0,m)fore(k,0,z){
		if((a[i][k]!=INF)&&(b[k][j]!=INF))r[i][j]=min(r[i][j],a[i][k]+b[k][j]);
	}
	return r;
}
mx be(mx b, ll e){
	mx r=zeros(SZ(b));
	while(e){if(e&1)r=r*b;b=b*b;e>>=1;}
	return r;
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	string s[n];
	vector<Hash> H; 
	fore(i,0,n){cin>>s[i]; H.pb(Hash(s[i]));}
	mx A(n,vv(n,INF));
	fore(i,0,n) A[i][i]=SZ(s[i]);
	mx B(n,vv(n,INF));
	
	fore(i,0,n){
		fore(j,0,n){
			ll da=SZ(s[j]);
			ll x=da;
			ll fi=SZ(s[i]);
			fore(k,0,min(SZ(s[i]),SZ(s[j]))-1){
				if(H[i].get(fi-k,fi)==H[j].get(0,k)) da=min(da,x-k);
			}
			B[i][j]=da;
		}
	}
	mx R=be(B,m-1);
	R=A*R;
	ll rta=INF;
	fore(i,0,n)fore(j,0,n) if(R[i][j]!=INF)rta=min(rta,R[i][j]);
	cout<<rta<<"\n";
	return 0;
}