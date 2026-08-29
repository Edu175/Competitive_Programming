#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x) cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv; 

bool can(vv& a){
    fore(i,0,SZ(a)) if(a[i] != i+1) return false;
    return true;
}

pair<ii,vv> solve(vv &a){
    ll cnt1 = 0, cnt2 = 0;
    vv mvs;
	show(a)
    while(cnt1 < SZ(a)+5){
        if(can(a)) break;
        for(ll i = 1;i<SZ(a);i+=2){
            ll j = (i+1)%SZ(a);
            bool cond=1?a[j] < a[i] : a[j]>a[i];
			if(cond){
                swap(a[j],a[i]);
                mvs.pb(i+1);
                cnt2++;
            }
        }
        if(can(a)) break;
		show(a);
        for(ll i = 0;i<SZ(a);i+=2) swap(a[i],a[i+1]);
        mvs.pb(1);
        cnt1++;
		show(a);
    }
    return {{cnt1,cnt2},mvs};
}

int main(){
    JET
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        n*=2;
        vv a(n);
        fore(i,0,n) cin>>a[i];
        auto [p,v] = solve(a);
        if(p.fst <= n && p.snd <= n*n/2){
            cout<<"YES\n"<<SZ(v)<<"\n";
            show(v);
        }
        else cout<<"NO\n";
    }
    return 0;
}
