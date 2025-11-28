#ifndef __TRSA_H__
#define __TRSA_H__

typedef unsigned long long nat;
typedef long long intg;

typedef struct
{
    nat e;
    nat N;
} public_key;

typedef struct
{
    nat d;
    nat N;
} private_key;

/**
 * Exponentiation modulo m using square-and-multiply.
 * @param a Base.
 * @param b Exponent.
 * @param m Modulo.
 * @return $a^b \mod m$.
 */
nat powm(nat a, nat b, nat m);

/**
 * Computes the extended Euclidean algorithm of two numbers.
 * @param a First number.
 * @param b Second number.
 * @param x Pointer to the Bezout coefficient of the first number.
 * @param y Pointer to the Bezout coefficient of the second number.
 * @return Returns $\gcd(a, b)$, and rewrites $x$, $y$ so that
 *  $ax+by = \gcd(a, b)$.
 */
nat euclid(nat a, nat b, intg *x, intg *y);

#endif // ! __TRSA_H__