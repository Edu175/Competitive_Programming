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

bool check(vector<ll>a){ //sorted a
	vector<ll>b(SZ(a));
	fore(i,0,SZ(a)){
		if(i)b[i]+=a[i-1];
		if(i<SZ(a)-1)b[i]+=a[i+1];
	}
	sort(ALL(b));
	sort(ALL(a));
	//cout<<"check "<<a<<" "<<b<<" "<<(a==b)<<"\n";
	return a==b;
}

vector<ll>a;
ll n,v;
vector<vector<ll>>sol;
void f(ll i){
	if(i==n){
		if(check(a))sol.pb(a);
		return;
	}
	fore(j,-v,v+1)if(j){
		a.pb(j);
		f(i+1);
		a.pop_back();
	}
}

int main(){FIN;
	cin>>n>>v;
	f(0);
	//cout<<"hay "<<SZ(sol)<<"\n";
	for(auto i:sol){
		cout<<i<<"\n";
	}
	return 0;
}
