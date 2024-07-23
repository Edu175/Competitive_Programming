#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e5+5;

//CRT stuff
ii extendedEuclid(ll a, ll b){
	ll x,y;
	if(b==0)return {1,0};
	auto p=extendedEuclid(b,a%b);
	x=p.snd;
	y=p.fst-(a/b)*x;
	if(a*x+b*y==-gcd(a,b))x=-x,y=-y;
	return {x,y};
}
pair<ii,ii> diophantine(ll a, ll b, ll r){
	ll d=gcd(a,b);
	a/=d,b/=d,r/=d;
	auto p=extendedEuclid(a,b);
	p.fst*=r; p.snd*=r;
	assert(a*p.fst+b*p.snd==r);
	return {p,{-b,a}};
}
ll inv(ll a, ll m){
	assert(gcd(a,m)==1);
	ll x=diophantine(a,m,1).fst.fst;
	return ((x%m)+m)%m;
}
#define mod(a,m) (((a)%m+m)%m)
ii sol(tuple<ll,ll,ll>c){
	ll a=get<0>(c),x1=get<1>(c),m=get<2>(c),d=gcd(a,m);
	if(d==1)return {mod(x1*inv(a,m),m),m};
	else return x1%d ? ii({-1LL,-1LL}) : 
	sol(make_tuple(a/d,x1/d,m/d));
}

typedef ii node;
node NEUT={0,1};
node DNF={-1,-1};
node oper(node a, node b){ //crt comb
	auto dbg=[&](node ret){
		// cout<<"oper "<<a.fst<<","<<a.snd<<" "<<b.fst<<","<<b.snd<<" = "<<ret.fst<<","<<ret.snd<<"\n";
	};
	if(a.fst==-1){dbg(a);return a;}
	if(b.fst==-1){dbg(b);return b;}
	auto [x1,m1]=sol({1,a.fst,a.snd});
	auto [x2,m2]=sol({1,b.fst,b.snd});
	if(x1==-1||x2==-1)return DNF; //creo
	if((x1-x2)%gcd(m1,m2))return DNF;
	if(m1==m2)return a;
	ll k=diophantine(m2,-m1,x1-x2).fst.snd,l=m1*(m2/gcd(m1,m2));
	x1=mod((__int128)m1*k+x1,l); m1=l;
	auto ret=sol({1,x1,m1});
	dbg(ret);
	return ret;
}
struct ST{
	ll K; vector<vector<node>>st; 
	ST(vector<node>a):
		K(SZ(a)?64-__builtin_clzll(SZ(a)):0),st(K,vector<node>(SZ(a))){
			fore(i,0,SZ(a))st[0][i]=a[i];
			fore(k,1,K)fore(i,0,SZ(a))if(i+(1ll<<k)<=SZ(a)){
				st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
			}
	}
	/*node query(ll s, ll e){
		ll k=63-__builtin_clzll(e-s);
		return oper(st[k][s],st[k][e-(1ll<<k)]);
	}*/
};
vector<ll>a[MAXN];
vector<ii>h[MAXN];
ll solve(ll v){
	// cout<<"solve "<<v<<"\n";
	// for(auto i:h[v])cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	vector<ii> ini;
	ll m=SZ(h[v]);
	fore(i,0,m){
		if(i&&h[v][(i-1)%m].fst!=h[v][i%m].fst-1)ini.pb({-1,-1});
		ll md=SZ(a[h[v][i%m].fst]);
		ini.pb({(h[v][i%m].snd-(i>=m)+md)%md,md});
	}
	// for(auto i:ini)cout<<i.fst<<","<<i.snd<<" ";;cout<<"\n";
	ST st(ini);
	ll ans=0;
	fore(l,0,SZ(ini)){
		node v=NEUT;
		ll x=l;
		for(ll k=st.K-1;k>=0;k--)if(x+(1ll<<k)<=SZ(ini)){
			node vc=oper(v,st.st[k][x]);
			if(vc!=DNF)v=vc,x+=1ll<<k;
		}
		// cout<<l<<","<<x<<"\n";
		ans=max(ans,x-l);
	}
	return ans;
}

int main(){
	JET
	ll n,m; cin>>n>>m;
	fore(i,0,n){
		ll ki; cin>>ki;
		fore(j,0,ki){
			ll x; cin>>x; x--;
			h[x].pb({i,j});
			a[i].pb(x);
		}
	}
	fore(v,0,m){
		ll res=solve(v);
		cout<<res<<"\n";
	}
	return 0;
}


/*


solve 0
0,2 1,0 2,1 
2,3 -1,-1 0,4 -1,-1 1,3 -1,-1 1,3 -1,-1 3,4 -1,-1 0,3 
oper 2,3 0,4 = 8,12
oper 0,4 1,3 = 4,12
oper 0,4 1,3 = 4,12
oper 1,3 3,4 = 7,12
oper 1,3 3,4 = 7,12
oper 3,4 0,3 = 3,12
oper 0,1 3,4 = 3,4
oper 3,4 0,3 = 3,12
0,11
oper 0,1 0,3 = 0,3
1,11
oper 0,1 0,3 = 0,3
2,11
3,11
oper 0,1 1,3 = 1,3
oper 1,3 3,4 = 7,12
4,10
oper 0,1 7,12 = 7,12
5,10
11
solve 1
1,3 
3,4 2,4 
0,2
oper 0,1 2,4 = 2,4
1,2
2
solve 2
0,0 1,1 2,0 
0,3 -1,-1 1,4 -1,-1 0,3 -1,-1 2,3 -1,-1 0,4 -1,-1 2,3 
oper 0,3 1,4 = 9,12
oper 1,4 0,3 = 9,12
oper 1,4 0,3 = 9,12
oper 2,3 0,4 = 8,12
oper 2,3 0,4 = 8,12
oper 0,4 2,3 = 8,12
oper 0,1 9,12 = 9,12
0,8
oper 0,1 2,3 = 2,3
1,11
oper 0,1 2,3 = 2,3
2,11
oper 0,1 8,12 = 8,12
3,11
oper 0,1 0,4 = 0,4
oper 0,4 2,3 = 8,12
4,11
oper 0,1 8,12 = 8,12
oper 8,12 2,3 = 8,12
5,11
10
solve 3
0,1 1,2 2,2 
1,3 -1,-1 2,4 -1,-1 2,3 -1,-1 0,3 -1,-1 1,4 -1,-1 1,3 
oper 1,3 2,4 = 10,12
oper 2,4 2,3 = 2,12
oper 2,4 2,3 = 2,12
oper 0,3 1,4 = 9,12
oper 0,3 1,4 = 9,12
oper 1,4 1,3 = 1,12
oper 0,1 10,12 = 10,12
0,8
oper 0,1 1,3 = 1,3
1,11
oper 0,1 1,3 = 1,3
2,11
oper 0,1 1,12 = 1,12
3,11
oper 0,1 1,4 = 1,4
oper 1,4 1,3 = 1,12
4,11
oper 0,1 9,12 = 9,12
5,10
10


*/