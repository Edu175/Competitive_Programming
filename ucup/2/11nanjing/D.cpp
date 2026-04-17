#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) do{for(auto i:v)cout<<i<<" "; cout<<"\n";}while(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll INF=1e18;
struct MinQ{
	deque<ii>q; ll dif=0;
	MinQ(){}
	void push(ll x){
		ll cnt=1;
		x-=dif;
		while(SZ(q)&&x<=q.back().fst)cnt+=q.back().snd,q.pop_back();
		q.pb({x,cnt});
	}
	void pop(){
		if(!SZ(q))return;
		if(q.front().snd>1)q.front().snd--;
		else q.pop_front();
	}
	ll query(){
		assert(SZ(q));
		return q.front().fst+dif;
	}
	void add(ll x){dif+=x;}
};

const ll MAXN=1e5+5;

vv g[MAXN];
ll ans[MAXN];
ll a[MAXN];

struct node{
	vv v;
	ll c=0,tam=0,res=0;
};
void relax(vv &dp, ll c){
	MinQ q;
	ll n=SZ(dp);
	fore(i,0,n){
		q.add(1);
		q.push(dp[i]);
		if(i-c-1>=0)q.pop();
		dp[i]=min(dp[i],q.query());
	}
}
void tra(vv &a, ll c, ll tam){
	assert(tam>0);
	ll po=tam-c;
	reverse(ALL(a)); fore(_,0,c)a.pb(INF); reverse(ALL(a));
	fore(_,0,po)a.pb(INF);
	relax(a,po);
	reverse(ALL(a));
	relax(a,c);
	reverse(ALL(a));
}
node dfs(ll x){
	node ret;
	ll tam=SZ(g[x]);
	if(tam==1){
		ret=dfs(g[x][0]);
		ret.c+=a[x]; ret.tam++;
	}
	else if(tam==0){
		ret.v=vv(2);
		ret.v[!a[x]]=1;
	}
	else {
		ll mn=INF;
		for(auto y:g[x]){
			auto cur=dfs(y);
			if(cur.tam){
				tra(cur.v,cur.c,cur.tam);
			}
			mn=min(mn,SZ(cur.v));
			ret.v.resize(mn);
			fore(i,0,SZ(ret.v))ret.v[i]+=cur.v[i];
		}
		tra(ret.v,a[x],1);
		ret.res=*min_element(ALL(ret.v));
	}
	ans[x]=ret.res;
	return ret;
}

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n)g[i].clear();
		fore(i,0,n){
			char c; cin>>c;
			a[i]=c-'0';
		}
		fore(i,1,n){
			ll p; cin>>p; p--;
			g[p].pb(i);
		}
		
		dfs(0);
		
		fore(i,0,n){
			if(i)cout<<" ";
			cout<<ans[i];
		}
		cout<<"\n";
	}
	return 0;
}