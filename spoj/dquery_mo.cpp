#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=3e4+5;
ll B=67;

struct qu{ll l,r,idx;};

qu qs[MAXN];

bool cmp(const qu &a, const qu &b){
	return a.l/B==b.l/B?((a.l/B)&1?a.r<b.r:a.r>b.r):a.l<b.r;
}
ll oc[MAXN],a[MAXN];
ll dif=0;

void add(ll x){
	x=a[x];
	oc[x]++;
	dif+=oc[x]==1;
}
void rem(ll x){
	x=a[x];
	oc[x]--;
	dif-=oc[x]==0;
}
ll n,nq;
void mo(){
	sort(qs,qs+nq,cmp);
	ll l=0,r=0;
	fore(i,0,nq){
		auto q=qs[i];
		
	}
}

int main(){FIN;
	cin>>n;
	B=sqrt(n);
	
	return 0;
}