#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
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

int main(){
	JET
	int t; cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s; cin>>s;
		vector<char> rta;
		rta.pb(s[0]);
		if(n==1 || s[0]==s[1]){
			cout<<s[0]<<s[0]<<"\n";
			continue;
		}
		fore(i,0,n-1){
			if(s[i+1]<=s[i]) rta.pb(s[i+1]);
			else break;
		}
		fore(i,0,SZ(rta)) cout<<rta[i];
		reverse(ALL(rta));
		fore(i,0,SZ(rta))cout<<rta[i];
		cout<<"\n";
	}
	return 0;
}