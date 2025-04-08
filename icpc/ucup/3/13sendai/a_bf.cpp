#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e6+5;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
ll n,m;
void impg(vector<vv>a){
	fore(i,0,n){
		fore(j,0,m)cout<<a[i][j];
		cout<<"\n";
	}
	// cout<<"\n";
}
ll cant(vector<vv>a){
	fore(i,0,n*m)uf[i]=-1;
	ll res=0;
	fore(i,0,n)fore(j,0,m)res+=!a[i][j];
	auto joinif=[&](ll i, ll j, ll r, ll c){
		if(!a[i][j]&&!a[r][c])res-=uf_join(i*m+j,r*m+c);
	};
	fore(i,0,n)fore(j,0,m){
		if(i)joinif(i,j,i-1,j);
		if(j)joinif(i,j,i,j-1);
		if(i&&j)joinif(i,j,i-1,j-1);
	}
	// cout<<"cant\n"; impg(a); cout<<"= "<<res<<"\n"<<endl;
	return res;
}

int main(){FIN;
	cin>>n>>m;
	vector<vector<vv>> h[n*m+5];
	
	fore(mk,0,1ll<<(n*m)){
		vector<vv> a(n,vv(m));
		fore(i,0,n)fore(j,0,m)if(mk>>(m*i+j)&1)a[i][j]=1;
		h[cant(a)].pb(a);
	}
	
	fore(z,0,n*m+5){
		cout<<"grids having "<<z<<" components:\n";
		for(auto a:h[z]){
			impg(a);
			cout<<"\n";
		}
		cout<<"\n\n";
	}
	return 0;
}
