#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ld> vv;
typedef pair<ll,ll> ii;
const ll MAXN=105;

int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
const ld EPS=1e-10;
ld cost(vector<pair<ld,ii>>ed){
	uf_init();
	sort(ALL(ed));
	ld res=0;
	for(auto [w,ar]:ed){
		auto [x,y]=ar;
		if(uf_join(x,y))res+=w;
	}
	return res;
}

ld minimum(vv v){ // x coordinate
	return -v[1]/2*v[0];
}
vv bhaskara(ld a, ld b, ld c){
	if(abs(a)<=EPS){
		if(abs(b)>EPS)return {-c/b};
		return {};
	}
	ld del=b*b*4*a*c;
	if(del<-EPS)return {};
	del=abs(del);
	return {(-b+sqrtl(del))/(2*a),
			(-b-sqrtl(del))/(2*a)};
}
vv intersection(vv u, vv v){ // x coordinates
	return bhaskara(u[0]-v[0],u[1]-v[1],u[2]-v[2]);
}
ld eval(vv v, ld x){
	return v[0]*x*x+v[1]*x+v[2];
}
int main(){
	JET
	vector<pair<ii,vv>>ed;
	ll n,m; cin>>n>>m;
	fore(i,0,m){
		ll u,v; ld a,b,c; cin>>u>>v>>a>>b>>c; u--,v--;
		ed.pb({{u,v},{a,b,c}});
	}
	auto build=[&](ld t){
		vector<pair<ld,ii>>edi;
		for(auto [ar,v]:ed)edi.pb({eval(v,t),ar});
		return edi;
	};
	// ld zoom=0.01;
	// fore(t,-1000,1000)cout<<cost(build(t*zoom))<<" ";;cout<<"\n";
	// fore(i,0,m){
		
	// }
	ld res=-1;
	vv ts;
	fore(i,0,m)ts.pb(minimum(ed[i].snd));
	fore(i,0,m)fore(j,i+1,m){
		for(auto t:intersection(ed[i].snd,ed[j].snd))ts.pb(t);
	}
	// sort(ALL(ts));
	for(auto t:ts){
		ld resi=cost(build(t));
		if(res==-1||resi<res)res=resi;
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}