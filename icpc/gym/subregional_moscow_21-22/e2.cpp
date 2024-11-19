#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vector<ii>dat={
	
{12, 48},
{15, 5055},
{18, 288},
{21, 7077},
{24, 8088},
{27, 3699},
{36, 48888},
{45, 5055555555},
{54, 222888888},
{63, 111888},
{72, 8088888888},
{81, 9099999999}
	
};

int main(){
	JET
	ll q; cin>>q;
	while(q--){
		ll n; cin>>n;
		set<ll>st;
		ll x=n;
		while(x)st.insert(x%10),x/=10;
		if(SZ(st)==1)cout<<n<<"\n";
		else {
			ll res=-1;
			for(auto [i,j]:dat)if(i==n)res=j;
			cout<<res<<"\n";
		}
	}
}