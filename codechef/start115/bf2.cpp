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
typedef long long ll;
typedef pair<ll,ll> ii;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}

const ll MOD=1e9+7;

vector<ll>a;
ll n,m,k;
ll res=0;
void greedy(){
	ll to=0,resi=0;
	fore(i,0,n){
		if(to<=a[i])resi++,to=a[i]+k;
	}
	res=(res+resi)%MOD;
	cout<<a<<" "<<resi<<"\n";
}
void f(){
	//imp(a);
	if(SZ(a)==n){
		greedy();
		return;
	}
	fore(j,SZ(a)?a.back()+1:0,m){
		a.pb(j);
		f();
		a.pop_back();
	}
}

int main(){FIN;
	factorials();
	ll t; cin>>t;
	while(t--){
		cin>>n>>m>>k;
		res=0;
		f();
		cout<<res<<endl;
	}
	return 0;
}
