#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef long double ld;
typedef pair<ld,ld> dd;
const ld EPS=1e-6;
const ld pii=acos(-1);
struct pt{
    ld x,y;
    pt (ld x, ld y): x(x), y(y){}
    pt(){}
    ld norm2(){return *this**this;}
    ld norm(){return sqrt(norm2());}
    bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
    pt operator+(pt p){return pt(x+p.x,y+p.y);}
    pt operator-(pt p){return pt(x-p.x,y-p.y);}
    pt operator*(ld t){return pt(x*t,y*t);}
    ld operator*(pt p){return x*p.x+y*p.y;}
    pt operator/(ld t){return pt(x/t,y/t);}
    ld angle(pt p){
        p=p-*this;
        ll res=acos(p.x/(p.norm()));
        res=((0<p.y || (p.y==0 && p.x>0))?res:2*pii-res);
        return res;
    } 

};
int main(){
    JET
    ll n; cin>>n;
    pt s, c; ld zc, zs;
    cin>>c.x>>c.y>>zc>>s.x>>s.y>>zs;
    //cout<<fixed<<setprecision(15);
    vector <pt> p(n);
    fore(i,0,n){
        cin>>p[i].x>>p[i].y;
    }
    vector <dd> a(n);
    fore(i,0,n){
        a[i]={p[(i+1)%n].angle(p[i]),p[(i+1)%n].angle(p[(i+2)%n])};
    }
    //fore(i,0,n) cout<<a[i].fst<<" "<<a[i].snd<<"\n";
    pt som=c+(c-s)*((zc)/(zs-zc));
    //cout<<som.x<<" "<<som.y<<"\n";
    bool y=false;
    fore(i,0,n){
        if(p[(i+1)%n]==som)continue;
        ld an=p[(i+1)%n].angle(som);
        //cout<<an<<"\n";
        if(a[i].fst-a[i].snd<=EPS){
            if(EPS>=a[i].fst-an && an-a[i].snd<=EPS) continue;
            else {y=true; break;}
        }
        else{
            if(EPS>=a[i].fst-an || an-a[i].snd<=EPS) continue;
            else {y=true; break;}
        }
    }
    cout<<(y?"S\n":"N\n");
    return 0;
}
