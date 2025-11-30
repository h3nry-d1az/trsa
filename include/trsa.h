/**
 * @file trsa.h
 * @brief Encryption and decryption algorithms.
 * @author Henry Díaz Bordón
 */
#ifndef __TRSA_H__
#define __TRSA_H__

typedef unsigned long long nat;
typedef long long intg;

/**
 * Public key for textbook RSA.
 * @param e Public exponent used for encryption.
 * @param N Modulus.
 */
typedef struct
{
    nat e;
    nat N;
} public_key;

/**
 * Private key for textbook RSA.
 * @param d Private exponent used for decryption.
 * @param N Modulus.
 */
typedef struct
{
    nat d;
    nat N;
} private_key;

/**
 * Exponentiation modulo m using square-and-multiply.
 * @param a Base.
 * @param b Exponent.
 * @param m Modulus.
 * @return \f$a^b \mod m\f$.
 */
nat powm(nat a, nat b, nat m);

/**
 * Computes the extended Euclidean algorithm of two numbers.
 * @param a First number.
 * @param b Second number.
 * @param x Pointer to the Bezout coefficient of the first number.
 * @param y Pointer to the Bezout coefficient of the second number.
 * @return Returns \f$\gcd(a, b)\f$, and rewrites \f$x\f$, \f$y\f$ so that
 *  \f$ax+by = \gcd(a, b)\f$.
 */
nat euclid(nat a, nat b, intg *x, intg *y);

/**
 * Encrypts an integer message using the provided public key.
 *
 * The encryption is performed as:
 *   \f$\f$ c = m^e \mod N \f$\f$
 * @param m Message to encrypt.
 * @param pbk Public key.
 * @return Ciphertext in the range \f$[0, N-1]\f$.
 */
nat encrypt(nat m, public_key pbk);

/**
 * Decrypts an encrypted integer using the provided private key.
 *
 * The decryption is performed as:
 *   \f$\f$ m = c^d \mod N \f$\f$
 * @param c Integer to decrypt.
 * @param pvk Private key.
 * @return Decrypted message in the range \f$[0, N-1]\f$.
 */
nat decrypt(nat c, private_key pvk);

#endif // ! __TRSA_H__