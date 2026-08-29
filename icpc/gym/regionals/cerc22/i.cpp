#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef long double ld;
typedef vector<ld> vd;
typedef vector<vd> mtx;
const ld eps=1e-9;
mtx id(ll n){
	mtx r(n, vd(n,0.L));
	fore(i,0,n) r[i][i]=1.L;
	return r;
}
mtx operator*(const mtx &A, const mtx &B){
	ll n=SZ(A), m=SZ(B[0]), h=SZ(B);
	mtx R(n,vd(m,0.L));
	fore(i,0,n)fore(j,0,m)fore(k,0,m){
		R[i][j]+=A[i][k]*B[k][j];
	}
	return R;
}
mtx operator*(const mtx &A, const vd &v){
	return A*(mtx){v};
}
vd operator*(const vd &A, const ll &t){
	vd r=A;
	for(auto &x:r) x*=t;
	return r;
}
void operator-=(vd &A, const vd &B){
	fore(i,0,SZ(A)) A[i]-=B[i];
}
mtx inv(mtx A){
	ll n=SZ(A);
	mtx B=id(n);
	vv p(n); iota(ALL(p),0);
	fore(i,0,n){
		ll b=-1;
		fore(j,i,n)if(abs(A[p[j]][i])>=eps) {b=j; break;}
		assert(b>=i);
		swap(p[i],p[b]);
		fore(j,i+1,n){
			B[p[j]]-=B[p[i]]*(A[p[j]][i]/A[p[i]][i]);
			A[p[j]]-=A[p[i]]*(A[p[j]][i]/A[p[i]][i]);
		}

	}
	return B;
}
typedef vector<pair<ll,ld>> vi;
 const int maxn = 1e4;
vi g[maxn], gt[maxn];vv ord;
ll vis[maxn], cmp[maxn],qcmp = 0, n;
void dfs(ll x, ll t){
	if(t) cmp[x] = qcmp; vis[x] = 1;
	for(auto [y,xx]:t?gt[x] : g[x])if(!vis[y])dfs(y,t);
	if(!t)ord.pb(x);
}
void scc(){
	fore(i,0,n) if(!vis[i])dfs(i,0);
	reverse(ALL(ord));mset(vis,0);
	for(auto x:ord)if(!vis[x])dfs(x,1),qcmp++;
}
mtx cst[maxn];
set<ll> bu[maxn];
ll wh[maxn];
void armar(ll n){
	fore(i,0,n) wh[i]=SZ(bu[cmp[i]]),bu[cmp[i]].insert(i);
	fore(i,0,qcmp){
		ll m=SZ(bu[i]);
		cst[i]=mtx(m,vd(m,0));
		for(auto j:bu[i]){
			for(auto [v,w]: g[j]){
				if(bu[i].count(v)){
					cst[i][j][v]=w;
				}
			}
		}
		cst[i]=inv(cst[i]);
	}
}

void pross(string s){
	if(s[0]=='P'){
		
	}
}
int main(){
	JET
	ll c,p; cin>>c>>p;
	n=c+p;
	fore(i,0,c){
		ll k; cin>>k;
		fore(i,0,k){
			string s; cin>>s;
			pross(s);
		}
	}
	
	return 0;
}