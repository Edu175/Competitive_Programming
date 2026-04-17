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
const ll MAXN=16,INF=1e10+5;

struct pt{
	ll x,y;
	pt(ll x, ll y): x(x), y(y){};
	pt(){};
};
struct node{
	pt s,b; ll v;
	node(pt s, pt b, ll v):s(s),b(b),v(v){};
	node(){};
};
bool operator<(node a, node b){
	ii c={a.s.x,a.s.y},d={b.s.x,b.s.y};
	return c<d;
}
ll k;
ll cnt(pt s, pt b){
	return (b.x-s.x+b.y-s.y)*2+8*k;
}
map<vector<node>,ll>dp;
ll f(vector<node>&c){
	ll &res=dp[c];
	if(res)return res;
	for(auto i:c)res+=i.v;
	fore(i,0,SZ(c)){
		fore(j,i+1,SZ(c)){
			vector<node>ci;
			pt s,b;
			s.x=min(c[i].s.x,c[j].s.x),s.y=min(c[i].s.y,c[j].s.y);
			b.x=max(c[i].b.x,c[j].b.x),b.y=max(c[i].b.y,c[j].b.y);
			ll q=0;
			fore(h,0,SZ(c)){
				if(h!=i&&h!=j)ci.pb(c[h]);
				else if(!q)ci.pb(node(s,b,cnt(s,b))),q++;
			}
			res=min(res,f(ci));
		}
	}
	for(auto i:c)cout<<"{"<<i.s.x<<","<<i.s.y<<" "<<i.b.x<<","<<i.b.y<<" "<<i.v<<"} ";
	cout<<"\n"<<res<<"\n";
	return res;
}
int main(){//FIN;
	ifstream cin; cin.open("placas.in", ios::in);
	//ofstream cout; cout.open("placas.out", ios::out);
	ll n; cin>>k>>n;
	pt a[n];
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	vector<node>c;
	fore(i,0,n)c.pb(node(a[i],a[i],cnt(a[i],a[i])));
	cout<<f(c)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

