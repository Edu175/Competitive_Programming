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
const ll MAXN=1e5+5,MAXV=1e6+5;

ll n,sq,nq,k;
ll a[MAXN],xp[MAXN],c[2*MAXV],res=0;
void add(ll i){
	res+=c[xp[i]^k];
	c[xp[i]]++;
}
void remove(ll i){
	c[xp[i]]--;
	res-=c[xp[i]^k];
}
struct qu{ll l,r,id;};
qu qs[MAXN];
ll ans[MAXN];
bool qcomp(qu a, qu b){
	if(a.l/sq!=b.l/sq)return a.l<b.l;
	return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
	fore(i,0,nq)qs[i].id=i;
	sq=sqrt(n)+.5;
	sort(qs,qs+nq,qcomp);
	ll l=0,r=0;
	fore(i,0,nq){
		qu q=qs[i];
		while(l>q.l)add(--l);
		while(r<q.r)add(r++);
		while(l<q.l)remove(l++);
		while(r>q.r)remove(--r);
		ans[q.id]=res;
	}
}
int main(){FIN;
	cin>>n>>nq>>k;
	fore(i,0,n)cin>>a[i];
	fore(i,1,n+1)xp[i]=xp[i-1]^a[i-1];
	fore(i,0,nq)cin>>qs[i].l>>qs[i].r,qs[i].l--,qs[i].r++;
	mos();
	fore(i,0,nq)cout<<ans[i]<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
