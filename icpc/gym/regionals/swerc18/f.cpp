#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(X) ((ll)X.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long long ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=4005,INF=1e15;

 // - % left
const ld EPS = 0;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator-(pt p) const {return pt(x-p.x,y-p.y);}
	ld operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;
	}
};
struct Cmp{
	pt r;
	Cmp(pt r):r(r){}
	int cuad(const pt &a) const {
		if(a.x>0&&a.y>=0)return 0;
		if(a.x<=0&&a.y>0)return 1;
		if(a.x<0&&a.y<=0)return 2;
		if(a.x>=0&&a.y<0)return 3;
		assert(a.x==0&&a.y==0);
		return -1;
	}
	bool cmp(const pt &p1, const pt &p2) const {
		int c1=cuad(p1),c2=cuad(p2);
		if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
		return c1<c2;
	}
	bool operator()(const pt &p1, const pt &p2) const {
		return cmp(p1-r,p2-r);
	}
};

ll n;
pt a[MAXN];
ll v[MAXN];

ll get(ll s){
	vv per;
	fore(i,0,n)if(i!=s)per.pb(i);
	Cmp cmp(a[s]);
	sort(ALL(per),[&](ll i, ll j){return cmp(a[i],a[j]);});
	auto av=[&](ll i){return (i+1)%(n-1);};
	ll sl=0,sr=0;
	for(auto i:per)sr+=v[i];
	// sl+=v[per[0]];
	// sr-=v[per[0]];
	ll po=0; // primero a la derecha
	ll res=INF;
	fore(_,0,SZ(per)){
		ll i=per[_];
		if(po==_){
			po=av(po);
		}
		while(a[per[po]].left(a[s],a[i])){
			sr-=v[per[po]];
			sl+=v[per[po]];
			po=av(po);
		}
		ll sri=(sr-v[i]);
		ll cur=abs(sl-sri);
		// cout<<s<<" -> "<<i<<": "<<sl<<" "<<sri<<": "<<cur<<"\n";
		res=min(res,cur);
		ll j=per[av(_)];
		if(a[j].left(a[s],a[i])){
			sl-=v[j];
			sr+=v[j];
		}
	}
	return res;
}

int main(){
    JE
	cin>>n;
	fore(i,0,n)cin>>a[i].x>>a[i].y>>v[i];
	// if(n==2){
	// 	cout<<"0\n";
	// 	return 0;
	// }
	ll res=INF;
	fore(s,0,n)res=min(res,get(s));
	cout<<res<<"\n";
    return 0;
}