#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	string s; cin>>s;
	ll n; cin>>n;
	vector<string> a(n);
	fore(i,0,n)cin>>a[i];
	ll res=0;
	fore(i,0,n)fore(j,0,n){
		auto t=a[i]+a[j];
		fore(k,0,SZ(s)){
			if(SZ(s)-k>=SZ(t)){
				res+=s.substr(k,SZ(t))==t;
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}
