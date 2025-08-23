#include<bits/stdc++.h>
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
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll u=0,d=0;
		fore(i,0,n){
			char c; ll x; cin>>c>>x;
			u+=x*(ll(c=='N')-ll(c=='S'));
			d+=x*(ll(c=='E')-ll(c=='W'));
		}
		cout<<ll(!!u)+ll(!!d)+ll(u*d!=0)+7*(ll(!!u)+(ll(!!d)+ll(u*d!=0))==0)<<" ";
		cout<<(u<0?'S':(u>0?'N':(d>0?'E':'W')))<<"\n";
		if(ll(!!u)+(ll(!!d)+ll(u*d!=0))==0){
			fore(i,0,3)cout<<"Z 1\nL\n";
			cout<<"Z 1\n";
		}
		if(u){
			cout<<"Z "<<abs(u)<<"\n";
			if(d){
				cout<<(u*d>0?'R':'L')<<"\n";
				cout<<"Z "<<abs(d)<<"\n";
			}
		}
		else if(d){
			cout<<"Z "<<abs(d)<<"\n";

		}
	}
	return 0;
}