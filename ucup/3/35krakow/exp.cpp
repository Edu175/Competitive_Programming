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
const ll MAXN=50;
struct UF{
	int uf[MAXN];
	void init(ll n){fore(i,0,n)uf[i]=-1;}
	int find(int x){return uf[x]<0?x:uf[x]=find(uf[x]);}
	bool join(int x, int y){
		x=find(x);y=find(y);
		if(x==y)return false;
		if(uf[x]>uf[y])swap(x,y); // y -> x
		uf[x]+=uf[y];uf[y]=x;
		return true;
	}
};
UF uf;
typedef vector<array<ll,4>> ved;
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		uf.init(n);
		ved ed;
		fore(i,0,m){
			ll x,y,w; char c; cin>>x>>y>>w>>c; x--,y--;
			uf.join(x,y);
			ed.pb({w,c=='R',x,y});
		}
		/*graph is connected, but its useful for debugging*/
		if(-uf.uf[uf.find(0)]!=n){
			fore(i,0,n)cout<<"-1 ";
			cout<<"\n";
			continue;
		}
		/**/
		vv per(m); fore(i,m-(n-1),m)per[i]=1;
		vv ans(n,-1);
		do{
			uf.init(n);
			ll fg=1,sum=0,cant=0;
			fore(i,0,m)if(per[i]){
				auto& [w,c,x,y]=ed[i];
				fg&=uf.join(x,y);
				sum+=w; cant+=c;
			}
			if(fg&&(ans[cant]==-1||sum<ans[cant]))ans[cant]=sum;
		}while(next_permutation(ALL(per)));
		imp(ans);
	}
	return 0;
}
