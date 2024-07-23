#include <bits/stdc++.h>
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
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	int n,k; cin>>n; cin>>k;
	ll p[n];
	fore(i,0,n){
		cin>>p[i];
	}
	string s;
	cin>>s;
	priority_queue <ll> P;
	P.push(p[0]);
	ll res=0;
	fore(i,1,n){
		if(s[i]==s[i-1]) P.push(p[i]);
		else{
			int aux=k;
			while(!P.empty() && aux--){
				res+=P.top();
				P.pop();
			}
			while(!P.empty()) P.pop();
			P.push(p[i]);
		}
	}
	int aux=k;
	while(!P.empty() && aux--){
		res+=P.top();
		P.pop();
	}
	cout<<res<<"\n";
	return 0;
}