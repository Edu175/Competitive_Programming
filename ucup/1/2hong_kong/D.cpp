#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
struct pt{
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	ll operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>0;
	}
	bool leftOrAt(pt p, pt q){return !left(q,p);}
	bool operator<(const pt &p)const {
		if(x!=p.x)return x<p.x;
		return y<p.y;
	}
};
const ll D=1005;

int main(){
	JET
	ll n,m; cin>>n>>m;
	vector<vector<ii>> ing(n);
	fore(i,0,m){
		ll u,v,c; cin>>u>>v>>c; u--,v--;
		ing[v].pb({u,c});
	}
	vector<vector<pt>> chs(D);
	ll q; cin>>q;
	vv ans(q);
	vector<vector<array<ll,3>>> resp(n);
	fore(i,0,q){
		ll a,b,x; cin>>a>>b>>x; x--;
		resp[x].pb({a,b,i});
	}
	fore(x,0,n){
		auto &cur=chs[x%D]; cur.clear();
		vector<pt> all;
		for(auto [y,c]:ing[x]){
			for(auto p:chs[y%D]){
				if(c)p.y++;
				else p.x++;
				all.pb(p);
			}
		}
		sort(ALL(all));
		if(!x)cur={{0,0}};
		else {
			cur.pb(all[0]);
			fore(i,1,SZ(all)){
				auto &p=all[i];
				while(SZ(cur)>1&&cur.back().leftOrAt(cur.end()[-2],p))cur.pop_back();
				cur.pb(p);
			}
		}
		for(auto [a,b,i]:resp[x]){
			ll res=(a+b+100)*n;
			for(auto p:cur)res=min(res,p.x*a+p.y*b);
			ans[i]=res;
		}
	}
	for(auto i:ans)cout<<i<<"\n";
	return 0;
}