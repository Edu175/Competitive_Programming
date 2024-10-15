#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector <ll> vv;
typedef long long ld;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	ld operator%(pt p){return x*p.y-y*p.x;}
};
bool operator<(pt p, pt q){
	return p%q<0;
}
int main(){ET
	ll n; cin>>n;
	vector<pt>a(n); vv b(n);
	fore(i,0,n)cin>>a[i].x>>a[i].y>>b[i];
	vector<pair<pt,ll>>ps;
	fore(i,0,n)fore(j,i+1,n){
		pt x=a[i],y=a[j];
		if(b[i]>b[j])swap(x,y);
		if(b[i]==b[j])continue;
		pt p=y-x;
		// cout<<i<<" "<<j<<": "<<p.x<<","<<p.y<<"\n";
		if(p.y<0||(p.y==0&&p.x>0)){ // izq
			ps.pb({pt(-p.x,-p.y),1});
		}
		else { // der
			ps.pb({p,0});
		}
	}
	auto go=[&](vector<pair<pt,ll>>ps){
		sort(ALL(ps));
		// cout<<"go ";
		// for(auto i:ps){
		// 	cout<<"("<<i.fst.x<<","<<i.fst.y<<"),"<<i.snd<<" ";
		// }
		// cout<<"\n";
		
		ll flag=1;
		fore(i,0,SZ(ps)-1){
			flag&=ps[i].snd<=ps[i+1].snd;
		}
		return flag;
	};
	ll flag=0;
	flag|=go(ps);
	for(auto &i:ps)i.fst.x*=-1,i.fst.y*=-1,i.snd^=1;
	flag|=go(ps);
	if(flag)cout<<"Y\n";
	else cout<<"N\n";
	
}

/*

0 1: 1,-3
0 2: 3,1
0 3: 4,-2
1 2: 2,4
2 3: -1,3
(-4,2),1 (-1,3),0 (-1,3),1 (2,4),0 (3,1),0 
N



*/