#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv a;
void app(ll p, char c){
	assert(p+1<SZ(a));
	vv b;
	fore(i,0,p)b.pb(a[i]);
	ll x=a[p],y=a[p+1];
	ll v=(c=='+'?x+y:x*y)&1;
	b.pb(v);
	fore(i,p+2,SZ(a))b.pb(a[i]);
	a=b;
	// imp(a)
}
void app(pair<ll,char>a){app(a.fst,a.snd);}

ll hay(ll t){ // ultimo par de t's consecutivos
	ll n=SZ(a);
	ll p=-1;
	fore(i,0,n){
		if(i+1<n&&a[i]==t&&a[i+1]==t)p=i; // ultimo par de 1s
	}
	return p;
}

pair<ll,char> get(ll t){ // busca par o impar
	ll n=SZ(a);
	assert(n>1);
	if(!t){ // busco 1 1 o 1
		ll p=hay(1),q=find(ALL(a),1)-a.begin();
		if(p!=-1)return {p,'+'};
		if(q<n){
			if(q==n-1)q--;
			 // 1 0 o 0 1
			return {q,'*'};
		}
		// todos 0s
		return {0,'+'};
	}
	
	ll p=hay(0);
	if(p!=-1)return {p,'+'};
	
	vector<ii> bs; // (cant, ult pos)
	ll q=0;
	fore(i,0,n){
		q++;
		if(i==n-1||a[i]!=a[i+1]){
			bs.pb({q,i});
			q=0;
		}
	}
	if(SZ(bs)==1){
		// todos 1s
		return {0,'*'};
	}
	p=-1; q=-1;
	fore(i,0,SZ(bs))if(!a[bs[i].snd]){
		q=bs[i].snd;
		ll izq=(i&&bs[i-1].fst%2);
		ll der=(i+1<SZ(bs)&&bs[i+1].fst%2);
		
		if(!izq||!der)p=q;
	}
	ll pos=p;
	if(pos==-1)pos=q;
	assert(pos!=-1);
	if(pos==n-1)pos--;
	assert(a[pos]^a[pos+1]);
	return {pos,'+'};
}

ll who(ll t){
	vv _a=a;
	
	// empieza el que busca t
	while(SZ(a)>1){
		auto p=get(t);
		app(p);
		t^=1;
	}
	ll win=a[0];
	a=_a;
	return win;
}

pair<ll,char> leer(){
	ll p; char c; cin>>p>>c;
	p--;
	if(p==-1)exit(0);
	return {p,c};
}

void escr(pair<ll,char> a){
	cout<<a.fst+1<<" "<<a.snd<<endl;
}

int main(){FIN;
	ll n,t; cin>>n>>t;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	ll p=who(t);
	
	ll j=p^t;
	if(j){
		cout<<"Bob"<<endl;
		app(leer());
	}
	else cout<<"Alice"<<endl;
	
	while(SZ(a)>1){
		auto par=get(p);
		app(par);
		escr(par);
		if(SZ(a)>1)app(leer());
	}
	assert(a[0]==p);
	return 0;
}
