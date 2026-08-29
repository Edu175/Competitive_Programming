#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll n;
ll p[10000];
vv a,b,x;
 
ll res = 0;

void proba(vv a, vv b, vv x){
	set<vv> s;
	while(!s.count(x)){
		s.insert(x);
		fore(i,0,n){
			x[i] = (x[i] * a[i] + b[i])%p[i];
		}
	}
	res = max(res,SZ(s));
}

vv tmp;

void f(){
	if(SZ(tmp)==3*n){
		auto a=vv(tmp.begin(),tmp.begin()+n);
		auto b=vv(tmp.begin()+n,tmp.begin()+2*n);
		auto c=vv(tmp.begin()+2*n,tmp.begin()+3*n);
		proba(a,b,c);
		return;
	}
	ll i=SZ(tmp)%n;
	fore(v,0,p[i]){
		tmp.pb(v);
		f();
		tmp.pop_back();
	}
}

int main(){
	JET
	cin>>n;
	fore(i,0,n){
		cin>>p[i];
	}
	f();
	cout<<res<<"\n";
	
	return 0;
}
