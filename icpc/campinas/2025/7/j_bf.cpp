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

int n;
const int maxn=2e5;
int a[maxn];



int solve(){
	set<ii> s;
	fore(i,0,n) s.insert({a[i],i});
	vv salvan;
	while(SZ(s)){
		auto x = *(s.begin());
		while()
	}
}

int main(){
	int n,q; cin>>n>>q;
	fore(i,0,n) cin>>a[i];
	
}