#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
// #define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;i--)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

bool adj(ll n, ll m, ll a, ll b){
	if(a>b)swap(a,b);
	if(abs(a-b)==m)return 1;
	if(b-a==1){
		if(b%m==0)return 0;
		return 1;
	}
	return 0;
}

bool good(vector<vv> a){
	ll n=SZ(a),m=SZ(a[0]);
	ll good=1;
	fore(i,0,n)fore(j,0,m){
		if(i)good&=!adj(n,m,a[i][j],a[i-1][j]);
		if(j)good&=!adj(n,m,a[i][j],a[i][j-1]);
	}
	return good;
}
void impm(vector<vv> a){ // returns 1 idxed
	for(auto i:a){
		for(auto j:i)cout<<j+1<<" ";
		cout<<"\n";
	}
}
void brute(ll n, ll m){
	vector<ll>per(n*m);
	iota(ALL(per),0);
	do{
		vector<vv>a(n,vv(m));
		fore(i,0,n)fore(j,0,m)a[i][j]=per[m*i+j];
		if(good(a)){
			cout<<"YES\n";
			impm(a);
			exit(0);
		}
	}while(next_permutation(ALL(per)));
	cout<<"NO\n";
	exit(0);
}

void fill(ll start, ll step, vector<vv> &a, ll rev){
	ll cnt=start;
	ll n=SZ(a),m=SZ(a[0]);
	if(!rev){
		fore(i,0,n)fore(j,0,m)if(a[i][j]==-1){
			if(cnt>=n*m)break;
			a[i][j]=cnt;
			cnt+=step;
		}
	}
	else {
		fore(j,0,m)fore(i,0,n)if(a[i][j]==-1){
			if(cnt>=n*m)break;
			a[i][j]=cnt;
			cnt+=step;
		}
	}
}


vector<vv> general(ll n, ll m, ll rev){
	vector<vv>a(n,vv(m,-1));
	fore(s,0,2)fill(s,2,a,rev);
	return a;
} 
vector<vv> ancho2(ll n, ll m, ll rev){
	vector<vv>a(n,vv(m,-1));
	fore(s,0,3)fill(s,3,a,rev);
	return a;
}
void retag(vector<vv> &a){
	ll n=SZ(a),m=SZ(a[0]);
	vv trad(n*m);
	fore(i,0,n)fore(j,0,m)trad[n*j+i]=m*i+j;
	fore(i,0,n)fore(j,0,m)a[i][j]=trad[a[i][j]];
}
vector<vv> solve(ll n, ll m){
	ll rev=(n<m);
	vector<vv>a;
	if(min(n,m)==2)a=ancho2(n,m,rev);
	else a=general(n,m,rev);
	// impm(a);
	if(rev)retag(a);
	// assert(good(a));aslihd
	return a;
}


// vector<vv> tra(vector<vv>a){
// 	ll n=SZ(a),m=SZ(a[0]);
// 	vector<vv>b(m,vv(n));
// 	vv trad(n*m); ll cnt=0;
// 	fore(i,0,n)fore(j,0,m)b[j][i]=a[i][j],trad[cnt++]=n*j+i;
// 	fore(i,0,m)fore(j,0,n)b[i][j]=trad[b[i][j]];
// 	return b;
// }


int main(){
	JET
	ll n,m; cin>>n>>m;
	if(n*m<=10)brute(n,m);
	else {
		// ll sw=0;
		// if(n<m)swap(n,m),sw=1;
		auto a=solve(n,m);
		// impm(a);
		// if(sw)a=tra(a);
		
		cout<<"YES\n";	
		impm(a);
		
		// cout<<endl;
		
		assert(good(a));
	}
	return 0;
}