#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef __int128_t xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	xl operator%(pt p){return xl(x)*xl(p.y)-xl(y)*xl(p.x);}
	bool left(pt p, pt q){return(q-p)%(*this-p);}
		
};
vector<pt> chull(vector<pt> p){
	if(SZ(p)<3)return p;
	vector<pt> r; int k = 0;
	fore(_,0,2){
		fore(i,0,SZ(p)){
			while(SZ(r)>1+k && r.back().left(r[SZ(r)-2],p[i]))r.pop_back();
			r.pb(p[i]);
		}
		r.pop_back(), k = SZ(r),reverse(ALL(p));
	}
}

int main(){
	JET
	ll n,m;
	return 0;
}