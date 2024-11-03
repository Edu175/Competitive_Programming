#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b; i<jet;i++)
#define fst first
#define snd second 
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=305;
ll a[MAXN];
int main(){
	JET
	ll n, m; cin>>n>>m;
	ll p[n];
	fore(i,0,n){cin>>p[i]; p[i]--; a[p[i]]++;}
	ll M=0;
	fore(i,0,m) M=max(M,a[i]);
	ll cnt=0;
	while(M<n){
		ll l=0, pos=p[0], q=p[0];
		fore(i,0,m){
			if(!a[i]) continue;
			ll bm=a[i]+1, ba=bm, bq=p[0];
			fore(j,1,n){
				if(p[j]==i) continue;
				if(p[j]==p[j-1]) ba++;
				else ba=a[i]+1;
				if(bm<ba) {bm=ba; q=j;}
			}
			if(bm>l) {l=bm; pos=i; q=bq;}
		}
		ll j=q; q=p[q];
		while(j>=0 && p[j]==q){
			p[j]=pos; j--;
		}
		a[q]-=l-a[pos];
		a[pos]=l;
		M=a[0];
		fore(i,1,m)M=max(M,a[i]);
		cnt++;
	}
	cout<<cnt<<"\n";
	return 0;
}
