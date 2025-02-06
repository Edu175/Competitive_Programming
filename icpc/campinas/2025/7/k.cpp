#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,k; cin>>n>>k;
	ll a[n];
	ll s=0,M=0;
	fore(i,0,n) {cin>>a[i];M=max(a[i],M);s+=a[i];}
	s-=M;
	queue <int> q;
	fore(i,2,n) q.push(a[i]);
	ii ahor={a[0],a[1]};
	if(ahor.fst>ahor.snd) swap(ahor.fst,ahor.snd);
	ll res=0;
	while(k&&ahor.snd!=M){
		res+=ahor.fst;
		q.push(ahor.fst);
		ahor.fst=q.front();
		if(ahor.fst>ahor.snd) swap(ahor.fst,ahor.snd);
		q.pop();
		k--;
	}
	while(k%(n-1)!=0){
		res+=ahor.fst;
		q.push(ahor.fst);
		ahor.fst=q.front();
		if(ahor.fst>ahor.snd) swap(ahor.fst,ahor.snd);
		q.pop();
		k--;
	}
	res+=(k/(n-1))*s;
	cout<<res<<"\n";
	return 0;
}