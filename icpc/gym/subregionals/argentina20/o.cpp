#include<bits/stdc++.h> 
#define fore(i,a,b) for(ll i=a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef pair<ld,ld> dd;
const ld pi=acos(-1), tau=2*pi;
const ld EPS=1e-7;

ld cut(ld a){ // range [0,tau)
	while(a<-EPS)a+=tau;
	while(a>=tau-EPS)a-=tau;
	return a;
}
ld dis(ld a, ld b){
	ld c=cut(a-b);
	if(c<=pi+EPS)return c;
	return tau-c;
}
ll sq(ll a){return a*a;}
ll norm2(ii a){return sq(a.fst)+sq(a.snd);}
ld norm(ii a){return sqrt(norm2(a));}
dd operator-(dd a, dd b){return {a.fst-b.fst,a.snd-b.snd};}
dd operator+(dd a, dd b){return {a.fst+b.fst,a.snd+b.snd};}

dd cer={0,0};

int main(){
	JET
	ll n; cin>>n;
	vector<ii> a(n);
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	
	vector<pair<ld,pair<ld,ld>>> ev;
	auto agr=[&](ld alp, pair<ld,ld> val){ev.pb({cut(alp),val});};
	fore(i,0,8)agr(i*tau/8,cer);
	// now there exists a point "in" for any o
	// and a point "out" for any o
	
	fore(i,0,n){
		auto [x,y]=a[(i+1)%n]-a[i];
		ld alp=atan2(y,x),t=norm({x,y});
		alp=cut(-alp); // a donde esta el sol
		dd coef={t*cos(alp),t*sin(alp)};
		agr(alp-pi/2,cer); // query point
		agr(alp+pi/2,cer); // query point
		agr(alp,coef); // upd point
		// cerr<<i<<": "<<alp<<" "<<t<<"\n";
	}
	sort(ALL(ev));
	ll m=SZ(ev);
	
	auto in=[&](ld o, ld b){return dis(o,b)<pi/2-EPS;};
	ll did=0,l=-1;
	fore(i,0,m){
		ll now=in(0,ev[i].fst);
		// cerr<<i<<": "<<now<<"\n";
		did|=!now;
		if(did&&now){l=i;break;}
	}
	assert(l!=-1);
	
	// for(auto [a,par]:ev){
	// 	auto [fst,snd]=par;
	// 	cout<<a<<",("<<fst<<","<<snd<<") ";
	// }
	// cout<<"\n";
	auto av=[&](ll &p){p=(p+1)%m;};
	dd sum=cer;
	fore(i,l,m)sum=sum+ev[i].snd;
	ll r=0;
	ld res=0; ll hay=0;
	fore(i,0,m){
		ld o=ev[i].fst;
		while(!in(o,ev[l].fst))sum=sum-ev[l].snd,av(l);
		while( in(o,ev[r].fst))sum=sum+ev[r].snd,av(r);
		ld cur=cos(o)*sum.fst+sin(o)*sum.snd;
		// cout<<i<<" "<<o<<": "<<l<<","<<r<<": "<<sum.fst<<","<<sum.snd<<": "<<cos(o)<<","<<sin(o)<<": ";
		// cout<<cur<<"\n";
		ld cur2=0;
		fore(j,l,r){
			ld del=ev[j].fst,t=ev[j].snd.fst/cos(del);
			ld term=t*(cos(o-del));
			// cerr<<j<<": "<<del<<" "<<t<<": "<<term<<"\n";
			// cerr<<t*(sin(o)*cos(del)+sin(o)*cos(del))
			cur2+=term;
		}
		// cout<<"= "<<cur2<<"\n\n";
		if(!hay||cur<res)res=cur,hay=1;
	}
	cout<<fixed<<setprecision(2)<<abs(res)<<"\n";
	return 0;
}