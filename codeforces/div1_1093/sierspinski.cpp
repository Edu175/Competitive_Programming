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

ll C2(ll n, ll k){return (n|k)==n;} // nCr %2

void super(vector<vv> &a){
	ll n=SZ(a);
	auto b=a;
	fore(i,0,n)fore(j,0,n)a[i][j]^=b[j][i];
}
void check(vector<vv> b){
	ll n=SZ(b);
	fore(i,0,n)fore(j,0,n){
		ll c=b[i][j];
		fore(k,0,i+1)fore(l,0,j+1)c^=b[k][l];
		assert(!c);
	}
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
	// fore(n,1,t+1){
		ll p=n;
		if((p&-p)!=p){ // not poteoncia de 2
			p=1<<(__lg(n)+1);
		}
		vector<vv> a(p,vv(p));
		fore(i,0,p)fore(j,0,p){
			// if(i+j>=p)continue;
			if(C2(i+j,j))a[p-1-i][p-1-j]=1;
		}
		vector<vv> b(n,vv(n));
		ll d=p-n;
		fore(i,0,n)fore(j,0,n)b[i][j]=a[i][j+d];
		check(b);
		// super(b);
		// check(b);
		
		
		ll c=0;
		fore(i,0,n)fore(j,0,n)c+=b[i][j];
		ll bound=n*n/10*3;
		cout<<n<<": "<<bound<<" "<<c<<": ratio "<<double(n*n)/c<<"\n";
		for(auto r:b)imp(r)
		if(c<bound){
			cout<<"========================== FAILED!!! ========================\n";
		}
		cout<<endl;
		// assert(bound<=c);
	}
	return 0;
}
