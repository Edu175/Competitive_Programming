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
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
vv all={1};

ll num=0;
ll k;
void f(ll i){
	if(i==2*k+1){all.pb(num);return;}
	ll s=(i?num%10:1),e=9;
	if(i==k)s++,e++;
	if(i>k){
		s=1,e=num%10+1;
	}
	if(i==k+1)e--;
	fore(v,s,e){
		num=num*10+v;
		f(i+1);
		num/=10;
	}
}
random_device rd;
mt19937 rng(rd());

int main(){FIN;
	fore(ki,0,9){
		k=ki;
		f(0);
	}
	// cout<<SZ(all)<<"\n";
	// ll random=0;
	// fore(i,0,95){
	// 	ll l=0,r=1e18,m=rng()%10+1;
	// 	ll res=0;
	// 	for(auto v:all)res+=(l<=v&&v<r&&v%m==0);
	// 	cout<<l<<" "<<r<<" "<<m<<": ";
	// 	cout<<res<<endl;
	// }
	// return 0;
	ll ljgfjfdg; cin>>ljgfjfdg;
	fore(ldjg,0,ljgfjfdg){
		cout<<"Case #"<<ldjg+1<<": ";
		ll l,r,m; cin>>l>>r>>m; r++;
		ll res=0;
		// cout<<"\n";
		for(auto v:all){
			res+=(l<=v&&v<r&&v%m==0);
			// if(l<=v&&v<r&&v%m==0)cout<<v<<"\n";
		}
		// cout<<"= ";
		cout<<res<<"\n";
	}
	return 0;
}
