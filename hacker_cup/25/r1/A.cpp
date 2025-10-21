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
const ll MAXN=5e5+5;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

ll n;
vv a;

bool can(ll k){
	uf_init();
	fore(i,0,n-1)if(abs(a[i]-a[i+1])<=k)uf_join(i,i+1);
	fore(i,0,n)if(a[i]<=k)uf_join(i,n);
	ll sz=-uf[uf_find(n)];
	return sz==n+1;
}

int main(){FIN;
	ll t; cin>>t;
	fore(_,0,t){
		cout<<"Case #"<<_+1<<": ";
		cin>>n;
		a=vv(n);
		fore(i,0,n)cin>>a[i];
		ll l=-1,r=1e9+5;
		while(r-l>1){
			ll m=(l+r)/2;
			if(can(m))r=m;
			else l=m;
		}
		ll res=r;
		cout<<res<<"\n";
	}
	return 0;
}
