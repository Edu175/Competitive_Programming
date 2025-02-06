#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,k;
	cin>>n>>k;
	vv a(n);
	fore(i,0,n) cin>>a[i];
	ll cnt=0,res=0;
	set<ll> st;
	fore(i,0,n){
		if(cnt<k){
			if(!st.count(a[i])){
				res+=i-cnt++;
			}
			st.insert(a[i]);
		}
	}
	if(cnt<k) cout<<-1<<"\n";
	else cout<<res<<"\n";
	return 0;
}