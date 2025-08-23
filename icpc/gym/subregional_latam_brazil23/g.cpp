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

const ld EPS=0;

struct pt{
	ld x,y;
	pt(ld x,ld y):x(x),y(y){}
	pt(){}
	pt operator-(pt p) {return pt(x-p.x,y-p.y);}
	ld operator%(pt p){return x*p.y-y*p.x;} 
	bool operator<(pt p) const{
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;
	}
};


vector<pair<pt,ll>> chull(vector<pair<pt,ll>>p){
	if(SZ(p)<3)return p;
	vector<pair<pt,ll>> r;
	sort(ALL(p));
	fore(i,0,SZ(p)){
		while(SZ(r)>=2&&r.back().fst.left(r[SZ(r)-2].fst,p[i].fst))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=SZ(r);
	for(int i=SZ(p)-1;i>=0;i--){
		while(SZ(r)>=k+2&&r.back().fst.left(r[SZ(r)-2].fst,p[i].fst))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	// for(auto i:r)cout<<"{"<<i.fst.x<<","<<i.fst.y<<" "<<i.snd<<"} ";;cout<<"\n";
	return r;
}

int main(){
	JET
	int n; cin>>n;
	vector<pair<pt,ll>> a;
	fore(i,0,n){
		int x,y; cin>>x>>y;
		a.pb({pt(x,y),i});
	}
	auto aux=chull(a);
	vector<ll> rta;
	for(auto i:aux)rta.pb(i.snd);
	sort(ALL(rta));
	fore(i,0,SZ(rta)){
		if(!i||rta[i]!=rta[i-1])cout<<rta[i]+1<<" ";
	}
	cout<<"\n";
	return 0;
}