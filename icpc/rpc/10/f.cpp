#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) for(auto pera:v) cout<<pera<<" ";;cout<<endl;
#define imp2(v) for(auto [sandia,melon]:v) cout<<sandia<<","<<melon<<" ";;cout<<endl;
#define inp(v) for(auto &uva:v) cin>>uva;
#define inp2(v) for(auto &[fresa,mora]:v) cin>>fresa>>mora;

using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef vector<ii> vi;
typedef __int128 xl;
typedef long double ld;
typedef vector<vv> mtx;
const ll maxn=2505;
vector<bitset<maxn>> b;
vector<bitset<maxn>> c;
ll h,w;

bool can(ll m){
    c=b;
    fore(i,0,h){
        fore(j,0,w){
            if(c[i][j]){
                fore(k,0,m){
                    fore(r,0,m){
                        if((i+k)>=h||(j+r)>=w||!c[i+k][j+r]){
                            return false;
                        }
                        else c[i+k][j+r]=0;
                    }
                }
                j+=m-1;
            }
        }
    }
    return true;
}
ll mygcd(ll a, ll b){
	if(!a&&!b)return 0;
	return __gcd(a,b);
}
int main(){
    JET
    cin>>h>>w;
    b.resize(h);
    fore(i,0,h){
        char x;
        fore(j,0,w){
            cin>>x;
            b[i][j]=(x=='#');
        }
    }
    ll g=0;
    fore(i,0,h){
        ll cnt=0;
        fore(j,0,w){
            if(b[i][j]) cnt++;
            else {
                g=mygcd(g,cnt);
                cnt=0;
            }
        }
        g=mygcd(g,cnt);
    }
    fore(j,0,w){
        ll cnt=0;
        fore(i,0,h){
            if(b[i][j]) cnt++;
            else {
                g=mygcd(g,cnt);
                cnt=0;
            }
        }
        g=mygcd(g,cnt);
    }
    for(ll i=g; i>0; i--){
        if(!(g%i)){
            if(can(i)){
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}