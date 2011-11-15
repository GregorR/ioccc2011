#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<sys/mman.h>
#define i int
#define c char
#define w while
#define S switch
#define T case
#define U break;
typedef i(*f)(i*);
typedef i(*q)(i**,i*,f*);
f ff;
#define W 9<<19
#define J(nm) i nm##s; nm(i**a,i*r,f*F){ i b[9]; F[2](b); (*(*a)
J(m))=b[8]; ff(b); *b=0; }
i n(i**a,i*r,f*F){ i b[9]; *b=0; ff(b); F[2](b); }
J(a))++; } /* a_dd */
J(s))--; } /* s_ub */
J(r)++); } /* r_ight */
J(l)--); } /* l_eft */
J(p)); (*F)(*a); } /* p_utchar */
J(g))=F[1](0); } /* g_etchar */

P(i*C){ putchar(*C); }
u(i*C){ }
ri(i*C){ scanf("%d",C); }

t[W];
void*L[]={P,getchar,u};
q J[W];

#define A(x) O(x##1)O(x##2)O(x##3)
#define B(x) A(x##1)A(x##2)A(x##3)
#define C(x) B(x##1)B(x##2)B(x##3)
#define D(x) C(x##1)C(x##2)C(x##3)
#define E(x) D(x##1)D(x##2)D(x##3)
#define F(x) E(x##1)E(x##2)E(x##3)

#define O(x) J(j##x)); *r=x; }
F()
#undef O
#define O(x) J(J##x))?(*r=x):0; }
F()

main(){
    i*h,C,ms,Rs;
    c*j,*e,*R,*x;

    /* get space */
    j=e=mmap(0,9<<25,-1,MAP_PRIVATE|MAP_ANON,-1,0);

    /* figure out the size of the pro/epilogue */
    R=(c*)m;
    x=(c*)n;
    w(*++R==*++x);
    ms=R-(c*)m;
    R=(c*)n;
    x=(c*)a;
    w(*--R==*--x);
    Rs=(c*)n-++R;
    R-=ms;

    /* figure out the sizes of functions */
#define M(x,y) x##s=(c*)y-(c*)x-ms-Rs;
    M(a,s); M(s,r); M(r,l); M(l,p); M(p,g); M(g,P); M(j111111,j111112);
#undef O
#define O(x) j##x##s=j111111s;
    F()
    M(J111111,J111112);
#undef O
#define O(x) J##x##s=J111111s;
    F()

    /* JIT */
#define K(f)memcpy(e,(c*)f+ms,f##s);e+=f##s;
    w((C=getchar())>=0) {
        S(C){
            T'+':K(a)U
            T'-':K(s)U
            T'>':K(r)U
            T'<':K(l)U
            T'.':K(p)U
            T',':K(g)U
            T'$':K(R)ri(&C);J[C]=(q)e;memcpy(e,(c*)m,ms);e+=ms;U
            T'^':ri(&C);
#undef O
#define O(x) if(C==x){K(j##x)}
            F()U
            T'?':ri(&C);
#undef O
#define O(x) if(C==x){K(J##x)}
            F()U
        }
    }
    K(R)

    C=111111;
    h=t;
    w(C!=333333){J[C](&h,&C,(f*)L);}

    return 0;
}
