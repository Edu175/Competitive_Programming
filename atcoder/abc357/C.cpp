#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;


vector<string> f(ll n){
	if(n==0)return {"#"};
	auto b=f(n-1);
	ll m=SZ(b);
	vector<string> res(3*m,string(SZ(b[0])*3,'.'));
	fore(i,0,m)fore(j,0,m)fore(k,0,3)fore(l,0,3)if(!(k==1&&l==1)){
		res[m*k+i][m*l+j]=b[i][j];
	}
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	auto r=f(n);
	for(auto i:r)cout<<i<<"\n";
	return 0;
}
