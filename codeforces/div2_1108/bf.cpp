#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {cerr<<"{ ";for(auto i:v)cerr<<i+1<<", "; cerr<<"}\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
vv mv(vv y, ll i){
	rotate(y.begin(),y.begin()+i,y.begin()+i+1);
	rotate(y.begin()+i+1,y.begin()+i+2,y.end());
	return y;
}
ll n;
vv u;
bool good(vv a){
	fore(i,0,SZ(a))if(u[i]!=-1&&u[i]!=a[i])return 0;
	return 1;
}
vv up(vv a){for(auto &i:a)i++;return a;}
vv bfs(vv s){
	map<vv,vv> fa;
	map<vv,ll> wh;
	wh[s]=-1;
	queue<vv>q;
	set<vv> st;
	q.push(s); st.insert(s);
	if(good(s))return {};
	ll n=SZ(s);
	vv e;
	while(SZ(q)){
		auto x=q.front(); q.pop();
		fore(i,0,n-1){
			auto y=mv(x,i);
			if(st.count(y))continue;
			st.insert(y);
			wh[y]=i; fa[y]=x; q.push(y);
			if(good(y)){e=y;break;}
		}
		if(SZ(e))break;
	}
	if(!SZ(e))return {-1};
	auto x=e;
	vv ret;
	while(wh[x]!=-1)ret.pb(wh[x]),x=fa[x];
	reverse(ALL(ret));
	return ret;
}

void see(vv a, vv ops){
	cerr<<"ops: ";
	if(ops==vv(1,-1)){
		cout<<"-1\n";
		return;
	}
	cout<<SZ(ops)<<"\n";
	for(auto i:ops)cout<<i+1<<" ";;cout<<"\n";
	cerr<<"as:\n";
	show(a)
	for(auto i:ops){
		a=mv(a,i);
		show(a)
	}
	cerr<<"good? "<<good(a)<<"\n";
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		u=vv(n);
		fore(i,0,n)cin>>u[i],u[i]--;
		auto ret=bfs(a);
		see(a,ret);
		cerr<<"\n";
		see(a,{0,n-2,1,1,1,1,1,1});
	}
	return 0;
}
