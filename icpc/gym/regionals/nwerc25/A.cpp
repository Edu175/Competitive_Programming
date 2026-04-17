#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;


map<vv,ii> dp;
ii NOF={-1,-1};
map<vv,ii> fa;
map<vv,vv> wfa;
void dfs(vv a){
	fore(i,0,SZ(a)-2){
		vv b=a; b.erase(b.begin()+i,b.begin()+i+3);
		fore(j,0,SZ(b)+1){
			vv c;
			fore(k,0,j)c.pb(b[k]);
			fore(k,i,i+3)c.pb(a[k]);
			fore(k,j,SZ(b))c.pb(b[k]);
			if(!fa.count(c)){
				fa[c]={i,j};
				wfa[c]=a;
				dfs(c);
			}
		}
	}
}

int main(){
    JET
	vv s(5); iota(ALL(s),0);
	fa[s]=NOF;
	dfs(s);
	// cout<<SZ(fa)<<"\n";
	// for(auto [a,f]:fa){
	// 	for(auto i:a)cout<<i<<" ";;cout<<"\n";
	// }
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	vector<ii> res;
	auto mop=[&](ll i, ll j){
		assert(i+3<=n&&j+3<=n);
		res.pb({i,j});
		vv b(a.begin()+i,a.begin()+i+3);
		a.erase(a.begin()+i,a.begin()+i+3);
		vv c;
		fore(k,0,j)c.pb(a[k]);
		fore(k,0,3)c.pb(b[k]);
		fore(k,j,SZ(a))c.pb(a[k]);
		swap(a,c);
	};
	fore(x,0,n-5){
		ll i=find(ALL(a),x)-a.begin();
		if(i>n-3){
			mop(n-3,n-5);
			i=find(ALL(a),x)-a.begin();
		}
		assert(i<=n-3);
		mop(i,x);
	}
	vv wh(a.end()-5,a.end());
	for(auto &i:wh)i-=n-5;
	// for(auto i:wh)cout<<i<<" ";;cout<<" wh\n";
	vector<ii> movs;
	while(fa[wh]!=NOF){
		auto cur=fa[wh];
		// for(auto i:wh)cout<<i<<" ";;cout<<" wh ";
		// cout<<cur.fst<<","<<cur.snd<<" | ";
		swap(cur.fst,cur.snd);
		cur.fst+=n-5;
		cur.snd+=n-5;
		// cout<<cur.fst<<","<<cur.snd<<"\n";
		movs.pb(cur);
		wh=wfa[wh];
	}
	// for(auto i:wh)cout<<i<<" ";;cout<<" final wh\n";
	// reverse(ALL(movs));
	for(auto [i,j]:movs)mop(i,j);
	assert(SZ(res)<=5000);
	vv id(n); iota(ALL(id),0);
	// for(auto i:a)cout<<i<<" ";;cout<<" final a\n";
	// cout<<endl;
	assert(a==id);
	cout<<SZ(res)<<"\n";
	for(auto [i,j]:res)cout<<i+1<<" "<<j+1<<"\n";
    return 0;
}