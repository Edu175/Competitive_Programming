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
#define bint __int128
bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
ll mul(bint a, bint b){return a*b%MOD;}

int main(){FIN;
	assert(mul(P,PI)==1);
	ll h,w; cin>>h>>w;
	vector<vector<char>> chico(h,vector<char>(w,'.'));
	fore(i,0,h)fore(j,0,w)cin>>chico[i][j];
	
	ll n,m; cin>>n>>m;
	ll hsh=0,pot=1;
	fore(i,0,h)fore(j,0,m){
		if(j<w){
			char c=chico[i][j];
			hsh=add(hsh,mul(c,pot));
		}
		pot=mul(pot,P);
	}
	// cerr<<hsh<<"\n";
	pot=1;
	vector<vv> a(n,vv(m));
	vector<vector<char>> tab(n,vector<char>(m,'.'));
	fore(i,0,n)fore(j,0,m){
		char c; cin>>c;
		a[i][j]=mul(c,pot);
		pot=mul(pot,P);
		tab[i][j]=c;
	}
	// fore(i,0,n){
	// 	fore(j,0,m)cerr<<a[i][j]<<" ";
	// 	cerr<<"\n";
	// }
	vector<vv> sp(n+1,vv(m+1));
	fore(i,1,n+1)fore(j,1,m+1)sp[i][j]=add(sp[i][j-1],a[i-1][j-1]);
	fore(i,1,n+1)fore(j,1,m+1)sp[i][j]=add(sp[i][j],sp[i-1][j]);
	
	// fore(i,0,n+1){
	// 	fore(j,0,m+1)cerr<<sp[i][j]<<" ";
	// 	cerr<<"\n";
	// }
	
	vv pi(n*m+5); pi[0]=1;
	fore(i,1,SZ(pi))pi[i]=mul(pi[i-1],PI);
	
	auto good=[&](ll i, ll j)->bool{ // subrect of h x w
		if(i+h>n||j+w>m)return 0;
		// cerr<<"? good "<<i<<" "<<j<<": ";
		ll uno=sp[i+h][j+w];
		ll dos=add(sp[i+h][j],sp[i][j+w]);
		ll tres=sp[i][j];
		ll res=add(sub(uno,dos),tres);
		// cerr<<res<<"\n";
		ll p=i*m+j;
		res=mul(res,pi[p]);
		// cerr<<res<<"\n";
		return res==hsh;
	};
	
	vv hist(m);
	vector<vector<ii>> cam(n+1);
	fore(i,0,n)fore(j,0,m)if(good(i,j)){
		// cerr<<"good "<<i<<","<<j<<"\n";
		cam[i].pb({j,1});
		cam[i+h].pb({j,-1});
	}
	
	vector<vv> is(n,vv(m));
	
	fore(i,0,n){
		for(auto [j,v]:cam[i])hist[j]+=v;
		vv ev(m+1);
		fore(j,0,m)if(hist[j]>0)ev[j]++,ev[j+w]--;
		ll cnt=0;
		fore(j,0,m){
			cnt+=ev[j];
			if(cnt>0)is[i][j]=1;
		}
	}
	
	fore(i,0,n){
		fore(j,0,m){
			char c='.';
			if(is[i][j])c=tab[i][j];
			cout<<c;
		}
		cout<<"\n";
	}
	
	return 0;
}
