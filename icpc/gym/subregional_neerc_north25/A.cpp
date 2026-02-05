#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,renison=b;i<renison;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii; 
typedef vector<ll> vv;
const ll MAXV=1e6+5;

typedef bitset<MAXV> mask;

int main(){
	FIN;
	ll n; cin>>n;
	vector<ii> a(n+1);
	vector<char> t(n+1,'.');
	a[0]={0,0}; t[0]='=';
	ll u=0;
	fore(i,1,n+1){
		string s;
		cin>>t[i]>>a[i].fst>>s;
		a[i].snd=s=="async";
		if(t[i]=='=')u=i;
	}
	n++;
	mask cur,ans,mk; cur[0]=1;
	ll sum=0;
	fore(i,0,u)if(t[i]=='+'&&a[i].snd)cur|=cur<<a[i].fst;
	fore(i,u,n)if(t[i]=='+')sum+=a[i].fst;
	if(!a[u].snd)ans|=cur<<(sum+a[u].fst);
	fore(i,u,n){
		if(t[i]=='+'){
			sum-=a[i].fst;
			if(a[i].snd)cur|=cur<<a[i].fst;
		}
		mk|=cur<<sum;
	}
	vv all;
	fore(i,0,n)if(t[i]=='='&&a[i].snd)all.pb(a[i].fst);
	for(auto v:all)ans|=mk<<v;
	ll res=ans.count();
	cout<<res<<"\n";
	return 0;
}