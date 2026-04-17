#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define forr(i,a,b) for(ll i=(b)-1,jet=a;i>=jet;--i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<(i?"▮":" "); cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<vector<ll>> mat;

// random_device rd;
mt19937 rng(175);

ll n;
mat b;
ll best;
double t=1e5;
double tiempo=5;
mat a;
ll cur;
void ch(ll r){
	cur-=a[r][n-1];
	a[r][n-1]^=1;
	cur+=a[r][n-1];
	fore(i,r+1,n)fore(j,0,n-1){
		cur-=a[i][j];
		a[i][j]=a[i-1][j]^a[i-1][j+1];
		cur+=a[i][j];
	}
}
void SA(){
	a=mat(n,vv(n));
	ch(0); ch(n-1);
	fore(i,1,n-1)if(i%3!=n%3)ch(i);
	b=a,best=cur;
	return;
	while(clock()<tiempo*CLOCKS_PER_SEC){
		ll r=rng()%(n-2)+1;
		
		ll old=cur; mat _a=a;
		ch(r);
		if(cur>best)best=cur,b=a;
		
		if(cur>old||exp((cur-old)/t)*(1ll<<32)>=rng());
		else cur=old,a=_a;
		
		t*=0.99996;
	}
	cerr<<"temperature "<<t<<"\n";
}

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		ll bound=n*n/10*3;
		cerr<<"solution for n="<<n<<"\n";
		SA();
		cerr<<"cant  "<<best<<"\n";
		cerr<<"bound "<<bound<<"\n";
		for(auto r:b)imp(r)

	}
	return 0;
}
