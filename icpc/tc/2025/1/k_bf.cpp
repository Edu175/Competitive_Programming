#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
vv x,y;

ll d(ll i, ll j){
	return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
ll n;
vv a;
ll res=0;
void f(){
	if(SZ(a)==n){
		ll good=1;
		fore(i,0,n)fore(j,0,n)if(i!=j)fore(k,0,n)if(i!=k&&j!=k){
			if(a[i]==a[j]){
				if(a[k]==a[i]){
					good&=d(i,j)==d(i,k)&&d(i,j)==d(j,k);
				}
				else {
					good&=d(i,j)<d(i,k)&&d(i,j)<d(j,k);
				}
			}
		}
		if(good){
			res++;
			// fore(i,0,n)cout<<a[i]<<" ";;cout<<"good\n";
		}
		return;
	}
	fore(i,1,n+1){
		a.pb(i);
		f();
		a.pop_back();
	}
}

int main(){
	JET
	cin>>n;
	x.resize(n);
	y.resize(n);
	fore(i,0,n)cin>>x[i]>>y[i];
	f();
	cout<<res<<"\n";
	return 0;
}