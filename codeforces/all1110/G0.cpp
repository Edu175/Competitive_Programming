#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
mt19937 rng(561);

ll SUMQ=0;
ll n;
vv per;
vv ask(vv a){
	SUMQ+=SZ(a);
	// assert(SUMQ<=30*n);
	cout<<"? "<<SZ(a)<<" ";
	for(auto i:a)cout<<per[i]+1<<" ";
	cout<<endl;
	string ret; cin>>ret;
	if(ret[0]=='-')exit(0);
	vv ans;
	fore(i,0,SZ(a))if(ret[i]=='1')ans.pb(a[i]);
	return ans;
}
vv comp(vv all, vv s){
	set<ll> st(ALL(s));
	vv r;
	for(auto i:all)if(!st.count(i))r.pb(i);
	return r;
}
vector<ii> ed;
void answer(){
	cout<<"!"<<endl;
	for(auto [x,y]:ed)cout<<per[x]+1<<" "<<per[y]+1<<endl;
	ed.clear();
}
vv operator+(vv a, vv b){
	for(auto i:b)a.pb(i);
	return a;
}
void doit(vv a, vv b){ // each i in b has an edge to a
	// a=comp(a,ask(b+a));
	// if(SZ(a)>SZ(b))swap(a,b);
	if(!SZ(a)||!SZ(b))return;
	if(SZ(a)==1){
		for(auto i:b)ed.pb({a[0],i});
		return;
	}
	ll m=SZ(a)/2;
	vv L(a.begin(),a.begin()+m);
	vv R(a.begin()+m,a.end());
	vv bL=comp(b,ask(L+b));
	// vv bR=comp(b,ask(R+b));
	
	// editorial's optimization: bR is initially ~bL
	vv bR=comp(b,bL);
	b=comp(b,bR);
	bR=bR+comp(b,ask(R+b));
	
	doit(L,bL);
	doit(R,bR);
}
void post_doit(vv a, vv b){
	a=comp(a,ask(b+a));
	doit(a,b);
}
int main(){
	// FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		cerr<<"n "<<n<<"\n";
		SUMQ=0;
		if(n==-1)exit(0);
		per=vv(n); iota(ALL(per),0); //shuffle(ALL(per),rng);
		vv v(n); iota(ALL(v),0);
		vector<vv> bags;
		while(SZ(v)){ // 2n-1
			auto r=ask(v);
			bags.pb(r);
			v=comp(v,r);
		}
		assert(SUMQ<=2*n-1);
		fore(i,0,SZ(bags))fore(j,i+1,SZ(bags))post_doit(bags[i],bags[j]);
		cerr<<"depth "<<SZ(bags)<<"\n";
		answer();
		// cerr<<"sum of queries "<<SUMQ<<"\n";
	}
	return 0;
}
