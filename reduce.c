#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "buffer.h"

struct SS {
    struct SS *next;
    int len, count, savings;
    char **locs;
};

struct SS *newSS(int len)
{
    struct SS *ret;
    SF(ret, malloc, NULL, (sizeof(struct SS)));
    ret->next = NULL;
    ret->len = ret->count = ret->savings = 0;
    SF(ret->locs, malloc, NULL, ((len+1)*sizeof(char *)));
    memset(ret->locs, 0, ((len+1)*sizeof(char *)));
    return ret;
}

void freeSS(struct SS *s)
{
    free(s->locs);
    free(s);
}

void link(struct SS **ssh, struct SS *n)
{
    n->savings = (n->len - 1) * (n->count - 1);
    n->next = *ssh;
    *ssh = n;
}

int sscmp(struct SS **a, struct SS **b)
{
    if ((*a)->savings < (*b)->savings) {
        return -1;
    } else if ((*a)->savings > (*b)->savings) {
        return 1;
    } else {
        return 0;
    }
}

int main()
{
    struct SS *ssl = NULL, *nl = NULL, *ssc, *ssn, **ssa;
    struct SS *sss[0x100];
    struct Buffer_char f;
    int i, l, sl;
    char c;

    /* read it in */
    INIT_BUFFER(f);
    READ_FILE_BUFFER(f, stdin);
    EXPAND_BUFFER(f);
    memset(f.buf + f.bufused, 0, f.bufsz - f.bufused);

    /* outright remove #lines */
    for (l = 0; l < f.bufused; l++) {
        if (f.buf[l] == '#') {
            for (; l < f.bufused && f.buf[l] != '\n'; l++) {
                f.buf[l] = '\0';
            }
            f.buf[l] = '\0';
        }
    }

    /* count all the initials */
    for (i = 1; i < 0x100; i++) {
        sss[i] = newSS(f.bufused);
        sss[i]->len = 1;
    }
    for (l = 0; l < f.bufused; l++) {
        c = f.buf[l];
        if (!c) continue;
        ssc = sss[c];
        ssc->locs[ssc->count++] = f.buf + l;
    }
    for (i = 1; i < 0x100; i++) {
        ssc = sss[i];
        if (ssc->count > 1) {
            link(&ssl, ssc);
        } else {
            freeSS(ssc);
        }
    }

    /* then recurse */
    for (sl = 2; sl < f.bufused - 1; sl++) {
        int ct = 0;
        fprintf(stderr, "  %d/%d\r", sl, f.bufused - 1);
        /* count all the greaters */
        for (ssn = ssl; ssn; ssn = ssn->next) {
            ct++;
            if (ssn->len != sl-1) break;
            for (i = 1; i < 0x100; i++) {
                sss[i] = newSS(f.bufused);
                sss[i]->len = sl;
            }
            for (l = 0; ssn->locs[l]; l++) {
                c = ssn->locs[l][sl-1];
                if (!c) continue;
                if (isspace(c)&&isspace(ssn->locs[l][sl-2])) continue;
                ssc = sss[c];
                ssc->locs[ssc->count++] = ssn->locs[l];
            }
            for (i = 1; i < 0x100; i++) {
                ssc = sss[i];
                if (ssc->count > 1) {
                    link(&ssl, ssc);
                } else {
                    freeSS(ssc);
                }
            }
        }
    }
    fprintf(stderr, "\n");

    /* put them all on an array */
    for (i = 0, ssn = ssl; ssn; i++, ssn = ssn->next);
    SF(ssa, malloc, NULL, (sizeof(struct SS *) * (i+1)));
    for (i = 0, ssn = ssl; ssn; i++, ssn = ssn->next) ssa[i] = ssn;
    ssa[i] = NULL;

    /* sort it */
    qsort(ssa, i, sizeof(struct SS *), sscmp);

    /* for readability, remove newlines */
    for (l = 0; l < f.bufused; l++) {
        if (f.buf[l] == '\n') f.buf[l] = '\\';
    }

    /*for (ssn = ssl; ssn; ssn = ssn->next) {
        printf("%d: %.*s: (%d*%d)\n", ssn->savings, ssn->len, ssn->locs[0], ssn->len-1, ssn->count-1);
    }*/
    for (i = 0; ssa[i]; i++) {
        ssn = ssa[i];
        printf("%d: %.*s: (%d*%d)\n", ssn->savings, ssn->len, ssn->locs[0], ssn->len-1, ssn->count-1);
    }

    return 0;
}
