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
typedef double ld;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ld EPS=1e-10;//,DINF=63736546543696876837774671.0;
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
bool operator<(pt a, pt p){
	return a.x<p.x-EPS||(abs(a.x-p.x)<=EPS&&a.y<p.y-EPS);
}
struct ln{
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;}
	pt operator^(ln l){ // intersection
		assert(!(*this/l));
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	ln rot90(){
		return ln(p,p+pq.rot90());
	}
	ld pen(){
		return pq.y/pq.x;
	}
};
string cv(pt p){
	return to_string(p.x)+","+to_string(p.y);
}
string cv(ln l){
	return cv(l.p)+" -> "+cv(l.pq);
}
vector<ln>a;
bool can(ln l){
	vector<pair<ld,ll>>in;
	fore(i,0,SZ(a)){
		auto k=a[i];
		if(l/k){
			if(k.p.left(l.p,l.p+l.pq))return 0;
		}
		else in.pb({k.pen(),i});
	}
	/*fore(i,0,SZ(in))fore(j,i+1,SZ(in)){
		ln s=a[in[i].snd],e=a[in[j].snd];
		if(!(s/e)&&(s^e).left(l.p,l.p+l.pq))return 0;
	}
	return 1;*/
	sort(ALL(in));
	fore(i,0,SZ(in)){
		ln s=a[in[i].snd],e=a[in[(i+1)%SZ(in)].snd];
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
	ld s=-1,e=1;
	//cout<<"bs "<<cv(l)<<endl;
	while(can(move(l,s)))s=s+s;
	while(!can(move(l,e)))e=e+e;
	assert(!can(move(l,s)));
	assert(can(move(l,e)));
	while(e-s>=EPS){
		ld m=(s+e)/2;
		if(can(move(l,m)))e=m;
		else s=m;
	}
	can(move(l,s));
	//cout<<"bs "<<cv(l)<<" = "<<s<<" = "<<cv(move(l,s))<<"\n";
	return s;
}
ll steps=0;
void solve(vector<ll>input){
	a.clear();
	ll cnt=0;
	ll n=input[cnt++];
	vector<ld>out0,out1;
	bool did=0;
	ld minx,maxx,miny,maxy;
	ll _n=n;
	while(n--){
		ll ty=input[cnt++];
		pt p,q;
		p.x=input[cnt++],p.y=input[cnt++],q.x=input[cnt++],q.y=input[cnt++];
		ln l(p,q);
		if(ty==0){
			fore(i,0,SZ(a))if(!(a[i]/l)){
				pt p=l^a[i];
				if(!did){
					minx=maxx=p.x;
					miny=maxy=p.y;
				}
				minx=min(minx,p.x);
				miny=min(miny,p.y);
				maxx=max(maxx,p.x);
				maxy=max(maxy,p.y);
				did=1;
			}
			a.pb(l);
		}
		else {
			ll flag=1;
			fore(i,0,SZ(a)-1)flag&=a[i]/a[i+1];
			if(flag){
				out0.pb(0);
			}
			else {
				ln v[4];
				v[0]=l;
				fore(i,1,4)v[i]=v[i-1].rot90();
				ld ans[4];
				fore(i,0,4)ans[i]=bs(v[i]);
				ld res=(ans[0]+ans[2])*(ans[1]+ans[3]);
				out0.pb(res);
			}
			if(!did){
				out1.pb(0);
			}
			else {
				ld resi=(maxx-minx)*(maxy-miny);
				out1.pb(resi);
			}
		}
	}
	ll igual=1;
	fore(i,0,SZ(out0)){
		ld a=out0[i],b=out1[i];
		igual&=abs(a-b)/max((ld)1.0,b)<=1e-4;
	}
	if(!igual){
		cout<<"FAILED!!!!!\n";
		cout<<_n;
		fore(i,1,SZ(input)){
			if(i%5==1)cout<<"\n"<<(input[i]?'?':'+')<<" ";
			else cout<<input[i]<<" ";
		}
		cout<<"\n";
		cout<<"output0:\n";
		imp(out0);
		cout<<"output1:\n";
		imp(out1);
		exit(0);
	}
	cout<<"ok "<<++steps<<"\n";
}
int main(){FIN;
	//cout<<fixed<<setprecision(15);
	ll N,V; srand((long long)&N); cin>>N>>V;
	while(1){
		vector<ll>in;
		ll n=rand()%N+1;
		in.pb(n);
		fore(i,0,n){
			in.pb(rand()%2);
			fore(i,0,4)in.pb(rand()%(2*V+1)-V);
		}
		solve(in);
	}
	return 0;
}
