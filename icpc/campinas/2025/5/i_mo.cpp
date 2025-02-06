#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
const ll MAXN=500000,ITER=60;
random_device rd;
mt19937 rng(rd());
int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};
qu qs[MAXN];
ll ans[MAXN]; // ans[i] = answer to ith query
ll c[MAXN],a[MAXN];
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
void add(ll x){c[a[x]]++;}
void remove(ll x){c[a[x]]--;}
ll get_ans(ll l, ll r){
	fore(_,0,ITER){
		ll k=a[rng()%(r-l)+l];
		if(c[k]*2>r-l)return k;
	}
	return -1;
}
void mos(){
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)remove(l++);
        while(r>q.r)remove(--r);
        ans[q.id]=get_ans(l,r);
    }
}

int main(){
	JET
	cin>>n>>nq;
	assert(n>=1&&n<=MAXN);
	assert(nq>=1&&nq<=MAXN);
	fore(i,0,n){
		ll x; cin>>x; x--;
		assert(x>=0&&x<n);
		a[i]=x;
	}
	fore(i,0,nq){
		ll l,r; cin>>l>>r; l--;
		assert(l>=0&&l<n);
		assert(r>0&&l<=n);
		assert(l<r);
		qs[i].l=l,qs[i].r=r;
	}
	mos();
	fore(i,0,nq)cout<<ans[i]+1<<"\n";
	return 0;
}