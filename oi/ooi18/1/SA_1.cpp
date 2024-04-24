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
const int MAXN=8e4+5;
ii a[MAXN];
int p[MAXN];
int n;
ll operator*(ii a, ii b){
	return a.fst*b.fst+a.snd*b.snd;
}
ii operator-(ii a, ii b){
	return {a.fst-b.fst,a.snd-b.snd};
}
int hay(int i){
	if(i<0||i+2>=n)return 0;
	ii b=a[p[i+1]]-a[p[i]],c=a[p[i+2]]-a[p[i]];
	return -(c*b<b*b);
	//return 0/-1;
}
int s=0,c;
void sw(int i, int j){
	if(abs(i-j)<3){
		if(i>j)swap(i,j);
		fore(h,i-2,j+1)s-=hay(h);
		swap(p[i],p[j]);
		fore(h,i-2,j+1)s+=hay(h);
		return;
	}
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
		int i=rand()%n,j=rand()%n;
		int old=s;
		sw(i,j);
		//if(s<=c)break;
		if(!(s<=old||exp((old-s)/t)*RAND_MAX>=rand()))sw(i,j);
		t*=0.99999;
	}
	while(clock()<=1.9*CLOCKS_PER_SEC);
	cerr<<t<<"\n";
}

int main(){FIN;
	int task,group; cin>>task>>group;
	assert(task==1);
	cin>>n;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	//cin>>c;
	fore(i,0,n)p[i]=i;
	SA();
	fore(i,0,n)cout<<p[i]+1<<" ";;cout<<"\n";
	return 0;
}
