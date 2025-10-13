#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
 
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
 
ll n,C;
vv a,b,aa,bb;
const ll inf = 1e15;

vv solve(vv a, vv bb){
	
}

void solve(){
	vector<tipo> v(tamano,elem);
	vector<vector<vv>> x(2,vv(5)),res=x,res1=x;
    // ll x[C+1][C * 100+2], y[C+1][C*100+2];
    // ll res[C+1][C*100+2], res1[C+1][C*100+2];
    // fore(i,0,C+1)fore(j,0,C*100+2) res[i][j] = -inf, res1[i][j] = -inf;
    fore(_,0,2){
        // fore(i,0,C+1)fore(j,0,C*100+2) y[i][j] = -inf,x[i][j] = -inf;
        y[0][0] = 0;x[0][0] = 0;
        for(ll i = SZ(a)-1; i>=0;i --){
			x[i&1]
            fore(c,1,C+1){
                fore(pa,0,C*100+1){
					auto &r=x[c][pa];
					r = y[c][pa];
					if(pa >= a[i])r=max(r,y[c-1][pa-a[i]]);
                    // x[c][pa] = max((pa >= a[i] ? y[c-1][pa-a[i]]  : -inf)+ b[i], y[c][pa]);
                    // if(x[c][pa] > 0) cout<<"mi i es "<<i+1<<" y teniendo "<<c<<" para meter y acumulando con este "<<pa<<" obtengo "<<x[c][pa]<<"\n";
                    (_ ? res1[c][pa] : res[c][pa]) = max((_ ? res1[c][pa] : res[c][pa]),x[c][pa]);
                }
            }
			swap(x,y);
            // fore(k,0,C+1)fore(j,0,C*100+2)y[k][j] = x[k][j];
        }
        swap(a,bb);
        swap(b,aa);
    }
    ll r = 0;
    fore(pa,0,C*100+2){
        r = max(r,pa*res[C][pa]);
        r = max(r,pa*res1[C][pa]);
    }

    fore(i,1,C){
        ll j = C-i;
        fore(pa,0,i*100 + 1) fore(pb,0,j*100 + 1){
            if(res[i][pa] < 0 || res1[j][pb] < 0) continue;
            // if((pa+res1[j][pb]) * (res[i][pa]+pb) > 0){
                // cout<<"pongo "<<i<<" tq a <= b y "<<j<<" al reves, ahora tengo pa "<<pa<<" y pb "<<pb<<" con b de los primeros "<<res[i][pa]<<" y de los segundos "<<res1[j][pb]<<"\n";
            // }
            r = max(r,(pa+res1[j][pb])*(res[i][pa] + pb));
        }
    }
    cout<<r<<"\n";

}

int main(){
    JET
    ll t; cin>>t;
    while(t--){
		solve(a,b);
		solve(bb,aa);
        cin>>n>>C;
        a.clear(); b.clear();aa.clear();bb.clear();
        fore(i,0,n){
            ll x,y; cin>>x>>y;
            (x <= y ? a.pb(x) : aa.pb(x));
            (x <= y ? b.pb(y) : bb.pb(y));
        }
        solve();
    }

    return 0;
}