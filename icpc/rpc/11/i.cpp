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
const ld eps=1e-12, pi=atan2l(0.L,-1.L);
struct pt{
    ld x,y;
    pt(ld x, ld y): x(x),y(y) {}
    pt(ld a): x(cosl(a)), y(sinl(a)) {}
    pt() {}
    ld norm2(){return *this**this;}
    ld norm(){return sqrtl(norm2());}
    pt operator+(pt p){return pt(x+p.x,y+p.y);}
    pt operator-(pt p){return pt(x-p.x,y-p.y);}
    pt operator*(ld t){return pt(x*t,y*t);}
    pt operator/(ld t){return pt(x/t,y/t);}
    ld operator*(pt p){return x*p.x+y*p.y;}
};
struct ln{
    pt p,pq;
    ln(pt p, pt q): p(p),pq(q-p) {}
    ln() {}
    pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
    ld dist(pt r){return (r-proj(r)).norm();}
};
struct circ{
    ld r, a, R;
    circ(ld r, ld a, ld R): r(r), a(a), R(R) {}
    circ() {}
    ld ar(ld g, bool f){
        ld d=R*sinl(abs(a-g));
        if(d<=eps) return pi*r*r/2;//se puede borrar
        if(d>r) return (f?pi*r*r:0.L);
        ld b=sqrt(r*r-d*d);
        ld z=atan2l(b,d);
        ld s=z*r*r-b*d;
        return (f?pi*r*r-s:s);
    }
};

int main(){
    JET
    ll n,k; ld R,z; cin>>n>>k>>R>>z;
    z=z*pi/180.L;
    circ c[n];
    ld ang[n];
    ld A=z*R*R;
    fore(i,0,n){
        ld r,a,d; cin>>r>>a>>d;
        a=a*pi/180.L;
        c[i]=circ(d/2,a,r);
        ang[i]=a;
        A-=pi*d*d/4;
    }
    A/=k;
    ld u=-z;
    vector<ld> rt;
    fore(i,0,k-1){
        ld l=u, r=z;
        while(r-l>=eps){
            ld a=(l+r)/2;
            ld ar=(a-u)*R*R/2;
            fore(i,0,n){
                ld a1=c[i].ar(u,ang[i]<u);
                ld a2=c[i].ar(a,ang[i]<a);
                ar-=max(a1,a2)-min(a1,a2);
            }
            if(ar<=A) l=a;
            else r=a; 
        }
        u=l;
        rt.pb(u*180.L/pi);
    }
    fore(i,0,k-1) cout<<fixed<<setprecision(16)<<rt[i]<<"\n";
    return 0;
}