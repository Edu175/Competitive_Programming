#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

struct pt{
	ll x,y;
	pt(ll x, ll y):x(x),y(y){};
	pt(){};
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	bool operator==(pt p){return (x==p.x&&y==p.y);}
	ll operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){return (p-*this)%(q-*this)>0;}
};

ll cnt(pt a, pt b){
	return abs(gcd(a.x-b.x,a.y-b.y));
}
int main(){FIN;
	ll n; cin>>n;
	pt a[n];
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	ll ar=0,b=0,in=0;
	fore(i,0,n)b+=cnt(a[i],a[(i+1)%n]);
	fore(i,0,n)ar+=a[i]%a[(i+1)%n];
	ar/=2;
	ar=abs(ar);
	in=1+ar-b/2;
	cout<<in<<" "<<b<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
