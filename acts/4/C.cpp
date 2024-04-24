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
struct ln{
	pt p,pq;
	ld pen;
	ln(pt p, pt q):p(p),pq(q-p){pen=pq.y/pq.x;}
	ln(){}
	bool operator/(ln l){return pen==l.pen;}//return abs(pq.unit()%l.pq.unit())<=EPS;}
	//bool operator/(ln l){return abs(pen()-l.pen())<=EPS;}
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
bool operator<(const ln& l, const ln& r){
	return l.pen<r.pen;
}
string cv(pt p){
	return to_string(p.x)+","+to_string(p.y);
}
string cv(ln l){
	return cv(l.p)+" -> "+cv(l.pq);
}
bool can(ln l){
	fore(i,0,SZ(a)){
		ln s=a[i],e=a[(i+1)%SZ(a)];
		if(s/e)continue;
		if((s^e).left(l.p,l.p+l.pq))return 0;
	}
	return 1;
}
ln move(ln l, ld x){ //x perpendicular to the left
	pt v=(l.pq.unit()).rot90();
	l.p=l.p+v*x;
	return l;
}
ld bs(ln l){
	ld s=-1e15,e=1e15;
	//cout<<"bs "<<cv(l)<<endl;
	//while(can(move(l,s)))s=s+s;
	//while(!can(move(l,e)))e=e+e;
	//assert(!can(move(l,s)));
	//assert(can(move(l,e)));
	ll it=67;
	//while(it--){
	while(e-s>=1e-5){
		ld m=(s+e)/2;
		if(can(move(l,m)))e=m;
		else s=m;
	}
	//if(debug==2)debug=3;
	//can(move(l,s));
	//cout<<"bs "<<cv(l)<<" = "<<s<<" = "<<cv(move(l,s))<<"\n";
	return s;
}
int main(){FIN;
	cout<<fixed<<setprecision(15)<<1e15<<"\n";
	ll n; cin>>n;
	while(n--){
		char ty; cin>>ty;
		pt p,q; cin>>p.x>>p.y>>q.x>>q.y;
		ln l(p,q);
		if(ty=='+'){
			a.pb(l);
		}
		else {
			ll flag=1;
			fore(i,0,SZ(a)-1)flag&=a[i]/a[i+1];
			if(flag){
				cout<<"0\n";
				continue;
			}
			sort(ALL(a));
			ln v[4];
			v[0]=l;
			fore(i,1,4)v[i]=v[i-1].rot90();
			ld ans[4];
			fore(i,0,4)ans[i]=bs(v[i]);
			ld res=(ans[0]+ans[2])*(ans[1]+ans[3]);
			//imp(ans);
			cout<<res<<"\n";
		}
		
	}
	return 0;
}
