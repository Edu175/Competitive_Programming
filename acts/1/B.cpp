#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,acts=b;i<acts;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdf:v)cout<<sdf<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=5e5+5;
string ft[MAXN+1];
void upd(int i0, string v){
	for(int i=i0+1;i<=MAXN;i+=i&-i)ft[i]=min(ft[i],v);
}
string get(int i){
	string res="~";
	for(;i>0;i-=i&-i)res=min(res,ft[i]);
	return res;
}
int main(){FIN;
	ll n,k; cin>>k>>n;
	fore(i,0,MAXN+1)ft[i]="~";
	bool b[k][k];
	fore(i,0,k)fore(j,0,k){
		char c; cin>>c;
		b[i][j]=(c=='1');
	}
	string a; cin>>a;
	vector<int>to(n);
	for(int i=n-1;i>=0;i--){
		for(to[i]=i+1;to[i]!=n&&b[a[i]-'a'][a[to[i]]-'a'];to[i]=to[to[i]]);
	}
	imp(to);
	//vector<string> dp(n+5,"$");
	//cout<<min(string("aaa"),string("aa"))<<"\n";
	upd(n,"");
	string res;
	for(int i=n-1;i>=0;i--){
		//auto &res=dp[i];
		res=get(to[i]+1);
		//fore(j,i+1,to[i]+1)res=min(res,dp[j]);
		res=string(1,a[i])+res;
		upd(i,res);
		cerr<<i<<": "<<res<<"\n";
		cerr<<SZ(res)<<"\n\n";
	}
	cout<<res<<"\n";
	return 0;
}
