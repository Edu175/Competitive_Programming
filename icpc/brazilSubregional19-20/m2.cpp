#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

vi a;
int m;

bool can (ll x){
	int k=1;
	int acc=0;
	fore(i,0,SZ(a)){
		
		if (a[i]>x) return false;
		if(acc+a[i]>x){
			acc=0;
			k++;	
		}
		acc+=a[i];
	}
	return (k<=m);
}

ll tec (ll a,ll b){
	if(a%b==0) return a/b;
	else{
		return a/b+1;
	}
}


int main(){
	FIN
	int n,k;
	cin>>n>>m>>k;
	ll sum=0;
	fore(i,0,n){
		int x;
		cin>>x;
		a.pb(x);
		sum+=x;
	}	
	ll l=0;
	ll r=sum;
	while(l<=r){
		ll m=(l+r)/2;
		if(can(m))r=m-1;
		else l=m+1;
	}
	r-=3;
	while(!can(r)){
		r++;
	}
	//cout<<r;
	cout<<tec(r,k)<<"\n";
	return 0;
} 