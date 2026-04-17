#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,celu=b;i<celu;i++)
#define SZ(x) ((int)(x).size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto kgjgbrb:v)cout<<kgjgbrb<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll inv(vv a){
	ll n=SZ(a);
	ll res=0;
	fore(i,0,n)fore(j,i+1,n)res+=a[i]>a[j];
	return res;
}
int main(){FIN;
	ll t=1;// cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n); iota(ALL(a),0);
		vv h(n*(n-1)/2+1);
		do{
			h[inv(a)]++;
		}while(next_permutation(ALL(a)));
		imp(h);
	}
	return 0;
}

//codeado desde el celular