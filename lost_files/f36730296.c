#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto jdfg:v)cout<<jdfg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,INF=1.5e9;

ll debug=1;

struct pt{
	ll x, y;
	pt(){}
	pt(ll x, ll y):x(x),y(y){}
};
pt a[MAXN];
ll n;
ll d;
pt p;
vector<ll> D={0};
vector<pt> P={pt(0,0)};
vector<pt>res;

ll bet(pt a, pt b, ll d){ // a es mejor a b en direccion d?
	if(d==0)return a.x>b.x;
	if(d==1)return a.y>b.y;
	if(d==2)return a.x<b.x;
	if(d==3)return a.y<b.y;
	return 0;
}

void go(pt b){
	if(d%2==0)res.pb(pt(b.x,p.y));
	else res.pb(pt(p.x,b.y));
	if(bet(b,p,(d+1)%4))d=(d+1)&3;
	else d=(d-1)&3;
	p=b;
	P.pb(p); D.pb(d);
}
void put(pt b){ //exactly to b
	res.pb(b);
	p=b;
	P.pb(p);
}
void dir(pt b){
	if(bet(b,p,(d+1)%4))d=(d+1)&3;
	else d=(d-1)&3;
	D.pb(d);
}
vector<pt> ex[4];
ll mx[4];
set<ii>cx,cy;
void calc(){
	if(!SZ(cx)||!SZ(cy))return;
	mx[0]=prev(cx.end())->snd;
	mx[1]=prev(cy.end())->snd;
	mx[2]=cx.begin()->snd;
	mx[3]=cy.begin()->snd;
}
void saco(ll i){
	cx.erase({a[i].x,i});
	cy.erase({a[i].y,i});
	calc();
}
void extremo(pt b, ll d0, ll d1){
	cout<<d0<<" "<<d1<<": ";
	if(d1!=((d0+1)&3)&&d1!=((d0-1)&3))swap(d0,d1);
	cout<<d0<<"\n";
	ex[d0].pb(b);
}
bool comp0(pt a, pt b){return a.x>b.x&&a.y>b.y;}
bool comp1(pt a, pt b){return a.x<b.x&&a.y>b.y;}
bool comp2(pt a, pt b){return a.x<b.x&&a.y<b.y;}
bool comp3(pt a, pt b){return a.x>b.x&&a.y<b.y;}
int main(){FIN;
	cin>>n;
	fore(i,0,n){
		cin>>a[i].x>>a[i].y;
	}
	fore(i,0,n)cx.insert({a[i].x,i}),cy.insert({a[i].y,i});
	calc();
	while(SZ(cx)){
		// caso 1
		
		ll j=mx[d];
		cout<<p.x<<","<<p.y<<" "<<d<<": ";
		for(auto i:mx)cout<<a[i].x<<","<<a[i].y<<"("<<i<<") ";
		if(bet(p,a[j],d)){
			if(debug){
				cout<<"\nex: "<<p.x<<","<<p.y<<"\n";
			}
			extremo(p,D[SZ(D)-2],D[SZ(D)-1]);
			P.pop_back(),D.pop_back(),res.pop_back();
			p=P.back(),d=D.back();
		}
		else {
			if(debug)cout<<"\ngo ("<<j<<"): "<<a[j].x<<","<<a[j].y<<"\n";
			go(a[j]);
			saco(j);
		}
		if(debug)cout<<res.back().x<<","<<res.back().y<<"\n\n";
	}
	fore(i,0,4){
		cout<<i<<": ";
		for(auto j:ex[i])cout<<j.x<<","<<j.y<<" ";
		cout<<"\n";
	}
	sort(ALL(ex[0]),comp0);
	sort(ALL(ex[1]),comp1);
	sort(ALL(ex[2]),comp2);
	sort(ALL(ex[3]),comp3);
	fore(i,2,4){
		reverse(ALL(ex[i]));
		for(auto j:ex[i])ex[i-2].pb(j);
		ex[i].clear();
	}
	fore(i,0,4){
		cout<<i<<": ";
		for(auto j:ex[i])cout<<j.x<<","<<j.y<<" ";
		cout<<"\n";
	}
	// 0
	if(SZ(ex[0])){
		if(d==0){
			put(pt(INF,p.y));
			dir(ex[0][0]);
			for(auto j:ex[0])go(j);
		}
		else if(d==1){
			put(pt(p.x,INF));
			dir(ex[0][0]);
			for(auto j:ex[0])go(j);
		}
		else if(d==2){
			put(pt(-INF,p.y));
			reverse(ALL(ex[0]));
			dir(ex[0][0]);
			for(auto j:ex[0])go(j);
		}
		else if(d==3){
			put(pt(p.x,-INF));
			reverse(ALL(ex[0]));
			dir(ex[0][0]);
			for(auto j:ex[0])go(j);
		}
	}
	//1
	if(SZ(ex[1])){
		if(d==0){
			put(pt(INF,p.y));
			reverse(ALL(ex[1]));
			dir(ex[1][0]);
			for(auto j:ex[1])go(j);
		}
		else if(d==1){
			put(pt(p.x,INF));
			dir(ex[1][0]);
			for(auto j:ex[1])go(j);
		}
		else if(d==2){
			put(pt(-INF,p.y));
			dir(ex[1][0]);
			for(auto j:ex[1])go(j);
		}
		else if(d==3){
			put(pt(p.x,-INF));
			reverse(ALL(ex[1]));
			dir(ex[1][0]);
			for(auto j:ex[1])go(j);
		}
	}
	//last
	if(d==0){
		put(pt(INF,p.y));
	}
	else if(d==1){
		put(pt(p.x,INF));
	}
	else if(d==2){
		put(pt(-INF,p.y));
	}
	else if(d==3){
		put(pt(p.x,-INF));
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.x<<" "<<i.y<<"\n";
}

