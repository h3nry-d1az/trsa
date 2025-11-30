/**
 * @file trsakg.h
 * @brief Key generation algorithm.
 * @author Henry Díaz Bordón
 */
#ifndef __TRSA_KEYGEN_H__
#define __TRSA_KEYGEN_H__

#include "trsa.h"

/**
 * Generates a textbook RSA public/private key pair from two prime factors.
 *
 * This procedure employs the `rand` function from the standard library, hence
 * it is not cryptographically safe and serves only for demonstration purposes.
 * @param ps List of prime numbers.
 * @param n Number of primes in the array.
 * @param pbk Pointer to `public_key` struct to receive \f$(e, N)\f$.
 * @param pvk Pointer to `private_key` struct to receive \f$(d, N)\f$.
 */
void generate_keys(nat ps[], unsigned int n, public_key *pbk, private_key *pvk);

#endif // ! __TRSA_KEYGEN_H__