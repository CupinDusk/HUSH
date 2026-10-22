// Own callback-driven source; unchanged countdown/register endpoint.
#include "endpoint_implementation.hpp"
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using Key=std::array<int,16>;
struct State {
    int t, mode=1, waiting=0, due=0, age=-1, target=-1;
    Endpoint ep;
    State(int p,int K,int P,int phi,int a):t(a),ep({(unsigned)p,(unsigned)K,(unsigned)P,(unsigned)phi}){}
    Key key()const {
        return {t,ep.valid,ep.enabled,(int)ep.count,ep.value,
                ep.register0.occupied,(int)ep.register0.id,ep.register0.value,
                ep.register1.occupied,(int)ep.register1.id,ep.register1.value,
                mode,waiting,due,age,target};
    }
};
struct Obs {int read=0,reply=0,expired=0,miss=0;};
Obs step(State &s,int p,int a,int b,int wu,int branch,int L){
    Obs o;o.expired=s.ep.begin_tick(s.t,wu);
    if(!s.waiting){
        if(s.due>0)--s.due;
        if(!s.due){
            o.read=1;
            if(!s.ep.accept_read(1)){o.miss=1;return o;}
            s.waiting=1;s.age=0;s.target=-1;
        }
    }
    if(auto r=s.ep.finish_tick(s.t)){
        assert(s.waiting && r->id==1 && r->value==0);
        o.reply=1;s.waiting=0;
        s.due=(s.mode?b:a)+branch*p;
        if(!branch)s.mode=1-s.mode;
        s.target=s.age+s.due;
    }
    if(s.age>=0)++s.age;
    assert(s.age<4*p && s.due<2*p && s.target<4*p);
    s.t=(s.t+1)%L;return o;
}
void keyout(const Key&k){std::cout<<'[';for(size_t i=0;i<k.size();++i){if(i)std::cout<<',';std::cout<<k[i];}std::cout<<']';}
int main(){
    int id,p,a,b;
    while(std::cin>>id>>p>>a>>b){
        assert(1<=a && a<b && b<p);
        for(int policy=0;policy<2;++policy){
            int K=policy?3:2,P=(policy?2:3)*p,phi=a+policy,L=std::lcm(p,P);
            std::vector<State> states;states.emplace_back(p,K,P,phi,a);
            std::map<Key,int> seen;seen[states[0].key()]=0;unsigned edges=0;
            for(size_t i=0;i<states.size();++i){
                std::cout<<"{\"kind\":\"state\",\"case\":"<<id<<",\"policy\":"<<policy<<",\"id\":"<<i<<",\"key\":";
                keyout(states[i].key());std::cout<<"}\n";
                for(int wu=0;wu<2;++wu){
                    bool has_reply=false;
                    for(int bit=0;bit<2;++bit){
                        if(bit && !has_reply)break;
                        State next=states[i];auto o=step(next,p,a,b,wu,bit,L);
                        assert(!o.miss && !o.expired);has_reply=o.reply;
                        auto [it,newly]=seen.emplace(next.key(),(int)states.size());
                        int j=it->second;if(newly)states.push_back(next);
                        std::cout<<"{\"kind\":\"edge\",\"case\":"<<id<<",\"policy\":"<<policy<<",\"from\":"<<i<<",\"to\":"<<j<<",\"wu\":"<<wu<<",\"branch\":"<<(o.reply?bit:-1)<<",\"read\":"<<o.read<<",\"reply\":"<<o.reply<<",\"expired\":"<<o.expired<<"}\n";
                        ++edges;
                    }
                }
            }
            std::cout<<"{\"kind\":\"summary\",\"case\":"<<id<<",\"policy\":"<<policy<<",\"states\":"<<states.size()<<",\"edges\":"<<edges<<"}\n";
        }
    }
    // Named negative controls, outside the accepted graph domains.
    State unsafe(9,2,18,3,2);int expiry=-1,miss=-1;
    for(int t=2;t<=40;++t){auto o=step(unsafe,9,2,7,t==3,1,18);if(o.expired)expiry=t;if(o.miss){miss=t;break;}}
    assert(expiry==21 && miss==34);
    State invalid(9,2,27,2,2);invalid.ep.valid=false;auto o=step(invalid,9,2,7,0,0,27);assert(o.miss);
    std::cout<<"{\"kind\":\"negative\",\"expiry\":"<<expiry<<",\"miss\":"<<miss<<",\"invalid_entry_read\":2}\n";
}
