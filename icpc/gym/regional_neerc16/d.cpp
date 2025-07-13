#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ld EPS=1e-8;

vector<int> X,Y;
vector<vector<ld>> A;
vector<ld> b,c;
ld z;
int n,m;
void pivot(int x, int y){
	swap(X[y],Y[x]);
	b[x]/=A[x][y];
	fore(i,0,m)if(i!=y)A[x][i]/=A[x][y];
	A[x][y]=1/A[x][y];
	fore(i,0,n)if(i!=x&&abs(A[i][y])>EPS){
		b[i]-=A[i][y]*b[x];
		fore(j,0,m)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
		A[i][y]=-A[i][y]*A[x][y];
	}
	z+=c[y]*b[x];
	fore(i,0,m)if(i!=y)c[i]-=c[y]*A[x][i];
	c[y]=-c[y]*A[x][y];
}
pair<ld, vector<ld>> simplex(vector<vector<ld>>_A, vector<ld> _b, vector<ld>_c){
	A=_A;b=_b;c=_c;
	n=SZ(b),m=SZ(c);z=0.;
	X=vector<int>(m);Y=vector<int>(n);
	fore(i,0,m)X[i]=i;
	fore(i,0,n)Y[i]=i+m;
	while(1){
		int x=-1,y=-1;
		ld mn=-EPS;
		fore(i,0,n)if(b[i]<mn)mn=b[i],x=i;
		if(x<0)break;
		fore(i,0,m)if(A[x][i]<-EPS){y=i;break;}
		assert(y>=0);
		pivot(x,y);
	}
	while(1){
		ld mx=EPS;
		int x=-1,y=-1;
		fore(i,0,m)if(c[i]>mx)mx=c[i],y=i;
		if(y<0)break;
		ld mn=1e200;
		fore(i,0,n)if(A[i][y]>EPS&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
		assert(x>=0);
		pivot(x,y);
	}
	vector<ld>r(m);
	fore(i,0,n)if(Y[i]<m)r[Y[i]]=b[i];
	return {z,r};
}
int main(){
    JET
    #ifdef ONLINE_JUDGE
    freopen("delight.in","r",stdin);     freopen("delight.out","w",stdout);
    #endif
	ll n,k,ms,me; cin>>n>>k>>ms>>me;
	ll sums=0;
	vector<ld> w(n);
	fore(i,0,n){ // s_i
		ll x; cin>>x; sums+=x;
		w[i]-=x;
	}
	fore(i,0,n){ // e_i
		ll x; cin>>x;
		w[i]+=x;
	}
	ll m=n-k+1;
	vector<vector<ld>>a(2*m,vector<ld>(n));
	vector<ld> b(2*m);
	fore(i,0,m){
		fore(j,i,i+k)a[2*i][j]=1,a[2*i+1][j]=-1;
		b[2*i]=k-ms;
		b[2*i+1]=-me;
	}
	fore(i,0,n){ // use only once
		vector<ld> v(n); v[i]=1;
		a.pb(v);
		b.pb(1);
	}
	// cout<<"a:\n";
	// fore(i,0,SZ(a)){
	// 	fore(j,0,SZ(a[i]))cout<<(a[i][j]==-1?"-":to_string(ll(a[i][j])));
	// 	cout<<"\n";
	// }
	// cout<<"b: ";;for(auto i:b)cout<<i<<" ";;cout<<"\n";
	// cout<<"w: ";;for(auto i:w)cout<<i<<" ";;cout<<"\n";
	
	auto [res,x]=simplex(a,b,w);
	res+=sums;
	cout<<ll(res)<<"\n";
	fore(i,0,n)cout<<(abs(x[i])<=EPS?'S':'E');
	cout<<"\n";
    return 0;
}