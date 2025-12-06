#include "trsa.h"

nat powm(nat a, nat b, nat m)
{
    unsigned char M = 8 * sizeof(b) - (unsigned char)(__builtin_clzll(b));
    nat r = 1, c = a % m;

    for (unsigned char i = 0; i < M; i++)
    {
        if (b & (1 << i))
            r = r * c % m;
        c = (c * c) % m;
    }

    return r;
}

nat euclid(nat a, nat b, intg *x, intg *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }

    intg x1, y1;
    nat gcd = euclid(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

nat encrypt(nat m, public_key pbk)
{
    return powm(m, pbk.e, pbk.N);
}

nat decrypt(nat c, private_key pvk)
{
    return powm(c, pvk.d, pvk.N);
}
