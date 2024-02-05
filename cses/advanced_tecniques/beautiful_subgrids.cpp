#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=3000;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bitset<MAXN> bt[MAXN];

int main(){FIN;
	int n; cin>>n;
	fore(i,0,n){
		string s; cin>>s;
		fore(j,0,n)bt[i][j]=s[j]-'0';
	}
	ll res=0;
	fore(i,0,n)fore(j,i+1,n){
		int c=(bt[i]&bt[j]).count();
		res+=c*(c-1)/2;
	}
	cout<<res<<"\n";
	return 0;
}
