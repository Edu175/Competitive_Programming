#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
ll fn(ll n){return n*(n+1)/2;}
int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string s,t; cin>>s>>t;
		vector<ll> a(n);
		fore(i,0,n)a[i]=s[i]!=t[i];
		ll b=0;
		fore(i,0,n)if(a[i]){
			if(i==n-1||!a[i+1])b++;
		}
		if(!b)cout<<fn(n)<<"\n";
		else if(b==1)cout<<(n-1)*2<<"\n";
		else if(b==2)cout<<"6\n";
		else cout<<"0\n";
	}
	return 0;
}