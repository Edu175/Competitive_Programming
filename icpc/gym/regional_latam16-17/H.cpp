#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
	ll n,k; cin>>n>>k; k++;
	ll res=0;
	vv a(n);
	ll sum=0;
	fore(i,0,n)cin>>a[i],sum+=a[i];
	priority_queue<ll> pq;
	for(ll i=n-1;i>=0;i--){
		pq.push(a[i]);
		if((i+1)%k==0){
			res+=pq.top();
			pq.pop();
		}
	}
	cout<<sum-res<<"\n";
    return 0;
}