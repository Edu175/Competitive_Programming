#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=2e5+5;
int n,sq,nq; // array size, sqrt(array size), #queries
struct qu{int l,r,id;};
qu qs[MAXN];
ll ans[MAXN]; // ans[i] = answer to ith query
bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}
vv cnt(2);
void init(){
	cnt=vv(2,0);
}
ll a[MAXN];
void ch(ll i, ll t, ll del){
	ll j=i+(t?-1:1);
	if(j==-1){
		// cerr<<"chota\n";
		return;
	}
	if(a[i]==a[j])cnt[a[i]]+=del;
}
ll get_ans(){
	ll a=cnt[0],b=cnt[1];
	ll res=min(a,b);
	ll s=max(a,b)-res;
	res+=s+1;
	return res;
}
void mos(){
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    init();
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)ch(--l,0,+1);
        while(r<q.r)ch(r++,1,+1);
        while(l<q.l)ch(l++,0,-1);
        while(r>q.r)ch(--r,1,-1);
        ans[q.id]=get_ans();
    }
}
int main(){FIN;
	cin>>n>>nq;
	fore(i,0,n){
		char c; cin>>c;
		a[i]=c-'0';
	}
	fore(i,0,nq){
		ll l,r; cin>>l>>r; l--;
		qs[i].l=l;
		qs[i].r=r;
	}
	mos();
	fore(i,0,nq)cout<<ans[i]<<"\n";
	return 0;
}
