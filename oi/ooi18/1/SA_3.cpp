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
	return (a.fst*b.fst)+(a.snd*b.snd);
}
ii operator-(ii a, ii b){
	return {a.fst-b.fst,a.snd-b.snd};
}
int hay(int i){
	if(i<0||i+2>=n)return 0;
	ii b=a[p[i+1]]-a[p[i]],c=a[p[i+2]]-a[p[i]];
	//cout<<"hay "<<p[i]<<" "<<p[i+1]<<" "<<p[i+2]<<" = "<<(c*b<b*b)<<"\n";
	//cout<<(c*b)<<"<"<<b*b<<"\n";
	return (c*b<b*b);
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
	random_shuffle(p,p+n);
	s=0;
	fore(i,0,n-2)s+=hay(i);
	double t=1e5;
	while(s!=c){
		int i=rand()%n,j=rand()%n;
		int old=abs(s-c);
		sw(i,j);
		int now=abs(s-c);
		//if(s<=c)break;
		if(!(now<old||exp((old-now)/t)*RAND_MAX>=rand()))sw(i,j);
		t*=0.999;
	}
	//while(clock()<=1.9*CLOCKS_PER_SEC);
	cerr<<t<<"\n";
}

int main(){FIN;
	int task,group; cin>>task>>group;
	srand(175);
	assert(task==3);
	cin>>n;
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	//cin>>c;
	fore(i,0,n)p[i]=i;
	cin>>c;
	int q; cin>>q;
	while(q--){
		cin>>c;
		SA();
		//cout<<"END=============================\n";
		/*ll si=0;
		fore(i,0,n-2)si+=hay(i);
		cout<<s<<" ("<<si<<")\n";*/
		fore(i,0,n)cout<<p[i]+1<<" ";;cout<<endl;
	}
	return 0;
}
