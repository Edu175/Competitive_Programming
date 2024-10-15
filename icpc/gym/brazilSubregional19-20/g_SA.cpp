#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef double ld;
typedef pair<ll,ll> ii;
const ll MAXN=105;
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
ld a[MAXN][MAXN];
vector<int_fast16_t>res,b;

int n;
ld v,best;
double t=1e5;
void sw(int i, int j){
	v-=a[i][b[i]];
	v-=a[j][b[j]];
	swap(b[i],b[j]);
	v+=a[i][b[i]];
	v+=a[j][b[j]];
}
void SA(){
	fore(i,0,n)b.pb(i);
	srand(175);
	random_shuffle(ALL(b));
	fore(i,0,n)v+=a[i][b[i]];
	res=b,best=v;
	do{
		int i=rand()%n,j=rand()%n;
		ld old=v;
		sw(i,j);
		if(v<best)best=v,res=b;
		if(!(v<old||exp((old-v)/t)>=(double)rand()/RAND_MAX))sw(i,j);
		t*=0.99999;
	}while(clock()<=0.99*CLOCKS_PER_SEC);
	// cerr<<t<<"\n";
}

int main(){FIN;
	cin>>n;
	fore(j,0,n)fore(i,0,n){
		cin>>a[i][j];
		a[i][j]=-log(a[i][j]);
	}
	SA();
	// ld vi=0;
	// fore(i,0,n)vi+=a[i][res[i]];
	// cerr<<vi<<"\n";
	// cerr<<"ans "<<v<<": "<<exp(-v)<<"\n";
	fore(i,0,n)cout<<res[i]+1<<" ";
	cout<<"\n";
	return 0;
} 