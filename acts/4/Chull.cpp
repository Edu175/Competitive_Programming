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
typedef int ll;
typedef long double ld;
typedef pair<ll,ll> ii;
//#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ld EPS=1e-10;//00,DINF=63736546543696876837774671.0;
struct pt{
	ld x,y;
	pt(ld x, ld y):x(x),y(y){}
	pt(){}
	ld norm2(){return *this**this;}
	ld norm(){return sqrt(norm2());}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ld t){return pt(x*t,y*t);}
	pt operator/(ld t){return pt(x/t,y/t);}
	ld operator*(pt p){return x*p.x+y*p.y;}
	pt unit(){return *this/norm();}
	ld operator%(pt p){return x*p.y-y*p.x;}
	
	bool left(pt p, pt q){
		return (q-p)%(*this-p)>EPS;
	}
	pt rot90(){
		return pt(-y,x);
	}
};
bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
struct ln{
	pt p,pq;
	ld pen,c;
	ln(pt p, pt q):p(p),pq(q-p){
		pen=pq.y/pq.x;
		if(pq.x<=EPS)c=p.x;
		else c=p.y-pen*p.x;
	}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	//bool operator/(ln l){return abs(pen-l.pen)<=EPS;}
	pt operator^(ln l){ // intersection
		//assert(!(*this/l));
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	ln rot90(){
		return ln(p,p+pq.rot90());
	}
};
vector<ln>a;
bool operator<(ln l, ln r){
	return ((l/r)?l.c<r.c:l.pen<r.pen);
}
string cv(pt p){
	return to_string(p.x)+","+to_string(p.y);
}
string cv(ln l){
	return cv(l.p)+" -> "+cv(l.pq);
}
vector<pt>po;
void new_point(ln l, ln r){
	//cout<<"new point "<<cv(l)<<" ^ "<<cv(r)<<" ??\n";
	if(l/r)return;
	//cout<<"okay\n";
	po.pb(l^r);
}

int main(){FIN;
	cout<<fixed<<setprecision(15)<<"\n";
	set<ln>st;
	ll n; cin>>n;
	while(n--){
		char ty; cin>>ty;
		pt p,q; cin>>p.x>>p.y>>q.x>>q.y;
		ln l(p,q);
		if(ty=='+'){
			st.insert(l);
			auto it=st.lower_bound(l);
			if(it!=st.begin())new_point(l,*prev(it));
			else new_point(l,*prev(st.end()));
			if(it!=prev(st.end()))new_point(l,*next(it));
			else new_point(l,*st.begin());
		}
		else {
			pt v[4];
			v[0]=l.pq;
			fore(i,1,4)v[i]=v[i-1].rot90();
			if(!SZ(po)){
				cout<<"0\n";
				continue;
			}
			ld ans[4];
			fore(i,0,4)ans[i]=v[i]*po[0];
			fore(i,1,SZ(po))fore(h,0,4)ans[h]=max(ans[h],v[h]*po[i]);
			//for(auto i:po)cout<<cv(i)<<" ";;cout<<" points!\n";
			fore(i,0,4)ans[i]/=v[i].norm();
			ld res=(ans[0]+ans[2])*(ans[1]+ans[3]);
			//imp(ans);
			cout<<res<<"\n";
		}
		
	}
	return 0;
}
