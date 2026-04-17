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
	pt(ll x, ll y): x(x), y(y){};
	pt(){};
};
bool operator<(pt p, pt q){ii a={p.x,p.y}, b={q.x,q.y}; return a<b;}
bool operator<=(pt p, pt q){ii a={p.x,p.y}, b={q.x,q.y}; return a<=b;}
ll dis(pt p, pt q){
	return (p.x-q.x)*(p.x-q.x)+(p.y-q.y)*(p.y-q.y);
}
int main(){FIN;
	ifstream cin; cin.open("placas.in", ios::in);
	ofstream cout; cout.open("placas.out", ios::out);
	ll k,n; cin>>k>>n;
	pt a[n];
	fore(i,0,n)cin>>a[i].x>>a[i].y;
	/*fore(i,0,n)cout<<a[i].x<<","<<a[i].y<<" ";
	cout<<"\n";*/
	set<pt>p;
	fore(i,0,n){
		pt esq[4];
		esq[0]=pt(a[i].x-k,a[i].y+k);
		esq[1]=pt(a[i].x+k,a[i].y+k);
		esq[2]=pt(a[i].x-k,a[i].y-k);
		esq[3]=pt(a[i].x+k,a[i].y-k);
		for(pt i=esq[0];i<=esq[1];i.x++)p.insert(i);
		for(pt i=esq[2];i<=esq[3];i.x++)p.insert(i);
		for(pt i=esq[2];i<=esq[0];i.y++)p.insert(i);
		for(pt i=esq[3];i<=esq[1];i.y++)p.insert(i);
	}
	ll res=0;
	for(auto pi:p){
		ll flag=1;
		fore(j,0,n){
			if(dis(pi,a[j])<k*k)flag=0;
			//cout<<pi.x<<","<<pi.y<<" "<<a[j].x<<","<<a[j].y<<"\n";
		}
		res+=flag;
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

