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
	string s; cin>>s;
	int k; cin>>k;
	multiset<char> a[k];
	fore(i,0,SZ(s)){
		a[i%k].insert(s[i]);
	}
	fore(i,0,SZ(s)){
		cout<<*a[i%k].begin();
		a[i%k].erase(a[i%k].begin());
	}
	cout<<"\n";
	return 0;
}