#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=370;
ll cs[30];
ll ss[MAXN][30];
ll fn(ll n){return n*(n+1)/2;}
ll n;
typedef vector<ll> node;
ll value(vector<ll>a){
	ll res=0,n=SZ(a);
	vector<ll>pas(26,-1);
	fore(i,0,n){
		res=res+ss[i][a[i]]-cs[a[i]]*fn(i-pas[a[i]]-1);
		pas[a[i]]=i;
	}
	fore(i,0,26)res-=cs[i]*fn(n-1-pas[i]);
	/*fore(i,0,n){
		res+=ss[i][a[i]];
		pas[a[i]]=i;
		fore(j,0,26)res-=cs[j]*(i-pas[j]);
	}*/
	return -res;
}
node vecino(node a){
	a[rand()%SZ(a)]=rand()%26;
	return a;
}
/*double temp(double p){
	
}*/
double P(ll old, ll now, double t){
	if(now<old)return 1.0;
	return exp((old-now)/t);
}
double t=1e5;
node simulate(){
	node s(n);
	node best=s;
	fore(i,0,n)s[i]=rand()%26;
	while(clock()/(double)CLOCKS_PER_SEC<=1.99){
		//double t=temp((clock()/(double)CLOCKS_PER_SEC)/1.99);
		node next=vecino(s);
		if(value(s)<value(best))best=s;
		if(P(value(s),value(next),t)>=(double)rand()/RAND_MAX)s=next;
		t*=0.99999;
	}
	return best;
}

int main(){FIN;
	ll sd; srand((ll)&sd);
	cin>>n;
	fore(i,0,26)cin>>cs[i];
	fore(i,0,n)fore(j,0,26)cin>>ss[i][j];
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	node v=simulate();
	for(auto i:v)cout<<i+1<<"\n";
	//cout<<value(v)<<"\n";
	//cout<<t<<"\n";
	return 0;
}
