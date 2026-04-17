#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;

bool solve(vector<int>a){
	map<ll,ll>c;
	for(auto i:a)if(++c[i]>2)return 0;
	return 1;
}

class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        return solve(nums);
    }
};

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	cout<<solve(a);
	return 0;
}
