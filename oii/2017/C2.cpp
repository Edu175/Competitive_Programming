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
typedef int ll;
typedef pair<ll,ll> ii;
const ll MAXN=5e4+5,MAXM=105;

ll oc[MAXM],sp[MAXN];
ll res;
void add(ll i){
	res+=oc[sp[i]]++;
}
void remove(ll i){
	res-=--oc[sp[i]];
}
ll get_ans(){
	return res;
}
struct qu{ll l,r,id;};
ll n,m,nq,sq;
qu qs[MAXN];
ll ans[MAXN];
bool qcomp(const qu &a, const qu &b){
	if(a.l/sq!=b.l/sq)return a.l<b.l;
	return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void mos(){
	sq=sqrt(n)+.5;
	fore(i,0,nq)qs[i].id=i;
	sort(qs,qs+nq,qcomp);
	ll l=0,r=0;
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
	cin>>n>>m>>nq;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	fore(i,1,n+1)sp[i]=(sp[i-1]+a[i-1])%m;
	fore(i,0,nq){
		cin>>qs[i].l>>qs[i].r; qs[i].l--,qs[i].r++;
	}
	mos();
	fore(i,0,nq)cout<<ans[i]<<"\n";
	return 0;
}
