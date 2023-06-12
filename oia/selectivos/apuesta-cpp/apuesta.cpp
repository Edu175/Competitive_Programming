#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(a) for(auto messi:a)cout<<messi<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
//#define bint __int128
//typedef __int128 bint;
#define angle pair<ll,frac>

struct frac{
	ll num,den;
	frac(ll a, ll b):num(a),den(b){
		ll g=__gcd(num,den);
		//cout<<g<<" "<<num<<"/"<<den<<" --> ";
		if(g!=0)num/=g,den/=g;
		if(den<0)num*=-1,den*=-1;
		if(den==0&&num<0)num*=-1,den*=-1;
		//cout<<num<<"/"<<den<<"\n";
	}
	frac(){}
	double aprox(){return double(num)/den;}
	bool operator==(frac f){return (num==f.num&&den==f.den);}
	bool operator!=(frac f){return !(*this==f);}
	frac operator+(frac f){return frac(num*f.den+f.num*den,den*f.den);}
	frac operator-(frac f){return frac(num*f.den-f.num*den,den*f.den);}
	frac operator*(frac f){return frac(num*f.num,den*f.den);}
	frac operator/(frac f){return *this*frac(f.den,f.num);}
};
bool operator<(frac f,frac g){
	if(f.den==0)return 0;
	if(g.den==0)return 1;
	return f.aprox()<g.aprox();
	//return /*(bint)*/f.num*g.den</*(bint)*/g.num*f.den;
}
struct pt{
	frac x,y;
	pt(ll x, ll y):x(frac(x,1)),y(frac(y,1)){}
	pt(){}
	bool operator==(pt p){return (x==p.x&&y==p.y);}
	bool operator!=(pt p){return !(*this==p);}
};
bool operator<(pt p, pt q){
	pair<frac,frac>p0={p.x,p.y},p1={q.x,q.y};
	return p0<p1;
}
struct ln{
	pt p, q;
	frac a,b;
	ln(){}
	ln(pt p, pt q):p(p),q(q){
		a=(p.y-q.y)/(p.x-q.x),b=p.y-a*p.x;
		//cout<<"ab "<<a.num<<"/"<<a.den<<" "<<b.num<<"/"<<b.den<<"\n";
		//cout<<p.y.num<<"/"<<p.y.den<<" - ("<<a.num<<"/"<<a.den<<")*("<<p.x.num<<"/"<<p.x.den<<")\n";
		//cout<<(a*p.x).num<<"/"<<(a*p.x).den<<"\n";
		
	}
	pt operator^(ln l){ //intersection  PUNTO NO ENTERO
		pt res;
		res.x=(b-l.b)/(l.a-a);
		res.y=a*res.x+b;
		return res;
	}
};
vector<pt>a; ll n;
angle ang(pt p, pt q){
	angle res;
	res.snd=(p.y-q.y)/(p.x-q.x);
	//cout<<"ang: ("<<p.y.num<<"/"<<p.y.den<<"-"<<q.y.num<<"/"<<q.y.den<<") / ("<<p.x.num<<"/"<<p.x.den<<"-"<<q.x.num<<"/"<<q.x.den<<") "<<": "<<(p.y-q.y).num<<"/"<<(p.y-q.y).den<<": "<<res.snd.num<<"/"<<res.snd.den<<"\n";
	res.fst=(q<p);
	return res;
}
vector<angle> srt(pt p){// sort points by pendiente
	vector<angle>res;
	fore(i,0,n)if(a[i]!=p){
		res.pb(ang(p,a[i]));
		//auto j=res.back();
		//cout<<i<<": "<<j.fst<<",("<<j.snd.num<<"/"<<j.snd.den<<")\n";
	}
	//cout<<"\n";
	sort(ALL(res));
	return res;
}
pair<bool,bool> check(vector<angle>&b, frac m){ //sorted vector of points, check if line m cumple
	ll l0,l1,r0,r1;
	angle s={0,m},e={1,m};
	l0=lower_bound(ALL(b),s)-b.begin(); l1=upper_bound(ALL(b),s)-b.begin();
	r0=lower_bound(ALL(b),e)-b.begin(); r1=upper_bound(ALL(b),e)-b.begin();
	ll q0=l0+SZ(b)-r1,q1=r0-l1;
	//cout<<"ch "<<m.num<<"/"<<m.den<<": "<<l0<<","<<l1<<" "<<r0<<","<<r1<<": "<<q0<<" "<<q1<<"\n";
	return {(q0==q1),(l1-l0==r1-r0)};
}
vector<double> apuesta(vector<int> &X, vector<int> &Y){
	n=SZ(X);
	a.resize(n);
	fore(i,0,n)a[i]=pt(X[i],Y[i]);
	pt l0=a[0],r0=l0; ll flag=0;
	vector<angle>h=srt(l0);
	/*for(auto i:h)cout<<i.fst<<",("<<i.snd.num<<"/"<<i.snd.den<<") ";
	cout<<"\n";*/
	fore(i,0,n)if(a[i]!=l0&&check(h,ang(l0,a[i]).snd).fst){r0=a[i],flag=1;}
	//cout<<"done line0\n";
	//cout<<"nopaso\n"<<l0.x.num<<","<<l0.y.num<<" "<<r0.x.num<<","<<r0.y.num<<"\n";
	if(!flag)return {};
	//cout<<"paso\n";
	pt l1,r1;
	frac ph=ang(l0,r0).snd; flag=0;
	fore(i,0,n)if(a[i]!=l0&&ang(a[i],l0).snd!=ph){
		//cout<<"nashe\n";
		//cout<<i<<"\n";
		l1=a[i];
		flag=1;
		break;
	}
	//cout<<"is alineados?\n";
	if(!flag){// alineados
		sort(ALL(a));
		double x=a[(n+1)/2-1].x.aprox(),y=a[(n+1)/2-1].y.aprox();
		return {x,y};
	}
	//cout<<"start line1\n";
	r1=l1; flag=0;
	h=srt(l1);
	fore(i,0,n)if(a[i]!=l1&&check(h,ang(l1,a[i]).snd).fst){r1=a[i],flag=1;}
	//cout<<"done line1\n";
	//cout<<"linea 0: "<<l0.x.num<<","<<l0.y.num<<" "<<r0.x.num<<","<<r0.y.num<<"\n";
	//cout<<"linea 1: "<<l1.x.num<<","<<l1.y.num<<" "<<r1.x.num<<","<<r1.y.num<<"\n";
	//cout<<"nopaso\n";
	if(!flag)return {};
	//cout<<"mentira si paso crack\n";
	pt c=ln(l0,r0)^ln(l1,r1); // might not be lattice
	//cout<<"c "<<c.x.num<<"/"<<c.x.den<<" , "<<c.y.num<<"/"<<c.y.den<<"\n";
	h=srt(c);
	flag=1;
	fore(i,0,n){
		if(a[i]!=c&&!check(h,ang(c,a[i]).snd).snd)flag=0;
	}
	if(flag)return{double(c.x.num)/c.x.den,double(c.y.num)/c.y.den};
	//cout<<flag<<"\n";
	return {};
}
