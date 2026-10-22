"""Direct finite checks of the R17 read-last query and its displayed examples."""
from pathlib import Path
import json


def expiry(r,K,P,phi,delta=0):
    # First decrement is weakly/strictly after the arm, by declared priority.
    return r+delta+(phi-r-delta)%P+(K-1)*P


def margin(C,J,K,P,phi,delta=0):
    return min(expiry(c-J+1,K,P,phi,delta)-c for c in C)


def main():
    checks=0
    for P in range(1,9):
        for K in range(1,5):
            for J in range(5):
                for phi in range(P):
                    for delta in (0,1):
                        for l in range(2*P):
                            for width in range(2*P+1):
                                u=l+width;C=range(l,u+1)
                                fl=expiry(l-J+1,K,P,phi,delta)
                                fu=expiry(u-J+1,K,P,phi,delta)
                                expected=fl-u if fl==fu else (K-1)*P-J+1+delta
                                assert margin(C,J,K,P,phi,delta)==expected
                                checks+=1
    C=(0,2);m=margin(C,0,2,4,2);uniform=5;projected=expiry(1,2,4,2)-2
    assert (m,uniform,projected)==(6,5,4)
    R=tuple((s,4*((s+3)//4)+8) for s in range(104,109));C=tuple(sorted({c for s,c in R}))
    historical=min(expiry(s+1,4,8,6)-c for s,c in R)
    projected=margin(C,11,4,8,6)
    assert max(c-s for s,c in R)==11 and (projected,historical)==(14,18)
    result={'result':'PASS','interval_queries_both_priorities':checks,
            'nonconvex_example':{'RP':m,'RU':uniform,'PP':4,'age':5},
            'partial_cell_example':{'C':C,'J':11,'M':projected,'Gamma':historical,'age':15},
            'scope':'Finite arithmetic checks; not a proof, source execution or native evidence.'}
    (Path(__file__).parent/'NEW_COMPARISONS.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(result))


if __name__=='__main__':main()
