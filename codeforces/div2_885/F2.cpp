#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
//O(nlog)
const ll K=20,MAXN=1<<20;

vector<ll> go(ll k,vector<ll>a){ //2**k steps
	vector<ll>ai(SZ(a));
	fore(i,0,SZ(a))ai[i]=a[i]^a[(i+(1<<k))%SZ(a)];
	return ai;
}
bool is(vector<ll>a){
	ll flag=1;
	fore(i,0,SZ(a))if(a[i])flag=0;
	return flag;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll res=0;
	for(ll k=K;k>=0;k--){
		if(!is(go(k,a)))a=go(k,a),res+=1<<k;
	}
	if(!is(a))res++;
	cout<<res<<"\n";
	return 0;
}
