#include<ctype.h>
#include<stdio.h>

int main()
{
    int rc, cc, c;
    rc = cc = 0;

    while ((c=getchar())>0) {
        rc++;
        if (!isspace(c)) {
            if (c == '{' || c == '}' || c == ';') {
                c=getchar();
                rc++;
                if (!isspace(c)) {
                    printf("WARNING! %c\n", c);
                    cc += 2;
                }
            } else {
                cc++;
            }
        }
    }

    printf("%d %d\n", rc, cc);
    return 0;
}
