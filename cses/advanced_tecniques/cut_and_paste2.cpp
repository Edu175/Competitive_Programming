#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <ext/rope>
using namespace __gnu_cxx;
rope<char> s;
// Sequence with O(log(n)) random access, insert, erase at any position
// s.push_back(x);
// s.insert(i,r) // insert rope r at position i
// s.erase(i,k) // erase subsequence [i,i+k)
// s.substr(i,k) // return new rope corresponding to subsequence [i,i+k)
// s[i] // access ith element (cannot modify)
// s.mutable_reference_at(i) // acces ith element (allows modification)
// s.begin() and s.end() are const iterators (use mutable_begin(), mutable_end() to allow modification)

int main(){FIN;
	ll n,m; cin>>n>>m;
	string t; cin>>t;
	fore(i,0,n)s.pb(t[i]);
	while(m--){
		ll l,r; cin>>l>>r; l--;
		rope<char>ns=s.substr(l,r-l);
		s.erase(l,r-l);
		s.insert(n-(r-l),ns);
	}
	cout<<s<<"\n";
	//fore(i,0,n)cout<<s[i];;cout<<"\n";
	return 0;
}


