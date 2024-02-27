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
	pt()x(0),y(0){}
	pt(ll x, ll y):x(x),y(y){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	ll norm2(){return x*x+y*y;}
};

const ll MAXN=1e5+5;
vector<pt>d={pt(1,0),pt(0,1),pt(-1,0),pt(0,-1)};
pt a[MAXN];
typedef pair<pt,bitset<MAXN>> tf;
int main(){FIN;
	ll n; srand((ll)&n); cin>>n;
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	random_shuffle(a,a+n);
	vector<tf>v(1);
	fore(i,0,n){
		vector<tf>all;
		fore(j,0,SZ(d)){
			all.pb({v[j].fst+a[i],v[j].snd});
			v[j].snd[i]=1;
			all.pb({v[j].fst-a[i],v[j].snd});
		}
		vector<pt>vi;
		for(auto di:d){
			pt x;
			bitset<MAXN>bt;
			ll did=0;
			for(auto [p,b]:all){
				if(di*p>0){
					if(!did||p*di<x*di)x=p,,bt=b,did=1;
				}
			}
			if(did)vi.pb(x);
		}
		v=vi;
	}
	
	return 0;
}
