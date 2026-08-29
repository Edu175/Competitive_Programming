#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for (auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

void preguntar(vv &a){
	cout<<"? "<<SZ(a)<<" ";
	for(auto x:a) cout<<x<<" ";
	cout<<endl;
}

vv un(vv a, vv b){
	for(auto x:b) a.pb(x);
	return a;
}

void responder(int x, int y){
	cout<<"! "<<x<<endl;
	string res; cin>>res;
	if(res == ":("){
		cout<<"! "<<y<<endl;
		cin>>res; 
	}
}

void tres(vv &tot){
	ll a = tot[0], b = tot[1], c = tot[2];
	cout<<"? "<<2<<" "<<a<<" "<<b<<endl;
	string s; cin>>s;
	if(s == "YES"){
		cout<<"? "<<1<<" "<<c<<endl;
		cin>>s;
		if(s == "NO")responder(a,b);
		else{
			cout<<"? "<<1<<" "<<a<<endl;
			cin>>s;
			if(s == "YES")responder(a,c);
			else responder(b,c);
		}
	}
	else{
		cout<<"? "<<1<<" "<<a<<endl;
		cin>>s;
		if(s == "NO")responder(b,c);
		else responder(a,c);
	}
}

pair<vv,vv> split(vv v){
	ll sz = SZ(tot)/2;
	vv a,b;
	fore(i,0,sz) a.pb(v[i]);
	fore(i,sz,SZ(v)) b.pb(v[i]);
}

int main(){
	// JET
	ll n; cin>>n;
	vv tot(n);
	fore(i,1,n+1) tot[i-1] = i; 
	while(SZ(tot)>3){
		vv C, CC;
		fore(i,0,(SZ(tot)+1)/2) C.pb(tot[i]);
		fore(i,(SZ(tot)+1)/2,SZ(tot)) CC.pb(tot[i]);
		preguntar(C);
		string s; cin>>s;
		if(s == "YES"){
			auto [a,b] = split(CC);
			preguntar(a);
			cin>>s;
			if(s == "YES"){
				auto [c,d] = split(C);
				preguntar(c);
				cin>>s;
				if(s == "YES")tot = un(c,a);
				else tot = un(d,a);
			}
			else tot = un(b,C);
		}	
		else{
			auto [a,b] = split(C);
			preguntar(a);
			cin>>s;
			if(s == "YES"){
				auto [c,d] = split(CC);
				preguntar(c);
				cin>>s;
				if(s == "YES")tot = un(c,a);
				else tot = un(d,a);
			}
			else tot = un(b,C);
		}
	}	
	assert(SZ(tot));
	if(SZ(tot) == 3){
		tres(tot);
		return 0;
	}
	responder(tot[0],tot[1]);
	return 0;
}