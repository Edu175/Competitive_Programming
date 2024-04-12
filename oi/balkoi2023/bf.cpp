#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,balkoi=b;i<balkoi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdkj:v)cout<<sdkj<<" ";cout<<endl
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
void operator+=(vector<ll>&a, vector<ll>b){
	for(auto i:b)a.pb(i);
}
int main(){FIN;
	ll n; cin>>n;
	vector<ll>p(n,-1);
	fore(i,1,n){
		cin>>p[i];
	}
	vector<ll>car(n);
	fore(i,0,n)cin>>car[i];
	
	vector<vector<ll>> h(n);
	fore(i,0,n)if(car[i])h[i]={i};
	vector<ll>res(n+5,-1);
	fore(_,0,n){
		for(auto i:h[0])res[i]=_;
		h[0].clear();
		vector<vector<ll>> hi(n);
		//cout<<_<<":\n";
		fore(i,1,n){
			//imp(h[i]);
			if(SZ(h[i])==1)hi[p[i]]+=h[i];
		}
		h=hi;
	}
	fore(i,0,n){
		cout<<res[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
