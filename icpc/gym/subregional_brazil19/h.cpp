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

ll tec (ll a,ll b){
	if(a%b==0) return a/b;
	else{
		return a/b+1;
	}
}

int main(){
	FIN
	ll n,k; cin>>n>>k;
	fore(i,1,10){
		ll rta=(n*k)*(i*10);
		rta=tec(rta,100);
		//cout<<(n*k)/100;
		cout<<(int) rta<<" ";
	}
	cout<<"\n";
	return 0;
} 