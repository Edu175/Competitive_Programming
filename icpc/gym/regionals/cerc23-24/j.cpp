#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto kgjgbrb:v)cout<<kgjgbrb<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<vv> a;
vv cap;
ll n,k;
void state(){
	fore(i,0,k){
		fore(j,0,cap[i]){
			if(j<SZ(a[i]))cout<<a[i][j];
			else cout<<"-";
		}
		cout<<"\n";
	}
	cout<<endl;
}
vector<ii>res;
void go(ll i, ll j){
	if(i==j)return;
	assert(SZ(a[i]));
	a[j].pb(a[i].back());
	assert(SZ(a[j])<=cap[j]);
	a[i].pop_back();
	res.pb({i,j});
	
	// cout<<i<<" --> "<<j<<":\n";
	// state();
	
}
ll mx=0;
// invariant mx vacio
void go_top(ll i, ll k){ // kesima from top
	ll aux=0;
	while(aux==i||aux==mx)aux++;
	if(SZ(a[aux]))go(aux,mx);	
	fore(_,0,k)go(i,mx);
	go(i,aux);
	fore(_,0,k)go(mx,i);
	go(aux,i);
	if(SZ(a[mx]))go(mx,aux);
}
void go_down(ll i, ll k){ // go to be kesima from top
	ll aux=0;
	while(aux==i||aux==mx)aux++;
	if(SZ(a[aux]))go(aux,mx);
	go(i,aux);
	fore(_,0,k)go(i,mx);
	go(aux,i);
	fore(_,0,k)go(mx,i);
	if(SZ(a[mx]))go(mx,aux);
}
void swapea(ll i, ll j){ // swaps tops
	go(i,mx);
	go(j,i);
	go(mx,j);
}
void swapea(ll i, ll j, ll k, ll l){ // nashe
	go_top(i,k);
	go_top(j,l);
	swapea(i,j);
	go_down(i,k);
	go_down(j,l);
}
void ir(ll i, ll j, ll r, ll c){ // de i,j a r,c
	// cout<<"ir "<<i<<","<<j<<" --> "<<r<<","<<c<<"\n";
	if(i==r&&j==c)return;
	if(i==r){
		go_top(i,j);
		go_down(i,c);
	}
	else {
		swapea(i,r,j,c);
	}
}
int main(){FIN;
	cin>>n>>k;
	fore(i,0,k){
		ll m; cin>>m;
		cap.pb(m);
		vv v(m);
		fore(i,0,m)cin>>v[i],v[i]--;
		while(SZ(v)&&v.back()==-1)v.pop_back();
		a.pb(v);
		if(m>cap[mx])mx=i;
	}
	// state();
	// acum at start except max
	ll p=0;
	auto mv=[&](){
		while(p<k&&(p==mx||SZ(a[p])==cap[p]))p++;
	};
	mv();
	auto vacia=[&](ll i){
		while(p<k&&p!=i&&SZ(a[i])){
			go(i,p);
			mv();
		}
	};
	vacia(mx);
	for(ll i=k-1;i>=0;i--){
		if(p<i)vacia(i);
	}
	
	// cout<<"acomodado\n";
	// state();
	
	vector<ii>pos(n); // from top
	ll idx=0;
	fore(i,0,k)if(i!=mx){
		fore(j,0,cap[i])if(idx<n)pos[idx++]={i,j};
	}
	fore(x,0,n){
		auto &[i,j]=pos[x];
		if(i<mx)j=SZ(a[i])-1-j;
		// cout<<"pos "<<x<<": "<<i<<","<<j<<"\n";
	}
	fore(x,0,n){
		ll i=-1,j=-1;
		fore(r,0,k)fore(c,0,SZ(a[r])){
			if(a[r][c]==x)i=r,j=SZ(a[r])-1-c;
		}
		assert(i!=-1);
		ir(i,j,pos[x].fst,pos[x].snd);
		
		// cout<<"puse "<<x<<" en "<<pos[x].fst<<","<<pos[x].snd<<":\n";
		// state();
	}
	
	// cout<<"\nordenado sin max\n\n";
	// state();
	
	p=mx;
	fore(i,mx+1,k){
		while(SZ(a[i])){
			while(SZ(a[p])==cap[p])p++;
			go(i,p);
		}
	}
	for(auto [i,j]:res){
		cout<<i+1<<" "<<j+1<<"\n";
	}
	cout<<"0 0\n";
	// state();
	return 0;
}