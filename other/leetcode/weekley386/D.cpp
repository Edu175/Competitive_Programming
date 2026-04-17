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
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=5005;
ll a[MAXN],b[MAXN];
ll n,m;
bool can(ll k){
	vector<ll>u(n,-1);
	vector<ll>ai(n);
	fore(i,0,n)ai[i]=a[i];
	ll c=0;
	fore(i,0,k+1){
		if(!ai[b[i]])c++;
		ai[b[i]]=0;
	}
	ll sum=n;
	fore(i,0,n)sum+=ai[i];
	return c>=sum;
}

ll solve(vector<int>A, vector<int>B){
	n=SZ(A),m=SZ(B);
	fore(i,0,n)a[i]=A[i];
	fore(i,0,m)b[i]=B[i]-1;
	ll l=0,r=m-1;
	while(l<=r){
		ll mid=(l+r)/2;
		if(can(mid))r=mid-1;
		else l=mid+1;
	}
	if(l>=m)return -1;
	return l+1;
}
class Solution {
public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        return solve(nums,changeIndices);
    }
};
int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<int>a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	cout<<solve(a,b);
	return 0;
}
