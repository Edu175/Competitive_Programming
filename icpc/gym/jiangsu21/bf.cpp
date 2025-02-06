#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
    JET
    int t; cin>>t;
    while(t--){
		string s; cin>>s;
		string res=s;
		ll n=SZ(s);
		fore(l,0,n)fore(r,l+1,n+1){
			auto m=s.substr(l,r-l);
			reverse(ALL(m));
			string si=s.substr(0,l)+m+s.substr(r);
			if(si<res){
				res=si;
			}
		}
		cout<<res<<"\n";
    }
    return 0;
}
