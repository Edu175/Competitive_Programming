#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll cuenta(const ii &a){
	return a.snd-a.fst;
}
int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n,k; cin>>n>>k;
		ii a[k];
		fore(i,0,k) cin>>a[i].fst>>a[i].snd;
		sort(a,a+k,[&](ii i, ii j){
			return i.snd-i.fst<j.snd-j.fst;
		});
		//cout<<"a"<<_<<endl;
		if((k>1) && (cuenta(a[k-1]) == cuenta(a[k-2]) && ((cuenta(a[k-1])<2) || cuenta(a[k-1])<=cuenta(a[0])+1))){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		ll r[n];
		mset(r,-1);
		r[a[k-1].fst-1]=0;
		fore(i,a[k-1].fst+1,a[k-1].snd+1){
			r[i-1] = i-1;
		}
		if(k>1 && cuenta(a[k-1])+1>=3 && cuenta(a[k-1])>cuenta(a[0])+1){
			r[a[0].fst-1] = r[a[k-1].fst]+1;
			fore(i,a[0].fst+1,a[0].snd+1) r[i-1]=i-1;
		}
		reverse(a,a+k);
		fore(i,0,k){
			fore(j,a[i].fst,a[i].snd+1){
				if(r[j-1]!=-1) continue;
				r[j-1]=((j==a[i].fst)?(!i?0:a[0].fst):j-1);
			}
		}
		fore(i,0,n) cout<<r[i]<<" ";
		cout<<"\n";
	}
	return 0;
}