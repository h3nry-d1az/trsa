#include "tests.h"
#include "trsakg.h"

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main()
{
    printf("File %s\n", __FILE__);
    int p = 0;

    nat primes[] = {62903, 66889, 25717, 14107, 17959,
                    14153, 37993, 37649, 12323, 82613};
    nat m;
    public_key pbk;
    private_key pvk;

    srand(time(NULL));

    for (int i = 1; i <= 10; i++)
    {
        generate_keys(primes, 10, &pbk, &pvk);
        m = (nat)rand() % (pbk.N / 100);
        p +=
            assert_test(i, "generate_keys", decrypt(encrypt(m, pbk), pvk) == m);
        sleep(1);
    }

    printf("\n%sPassed: %d.%s\n", GREEN, p, WHITE);
    printf("%sFailed: %d.%s\n", RED, 10 - p, WHITE);

    return 0;
}