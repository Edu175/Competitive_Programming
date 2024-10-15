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
const ll MOD=998244353*2;//,MOD2=MOD*2;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll n;
vv id;
vv operator+(vv a, vv b){ // NO CONMUTATIVO
	vv ai=a;
	fore(i,0,n)ai[i]=a[b[i]];
	return ai;
}
ll fd(vv v){
	fore(i,0,n)if(v[i]!=i)return i;
	return n;
}
ll lcm(vv v){
	vv vis(n);
	ll res=1;
	fore(x,0,n)if(!vis[x]){
		ll z=0;
		for(ll y=x;!vis[y];y=v[y])vis[y]=1,z++;
		res=lcm(res,z);
	}
	return res%MOD;
}
struct matrix{
	vector<vv>x;
	matrix(): x(n,id){}
	ll d=0;
	bool add(vv v){
		if(v==id)return 0;
		fore(i,0,n){
			ll in=v[i];
			do{
				if(v[i]==i)break;
				v=v+x[i];
			}while(v[i]!=in);
			// imp(v)
			
		}
		if(v!=id){x[fd(v)]=v;d++;return 1;}
		return 0;
	}
};

ll calc_sz(matrix mt){
	auto p=id;
	ll res=0;
	do{
		auto mti=mt;
		if(!mti.add(p)){
			res++;
			cout<<"good ";imp(p);
		}
		// cout<<"\n";
	}while(next_permutation(ALL(p)));
	return res;
}
ll unmedio=(MOD+1)/2;
int main(){FIN;
	ll m; cin>>n>>m;
	id.resize(n); iota(ALL(id),0);
	matrix mt;
	fore(i,0,m){
		vv v(n);
		fore(i,0,n)cin>>v[i],v[i]--;
		mt.add(v);
	}
	fore(i,0,n){
		for(auto i:mt.x[i])cout<<i<<" ";
		if(mt.x[i]!=id)cout<<"!!";
		cout<<"\n";
	}
	// cout<<calc_sz(mt)<<"\n";
	// cout<<"\n\n";
	ll mu=1;
	fore(i,0,n)mu=mu*lcm(mt.x[i])%MOD;
	// mu/=2;
	mu%=MOD;
	cout<<mu<<"\n";
	ll res=mul(n*(n-1)/2,mu);
	cout<<res<<" antes\n";
	res=res/2%(MOD/2);
	cout<<res<<"\n";
	return 0;
}