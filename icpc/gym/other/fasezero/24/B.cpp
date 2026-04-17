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
const ll MAXN=2e5+5;
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
int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vector<pair<ll,ii>>ed;
	fore(i,0,m){
		ll u,v,c; cin>>u>>v>>c; u--,v--;
		ed.pb({c,{u,v}});
	}
	uf_init();
	sort(ALL(ed));
	if(k==1){
		cout<<"0\n";
		return 0;
	}
	ll t=-1;
	for(auto [c,p1]:ed){
		auto [u,v]=p1;
		uf_join(u,v);
		if(-uf[uf_find(0)]>=k){
			t=c;
			break;
		}
	}
	cout<<t<<"\n";
	return 0;
}
