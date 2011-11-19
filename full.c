#define _GNU_SOURCE
#ifdef AH
#include<alloca.h>
#endif
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
#define R(x) ;S r(#x);
#define L(x,y) S l[x](d)R(y)
#define F(x) void l##x(vo dat d) {
#define Q(x) S a[-1] x##=*S a;S a--;R(x)
#define O(x,y,z) x##y##z,

int m[]={G 0};
int n[9<<16];

typedef void (*f)(vo void*);
typedef struct { int*a,*t,h,*m; char**s; f*j,*l,r; }*dat;

void t(vo dat d) {
    R(1)/*R(F)*/Q(+)Q(-)Q(*)*S a=-*S a;R(_)L(1,/)L(2,P)L(3,p)L(4,v)
#undef O
#define O(x,y,z) *++S a=S m[(x*S h+y)*S h+z];S r("");
    G S l[0](d);
}

void T() {}

dat state;
int stack[9<<16];
char*last;
void*code[9<<16];
int size[9<<16];
char*j,*e;

void rsubd(int v) {
    char*a=0,**b=&a;
    code[v]=last;
    while (*b<last||*b>(char*)T||*b==(char*)(long)v)b++;
    size[v]=*b-last-size['F'];
    last=*b;
}

typedef void(*rsubt)(int);
vo rsubt rsub=rsubd;

void recorder(vo char*rec) {
    static int i=0;
    jmp_buf j;
    *(state->a=stack+9)=0;
    setjmp(j);
    rsub(*rec?*rec:m[i++]);
}

F(d)S a[-1]/=*S a;S a--; }
F(P)printf("%d",*S a); fflush(stdout); }
F(p)printf("%d\n",*S a); }
F(v)*S a=sqrt(*S a); }

void*lib1[]={T,T,T,T,T};
void*lib2[]={T,ld,lP,lp,lv};

#define W(c) memcpy(e,code[(int)c],size[(int)c]);e+=size[(int)c];

void literal(int v) {
    if (v>256) {
        literal(v/256);
        literal(256);
        W('*');
    } else {
        W(m[v]);
    }
}

int main() {
    int i;
    char c;
    dat d=state=malloc(64);
    S a=stack+9;
    S h=0;
    S m=n;
    S l=(f*)lib1;
    S r=(f)recorder;
    for (i=0;m[i];i++)n[m[i]]=i;
    last=(char*)t;
    t(d);
    size['1']-=size['F'];
    code['2']=last;
    size['2']=(char*)T-last+8;

    S h=100;
    S l=(f*)lib2;
    S r=(f)T;

    /* get space */
    j=e=
#if NOMMAP
    malloc(9<<16);
#else
    mmap(0,9<<16,-1,MAP_PRIVATE|MAP_ANON,-1,0);
#endif

    W('1')
    while (!feof(stdin)) {
        if (scanf("%d",&i)>0) {
            literal(i);
        } else if (scanf("%c",&c)>0) {
            switch(c){
                case '_':
                    scanf("%d",&i);
                    literal(i);
                    break;
            }
            W(c)
        } else break;
    }
    W('2')

#ifdef JDEBUG
    fwrite(j, 1, e-j, stdout);
    fflush(stdout);
#endif
    ((f)j)(d);

    return 0;
}
