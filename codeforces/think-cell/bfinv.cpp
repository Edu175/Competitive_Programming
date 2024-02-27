#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<"\n";
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}
const ll MAXN=1e3+5;
set<vector<ll>>st[MAXN][MAXN];
ll n;
void f(ll k, ll m){
	if(m%(2*k))return;
	vector<ll>ko(m,0);
	fore(i,0,n-m)ko.pb(1);
	do{
		ll s=0,fl=0;
		fore(i,0,n){
			s+=!ko[i];
			fl|=ko[i]==1&&s>=k&&m-s>=k;
		}
		//imp(ko);
		//cout<<fl<<endl;
		if(!fl)continue;
		vector<ll>a;
		fore(i,0,n)if(ko[i])a.pb(i);
		st[k][m].insert(a);
	}
	while(next_permutation(ALL(ko)));
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll>a;
		fore(i,0,n)a.pb(i);
		cout<<"n "<<n<<":\n";
		fore(k,1,(n-1)/2+1){
			cout<<"\nk "<<k<<":\n";
			fore(m,0,n+1){
				f(k,m);
			}
			ll sum=1;
			fore(m,0,n+5)if(SZ(st[k][m])){
				cout<<"m "<<m<<":\n";
				for(auto v:st[k][m]){
					cout<<v<<" ";
					fore(_,0,n-SZ(v))cout<<"  ";
					string s(n,'0');
					fore(i,0,SZ(v))s[v[i]]='1';
					cout<<s<<"\n";
				}
				cout<<"size "<<SZ(st[k][m])<<"\n";
				sum+=SZ(st[k][m]);
			}
			cout<<"sum "<<sum<<"\n";
		}
		cout<<"\n\n";
	}
	return 0;
}
