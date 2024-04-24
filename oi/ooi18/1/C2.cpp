#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,rus=b;i<rus;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto sdkjg:v)cout<<sdkjg<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef int ll;
typedef long long LL;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll K=50;

int main(){FIN;
	ll n,h,t; cin>>n>>h>>t;
	vector<ll>a(2*n);
	fore(i,0,n){
		cin>>a[i];
		a[i+n]=a[i];
	}
	map<ll,ll>mp;
	fore(i,0,n)mp[a[i]]=0;
	if(SZ(mp)<=t){
		cout<<"1\n";
		return 0;
	}
	mp.clear();
	ll p=-1;
	ll F[K][n],V[K][n];
	fore(i,0,n){
		while(SZ(mp)<=t)mp[a[++p]]++;
		F[0][i]=p%n;
		V[0][i]=p%n<i;
		mp[a[i]]--;
		if(mp[a[i]]==0)mp.erase(a[i]);
		/*cout<<i<<": "<<F[0][i]<<" "<<V[0][i]<<"\n";
		cout<<p<<"\n";*/
		//imp(st);
	}
	fore(k,1,K)fore(x,0,n){
		F[k][x]=F[k-1][F[k-1][x]];
		V[k][x]=min(V[k-1][x]+V[k-1][F[k-1][x]],h+5);
	}
	LL res=0;
	ll s=0,x=0;
	for(ll k=K-1;k>=0;k--)if(s+V[k][x]<h){
		//if(s==h)break;
		/*cout<<x<<" -> "<<F[k][x]<<"\n";
		cout<<k<<"\n";
		cout<<s<<"+"<<V[k][x]<<"\n\n";*/
		res+=1ll<<k;
		s+=V[k][x];
		x=F[k][x];
	}
	while(s<h){
		s+=V[0][x];
		x=F[0][x];
		res++;
	}
	cout<<res<<"\n";
	return 0;
}
