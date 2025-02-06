#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
struct pt{
	ll x,y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	bool operator==(pt p){return x==p.x&&y==p.y;}
	ll norm2(){return x*x+y*y;}
};

const ll MAXN=1e5+5;
vector<pt>D={
	/*pt(1,0),pt(0,1),pt(-1,0),pt(0,-1), 
	pt(1,1),pt(-1,1),pt(-1,-1),pt(1,-1)*/
};
const ll EX=10;
pt a[MAXN];
ll n;
vector<pt> dp[MAXN];
ll ans[MAXN];
vector<pair<pt,ll>>b;
ll u=(1ll<<16)-1;
pt solve(){
	random_shuffle(ALL(b));
	fore(i,0,n)a[i]=b[i].fst;
	//fore(i,0,n+3)vis[i]=0;
	//dp 
	auto d=D;
	fore(i,0,EX)d.pb(pt((rand()&u)-(u>>1),(rand()&u)-(u>>1)));
	dp[n]={pt(0,0)};
	for(ll i=n-1;i>=0;i--){
		vector<pt> &v=dp[i+1], all, vi;
		fore(j,0,SZ(v))all.pb(v[j]+a[i]),all.pb(v[j]-a[i]);
		for(auto di:d){
			pt x=pt(0,0);
			ll did=0;
			for(auto p:all){
				if(di*p>0){
					if(!did||p.norm2()<x.norm2())x=p,did=1;
				}
			}
			if(did)vi.pb(x);
		}
		dp[i]=vi;
	}
	//
	vector<pt>&v=dp[0];
	pt res=v[0];
	for(auto i:v)if(i.norm2()<res.norm2())res=i;
	return res;
}
const ll AC=1.5e6;
int main(){FIN;
	ll sd; srand((ll)&sd);
	cin>>n;
	b.resize(n);
	fore(i,0,n)cin>>b[i].fst.x>>b[i].fst.y,b[i].snd=i;
	pt res=solve();
	while(res.norm2()>AC*AC)res=solve();
	//build
	fore(i,0,n){
		vector<pt>&v=dp[i+1];
		//cout<<i<<": "<<res.x<<","<<res.y<<" "<<a[i].x<<","<<a[i].y<<":\n"; 
		//for(auto i:v)cout<<i.x<<","<<i.y<<" ";;cout<<"\n";
		fore(j,0,SZ(v)){
			if(res==v[j]+a[i]){ans[i]=1;res=v[j];break;}
			if(res==v[j]-a[i]){ans[i]=-1;res=v[j];break;}
		}
	}
	
	vector<ll>us(n);
	fore(i,0,n)us[b[i].snd]=ans[i];
	fore(i,0,n)cout<<us[i]<<" ";
	cout<<"\n";
	return 0;
}
