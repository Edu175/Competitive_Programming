#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,acts=b;i<acts;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdf:v)cout<<sdf<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#define bint ll
const int MAXN=5e5+5,K=19;
//const bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
const ll MOD=1e9+7,P=1777771;
ll PI;
bint fpow(bint b, ll e){
	bint ret=1;
	while(e){
		if(e&1)ret=ret*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return ret;
}
int F[K][MAXN],D[MAXN];
bint H[MAXN], pi[MAXN],pt[MAXN];
string a;
int mini(int x, int y){
	if(x==-1)return y;
	if(y==-1)return x;
	int _x=x,_y=y;
	//ll db=(_x==7&&_y==4);
	//if(db)cout<<x<<" "<<y<<" : "<<D[x]<<" "<<D[y]<<"\n";
	for(int k=K-1;k>=0;k--)if(min(D[x],D[y])>=1ll<<k){
		bint h0=(H[x]-H[F[k][x]]*pt[1<<k]%MOD+MOD)%MOD;
		bint h1=(H[y]-H[F[k][y]]*pt[1<<k]%MOD+MOD)%MOD;
		//bint h1=(H[y]-H[F[k][y]]+MOD)%MOD*pi[D[F[k][y]]+1]%MOD;
		//if(db)cout<<x<<" "<<y<<" "<<k<<" : "<<F[k][x]<<" "<<F[k][y]<<" : "<<D[F[k][x]]+1<<" "<<D[F[k][y]]+1<<" : "<<ll(h0)<<" "<<ll(h1)<<"\n";
		if(h0==h1){
			x=F[k][x],y=F[k][y];
		}
	}
	//x=F[0][x];y=F[0][y];
	//if(x==y)return _x;
	/*if(db){
		cout<<x<<" "<<y<<"   ==========\n";
	}*/
	if(a[x]<a[y])return _x;
	return _y;
}
/*int mini(ll x, ll y){
	ll r=oper(x,y);
	//if(x==7&&y==4)cout<<"mini "<<x<<" "<<y<<" = "<<r<<"\n";
	return r;
}*/
void add(int x, int f){
	F[0][x]=f;
	fore(k,1,K)F[k][x]=F[k-1][F[k-1][x]];
	H[x]=(H[f]*P+a[x])%MOD;
	D[x]=D[f]+1;
}
int ft[MAXN+1];
void upd(int i0){
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]=mini(ft[i],i0);
}
int get(int i){
	int res=-1;
	for(;i>0;i-=i&-i)res=mini(res,ft[i]);
	return res;
}
int main(){FIN;
	//cout<<ll(fpow(P,MOD-2))<<"\n";
	PI=fpow(P,MOD-2);
	assert(P*PI%MOD==1);
	pi[0]=1;
	fore(i,1,MAXN)pi[i]=pi[i-1]*PI%MOD;
	pt[0]=1;
	fore(i,1,MAXN)pt[i]=pt[i-1]*P%MOD;
	int n,k; cin>>k>>n;
	//bint hs='a';
	//fore(i,0,n)cout<<"hs "<<i<<" = "<<ll(hs)<<"\n",hs=hs*P%MOD;
	mset(ft,-1);
	bool b[k][k];
	fore(i,0,k)fore(j,0,k){
		char c; cin>>c;
		b[i][j]=(c=='1');
	}
	cin>>a;
	a.pb('$');
	vector<int>to(n);
	//imp(to);
	add(n,n);
	//upd(n);
	D[n]=0;
	//cout<<ll(H[n])<<"\n";
	vector<int>dp(n+1);
	dp[n]=n;
	for(int i=n-1;i>=0;i--){
		int res=-1;
		//cout<<i<<":"<<endl;
		for(to[i]=i+1;to[i]!=n&&b[a[i]-'a'][a[to[i]]-'a'];to[i]=to[to[i]])
			res=mini(res,dp[to[i]]);
			//,cout<<"min "<<to[i]<<" "<<dp[to[i]]<<endl;
		//cout<<"min "<<to[i]<<" "<<dp[to[i]]<<endl;
		res=mini(res,to[i]);
		//cout<<res<<endl<<endl;
		add(i,res);
		//upd(i);
		dp[i]=mini(res,i);
		//int res=-1;
		//fore(j,i+1,to[i]+1)res=mini(res,j);
		//cout<<D[i]<<" 4("<<D[4]<<")\n\n";
	}
	string res;
	int x=0;
	while(x!=n){
		//cout<<x<<endl;
		res.pb(a[x]);
		x=F[0][x];
	}
	cout<<res<<"\n";
	return 0;
}
