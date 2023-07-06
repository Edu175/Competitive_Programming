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

ll n,V=100;
vector<ll>a;
void f(){
	if(SZ(a)==n){
		ll x=0;
		fore(i,0,n)x+=a[i];
		ll flag=1;
		fore(i,0,n)if(x%a[i]!=0)flag=0;
		if(flag){
			cout<<a<<"\n";
			fore(i,0,n)cout<<x/a[i]<<" ";
			cout<<"\n";
		}
	}
	else{
		fore(i,(SZ(a)==0?1:a.back()+1),V+1){
			a.pb(i);
			f();
			a.pop_back();
		}
	}
}
int main(){//FIN;
	ll t; srand((ll)&t); cin>>t;
	while(t--){
		cin>>n;
		f();
	}
	return 0;
}
