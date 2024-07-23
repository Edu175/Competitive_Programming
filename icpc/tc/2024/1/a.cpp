#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto slkdf:v)cout<<slkdf<<" ";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		ll res=0,no;
		fore(l,0,n){
			stack<ii>st;
			fore(r,l,n){
				ll mx=a[r];
				while(SZ(st)&&
				(st.top().fst>a[r]||!(st.top().snd<=a[r])))
					mx=max(mx,st.top().snd),st.pop();
				st.push({a[r],mx});
				ll resi=r+1-l-SZ(st);
				no+=SZ(st);
				cout<<l<<","<<r<<": "; 
				// fore(i,l,r+1)cout<<a[i]<<" ";;cout<<"| ";
				
				auto _st=st;
				vector<ll>tmp;
				while(SZ(_st))tmp.pb(_st.top().fst),_st.pop();
				reverse(ALL(tmp));
				imp(tmp);
				cout<<" = "<<resi<<"\n";
				res+=resi;
			}
		}
		cout<<no<<" ";
		cout<<res<<"\n\n\n";
	}
}