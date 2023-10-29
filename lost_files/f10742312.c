#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=2e5+5;

ll a[MAXN],res;
ll c[MAXN];
ll to3(ll r){
	return r*(r-1)*(r-2)/6;
}
void add(ll i){
	res=res-to3(c[a[i]])+to3(++c[a[i]]);
}
void remove(ll i){
	res=res-to3(c[a[i]])+to3(--c[a[i]]);
}
void init(){}
ll get_ans(){return res;}

ll n,sq,nq;
struct qu{ll l,r,id;};
qu qs[MAXN];
ll ans[MAXN];
bool qcomp(qu a, qu b){
	if(a.l/sq!=b.l/sq)return a.l<b.l;
	return (((a.l/sq)&1)?(a.r<b.r):(a.r>b.r));
}

void mos(){
	fore(i,0,nq)qs[i].id=i;
	sq=sqrt(n)+.5;
	sort(qs,qs+nq,qcomp);
	ll l=0,r=0;
	init();
	fore(i,0,nq){
		qu q=qs[i];
		while(l>q.l)add(--l);
		while(r<q.r)add(r++);
		while(l<q.l)remove(l++);
		while(r>q.r)remove(--r);
		ans[q.id]=get_ans();
	}
}

int main(){FIN;
	cin>>n>>nq;
	fore(i,0,n)cin>>a[i];
	fore(i,0,nq)cin>>qs[i].l>>qs[i].r,qs[i].l--;
	mos();
	fore(i,0,nq)cout<<ans[i]<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
