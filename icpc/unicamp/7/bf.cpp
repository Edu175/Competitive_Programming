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

vector<ll> f(vector<ll>a, vector<ll>p){
	ll n=SZ(a);
	vector<ll>b(n);
	fore(i,0,n)b[p[i]]=a[i];
	return b;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll>p;
	fore(i,0,n)p.pb(i);
	vector<ll>id=p;
	ll res=0;
	do{
		vector<ll>b=id;
		//cout<<p<<": ";
		fore(i,0,4)b=f(b,p);//,cout<<b<<" ";
		vector<ll>q(n);
		fore(i,0,n)q[b[i]]=i;
		if(q==a)res++;//,cout<<p<<"\n";
		//cout<<"\n"<<q<<" "<<(q==a)<<"\n\n";
	}
	while(next_permutation(ALL(p)));
	cout<<res%MOD<<"\n";
	return 0;
}
