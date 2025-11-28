#include "trsakg.h"

#include <stdlib.h>
#include <time.h>

void generate_keys(nat ps[], unsigned int n, public_key *pbk, private_key *pvk)
{
    srand(time(NULL));

    unsigned int i = (unsigned int)(rand() % n);
    unsigned int j = i;

    while (j == i)
        j = (unsigned int)(rand() % n);

    nat N = ps[i] * ps[j];
    pbk->N = N;
    pvk->N = N;

    nat phi = (ps[i] - 1) * (ps[j] - 1);
    nat e = 0;
    intg d, _;

    do
    {
        e = ((nat)rand() % (phi - 1)) + 1;
        e |= 1;
    } while (euclid(phi, e, &_, &d) != 1);

    while (d < 0)
        d += phi;

    pbk->e = e;
    pvk->d = (nat)d;
}