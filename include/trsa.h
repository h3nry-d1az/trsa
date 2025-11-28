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

/**
 * Encrypts an integer message using the provided public key.
 *
 * The encryption is performed as:
 *   $$ c = m^e \mod N $$
 * @param m Message to encrypt.
 * @param pbk Public key.
 * @return Ciphertext in the range [0, N-1].
 */
nat encrypt(nat m, public_key pbk);

/**
 * Decrypts a ciphertext using the provided private key.
 *
 * The decryption is performed as:
 *   $$ m = c^d \mod N $$
 * @param c Ciphertext to decrypt.
 * @param pvk Private key.
 * @return Decrypted message in the range [0, N-1].
 */
nat decrypt(nat c, private_key pvk);

#endif // ! __TRSA_H__