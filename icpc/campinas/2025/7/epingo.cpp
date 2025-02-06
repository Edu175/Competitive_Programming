#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long long ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
struct pt{
	ll x,y;
	pt(ll x, ll y): x(x),y(y) {}
	pt(){}
	ll norm2(){return *this**this;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	ll operator%(pt){return x*p.y-y*p.x;}
}
int main(){
	ll n; cin>>n;
	vector<pt> pol;	
}