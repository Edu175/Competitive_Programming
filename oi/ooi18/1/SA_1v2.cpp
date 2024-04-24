#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,rus=b;i<rus;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto sdkjg:v)cout<<sdkjg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=8e4+5;
ii a[MAXN];
ll n;
ll operator*(ii a, ii b){
	return a.fst*b.fst+a.snd*b.snd;
}
ii operator-(ii a, ii b){
	return {a.fst-b.fst,a.snd-b.snd};
}
ll hay(ll i){
	if(i<0)return 0;
	ii b=a[p[i+1]]-a[p[i]],c=a[p[i+2]]-a[p[i]];
	return -(c*b<b*b);
	//return 0/-1;
}
ll s=0;
void sw(ll i, ll j){
	s-=hay(i-2)+hay(i-1)+hay(i);
	s-=hay(j-2)+hay(j-1)+hay(j);
	swap(p[i],p[j]);
	s+=hay(i-2)+hay(i-1)+hay(i);
	s+=hay(j-2)+hay(j-1)+hay(j);
}
void SA(){
	srand(175);
	random_shuffle(p,p+n);
	fore(i,0,n-2)s+=hay(i);
	double t=1e9;
	do{
		ll i=rand()%n,j=rand()%n;
		ll old=s;
		sw(i,j);
		if(!(s<=old||exp((old-s)/t)*RAND_MAX>=rand()))sw(i,j);
		t*=0.99999;
	}
	while(clock()<=1.99*CLOCKS_PER_SEC);
	cerr<<t<<"\n";
}

int main(){FIN;
	ll task,group; cin>>task>>group;
	assert(task==1);
	cin>>n;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	fore(i,0,n)p[i]=i;
	SA();
	fore(i,0,n)cout<<p[i]+1<<" ";;cout<<"\n";
	return 0;
}
