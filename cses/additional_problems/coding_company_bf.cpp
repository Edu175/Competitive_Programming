#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
const ll MAXN=105;

ll a[MAXN];
ll n,k;
vector<ll>s;
ll res=0;
//vector<vector<ll>>sol;
void calc(){
	vector<ll>c[n];
	fore(i,0,n)c[s[i]].pb(i);
	ll sum=0;
	fore(i,0,n)if(SZ(c[i])){
		if(c[i][0]!=i)return;
		sum+=a[c[i].back()]-a[c[i][0]];
	}
	if(sum<=k)res++;//,sol.pb(s);
}
void f(){
	if(SZ(s)==n){calc();return;}
	fore(j,0,n){
		s.pb(j);
		f();
		s.pop_back();
	}
}

int main(){FIN;
	cin>>n>>k;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	f();
	cout<<res<<"\n";
	//for(auto i:sol)cout<<i<<"\n";
	return 0;
}
