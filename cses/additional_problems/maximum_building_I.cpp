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

vector<ll> fse(vector<ll>a, ll r=0){ //index of first smaller element to the left (-1 if none)
//for bigger change for condition, for right reverse a, then le, and indexes (n-1-x)
	ll n=SZ(a);
	if(r)reverse(ALL(a));
	vector<ll>le(n,-1);
	fore(i,0,n)for(le[i]=i-1;le[i]!=-1&&a[le[i]]>=a[i];le[i]=le[le[i]]);
	if(r){
		reverse(ALL(le));
		for(auto &i:le)i=n-1-i;
	}
	return le;
}

int main(){FIN;
	ll n,m; cin>>n>>m;
	char a[n][m];
	fore(i,0,n)fore(j,0,m)cin>>a[i][j];
	vector<ll>u(m,-1);
	ll res=0;
	fore(i,0,n){
		fore(j,0,m)if(a[i][j]=='*')u[j]=i;
		vector<ll>h(m);
		fore(j,0,m)h[j]=i-u[j];
		vector<ll>l=fse(h),r=fse(h,1);
		fore(j,0,m)res=max(res,h[j]*(r[j]-l[j]-1));
	}
	cout<<res<<"\n";
	return 0;
}
