#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,omi=b;i<omi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dfgdfh:v)cout<<dfgdfh<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<int> El_Robot_Shor(int n, int q, vector<int> a,
vector<int> u, vector<int> v) {
	vector<int>res(q+1);
	auto count=[&](){
		vector<ll>vis(n);
		ll res=0;
		fore(x,0,n)if(!vis[x]){
			res++;
			for(auto y=x;!vis[y];y=a[y])vis[y]=1;
		}
		return res;
	};
	ll c=count();
	res[0]=(n-c)&1?-1:(n-c)/2;
	fore(i,1,q+1){
		if(u[i-1]!=v[i-1]){
			swap(a[u[i-1]],a[v[i-1]]);
			if(n<=2005)c=count();
			else c--;
		}
		res[i]=(n-c)&1?-1:(n-c)/2;
	}
	// imp(res);
	/*for(auto &i:res){
		if(n>2005&&i!=-1)
	}*/
	return res;
}