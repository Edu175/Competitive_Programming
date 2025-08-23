#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n;
		string s;
		cin>>n>>s;
		ll diff = 0;
		vv a(n);
		fore(i,0,n){
			cin>>a[i];
			if(a[i] != i+1) diff++;
		}
		if(n==2){
			cout<<"Alice\n";
			continue;
		}
		if(n==3){
			string s1 = (s=="Alice") ? "Bob" : "Alice";
			if(a == (vv){1,3,2} || a == (vv){2,1,3} || a == (vv){3,2,1}){
				cout<<s<<"\n";
			}
			else cout<<s1<<"\n";
			continue;
		}
		if(s == "Alice" && diff == 2){
			cout<<"Alice\n";
			continue;
		}
		cout<<"Bob\n";
	}
	return 0;
}