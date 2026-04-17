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

const int maxn=1e6+6;
int a[maxn];

ll sd (ll x){
	ll rta=0;
	while(x>0){
		rta+=x%10;
		x/=10;
	}
	return rta;
}

int main(){
	JET
	
	ll n,k; cin>>n>>k;
	priority_queue<ll> pq;
	fore(i,0,n){
		int x; cin>>x;
		if(a[x]==0){
			pq.push(x);
		}
		a[x]++;
	}
	ll cnt=0;
	ll rta=0;
	while(true && !pq.empty()){
		int x=pq.top();
		int c=a[x];
		pq.pop();
		if(x==0) break;
		if(k<=cnt+c){
			rta=sd(x);
			break;
		}
		ll y=x-sd(x);
		if(a[y]==0){
			pq.push(y);
		}
		a[y]+=c;
		cnt+=c;
	}
	cout<<rta<<"\n";
	return 0;
}