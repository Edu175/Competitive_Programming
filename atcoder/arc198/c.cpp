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
ll n;
vv a;
vv b;
vector<ii>res;
void op(ll i, ll j){
	assert(i<j);
	res.pb({i,j});
	swap(a[i],a[j]);
	a[i]--,a[j]++;
}
void swL(ll i, ll j, ll k){
	assert(i<j&&j<k);
	op(j,k);
	op(i,k);
	op(j,k);
}
void swR(ll i, ll j, ll k){
	assert(i<j&&j<k);
	op(i,j);
	op(i,k);
	op(i,j);
}
void sw(ll i, ll j){
	if(i==j)return;
	if(i>j)swap(i,j);
	assert(!(i==0&&j==n-1));
	if(i==0)swL(i,j,n-1);
	else swR(0,i,j);
}
void final(){
	assert(a==b);
	cout<<"Yes\n";
	cout<<SZ(res)<<"\n";
	for(auto [i,j]:res)cout<<i+1<<" "<<j+1<<"\n";
}
int main(){FIN;
	cin>>n;
	a=b=vv(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n)cin>>b[i];
	if(accumulate(ALL(a),0ll)!=accumulate(ALL(b),0ll)){
		cout<<"No\n";
		return 0;
	}
	if(n==2){
		if(a==b)final();
		else {
			op(0,1);
			if(a==b)final();
			else cout<<"No\n";
		}
		return 0;
	}
	fore(x,0,n-1){
		ll p=x;
		if(a[x]<b[x]){
			while(a[p]!=b[x]){
				ll cond=p==n-1;
				if(x==0)cond=p==n-2;
				if(cond)sw(x,p),p=x;
				else op(p,p+1),p++;
			}
		}
		else {
			while(a[p]!=b[x]){
				ll to=n-1;
				if(x==0)to=n-2;
				if(p==x)sw(p,to),p=to;
				else op(p-1,p),p--;
			}
		}
		sw(p,x);
	}
	final();
	return 0;
}
