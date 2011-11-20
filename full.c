#define _GNU_SOURCE
#ifdef AH
#include<alloca.h>
#endif
#include<ctype.h>
#include<math.h>
#include<setjmp.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#if !NOMMAP
#include<sys/mman.h>
#endif
#define vo volatile
#define A(x,y,z) O(x,y,z##1)O(x,y,z##2)O(x,y,z##3)
#define B(x,y) A(x,y,1)A(x,y,2)A(x,y,3)
#define C(x,y) B(x,y##1)B(x,y##2)B(x,y##3)
#define D(x) C(x,1)C(x,2)C(x,3)
#define E(x) D(x##1)D(x##2)D(x##3)
#define G E(1)E(2)E(3)
#define S d->
#define R(x) ; S u(); S r(#x); S u();
#define L(x,y) S l[x](d)R(y)
#define F(x) void l##x(vo dat d) {
#define Q(x); S a--; *S a=*S a x S a[1]; R(x)
#define O(x,y,z) x##y##z,
#define q typedef
#define H 9<<16
#define I case
#define J(i) calloc(i,1)

q char k;
q void o;
q int u;
q o (*f)(vo o*);
q struct { u*a,**R,*m,h,c; k**s; o(*u)(); f*l,*j,r; } *dat;

u m[]={G 0};
u n[H];
dat st;
u sk[H];
k*U,*w;
o*x[H];
u y[H];
k*j,*e;

#define W(c) memcpy(e,x[(u)c],y[(u)c]); e+=y[(u)c];

o g(u v){
    if(v>256){
        g(v/256);
        g(256);
        W('*')
    }else{
        W(m[v])
    }
}

f K(k*p,dat d){
    k c,n=0;
    f r=(f)e;
    W(1)
    while((c=*p)){
        switch(c){
            I'#':
                while(*++p!=10);
                break;
            I'[':
                c=1;
                S s[S c]=++p;
                for(;c;p++){
                    if(*p=='[')c++;
                    else if(*p==']')c--;
                }
                p[-1]=0;
                g(S c++);
                break;
            I'!':
                n=1;
                c=*++p;
            I'=':
            I'<':
            I'>':
                W(c)
                if(n){ W('!')n=0; }
                g(*++p);
                W('|')
                p++;
                break;
            I's':
            I'S':
            I'l':
            I'L':
                g(*++p);
                W(c)
                p++;
                break;
            I'_':
                p++;
            default:
                if(isdigit(*p)){
                    g(atoi(p));
                    while(isdigit(*p))p++;
                } else p++;
                W(c)
        }
    }
    W(2)
#ifdef JDEBUG
    fwrite(j, 1, e-j, stdout);
    fflush(stdout);
#endif
    return r;
}

o t(vo dat d) {
    S u(); S r("\01"); S u()R(F)
    Q(+)Q(-)Q(*)*S a=-*S a; R(_)
    S a--;R(@)
    Q(==)Q(<)Q(>)*S a=!*S a; R(!)
    S a[-1]^=*S a; *S a^=S a[-1]R(r)
    S a[1]=*S a; S a++R(d)
    *S R[*S a]=S a[-1]; S a--; R(s)
    *++S R[*S a]=S a[-1]; S a--; R(S)
    *S a=*S R[*S a]; R(l)
    *S a=*S R[*S a]--; R(L)
    L(1,/)L(2,P)L(3,p)L(4,x)L(5,v)L(6,|)
#undef O
#define O(x,y,z) *++S a=S m[(x*S h+y)*S h+z]; S u(); S r(""); S u();
    G S l[0](d);
}

o T(){ }

o ru(){
    k*a=0,**b=&a,**c=b+32;
    for(;b<c&&(*b<w||*b>(k*)T);b++);
    if(b==c){
        jmp_buf*j=alloca(sizeof(jmp_buf));
        setjmp(*j);
        ru();
    } else {
        U=w;
        w=*b;
    }
}

o rd(u v){
    x[v]=U;
    y[v]=w-U-y['F'];
}

q o(*rt)(u);
vo rt rs=rd;

o re(vo k*rec){
    static u i=0;
    *(st->a=sk+9)=0;
    rs(*rec?*rec:m[i++]);
}

F(d)S a[-1]/=*S a;S a--; }
F(P)printf("%d",*S a); fflush(stdout); }
F(p)printf("%d\n",*S a); }
F(x)u n=*S a--;if(!S j[n])S j[n]=K(S s[n],d);S j[n](d); }
F(v)*S a=sqrt(*S a); }
F(1)S a-=2; if(S a[1]){ S a[1]=*S R[S a[2]]; S a++; S l[4](d); } }

o*lib1[]={T,T,T,T,T,T,T};
o*lib2[]={T,ld,lP,lp,lx,lv,l1};

u main(){
    u i;
    k*b;
    dat d=st=J(sizeof(*st));
    S a=sk+9;
    S R=J(256*sizeof(k*));
    for(i=0;i<256;i++)S R[i]=J(H);
    S m=n;
    S s=J(H);
    S u=ru;
    S l=(f*)lib1;
    S j=J(H);
    S r=(f)re;
    for (i=0;m[i];i++)n[m[i]]=i;
    w=(k*)t;
    t(d);
    y[1]-=y['F'];
    x[2]=w;
    y[2]=(k*)T-w+8;

    S h=100;
    S l=(f*)lib2;
    S r=(f)T;

    /* get space */
    j=e=
#if NOMMAP
    malloc(H);
#else
    mmap(0,H,-1,MAP_PRIVATE|MAP_ANON,-1,0);
#endif
    b=malloc(H);
    b[fread(b,1,(H)-1,stdin)]=0;
    K(b,d);

    ((f)j)(d);

    return 0;
}
