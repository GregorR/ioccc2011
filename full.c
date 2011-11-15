#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/mman.h>
#define i int
#define c char
#define w while
#define S switch
#define T case
#define U break;
#define ar (i**a,i*r,f*F)
typedef i(*f)(i*);
typedef i(*q)ar;
f ff;
#define W 9<<16
#define J(nm) i nm##s; nm ar{ i b[9]; F[2](b);
#define he i b[9];
i m ar{ i b[9]; F[2](b); *b=0; ff(b); F[2](b); **a=b[8]; }
i n ar{ i b[9]; F[2](b); ff(b); *b=0; **a=b[8]; F[2](b); }
J(a)(**a)++; } /* a_dd */
J(s)(**a)--; } /* s_ub */
J(r)(*a)++; } /* r_ight */
J(l)(*a)--; } /* l_eft */
J(p) F[0](*a); } /* p_utchar */
J(g) F[1](*a); } /* g_etchar */

P(i*C){ putchar(*C); }
G(i*C){ *C=getchar(); }
u(){ }
ri(i*C){ scanf("%d",C); }

t[W];
void*L[]={P,G,u};
q J[W];

#define A(x) O(x##1)O(x##2)O(x##3)
#define B(x) A(x##1)A(x##2)A(x##3)
#define C(x) B(x##1)B(x##2)B(x##3)
#define D(x) C(x##1)C(x##2)C(x##3)
#define E(x) D(x##1)D(x##2)D(x##3)
#define F(x) E(x##1)E(x##2)E(x##3)

#define O(x) J(j##x)*r=x; }
F()
#undef O
#define O(x) J(J##x)**a?(*r=x):0; }
F()

main(){
    i*h,C,ms,Rs;
    c*j,*e,*R,*x;

    /* get space */
    j=e=
#ifndef NOMMAP
    mmap(0,9<<25,-1,MAP_PRIVATE|MAP_ANON,-1,0);
#else
    malloc(9<<25);
#endif

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
    printf("%d %d\n", ms, Rs);

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
    w((G(&C),C)>=0){
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
        if(C=='!')break;
    }
    K(R)

    C=111111;
    h=t;
    w(C!=333333){ J[C](&h,&C,(f*)L);}

    return 0;
}
