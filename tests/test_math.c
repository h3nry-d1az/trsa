#include "tests.h"
#include "trsa.h"

int main()
{
    printf("File %s\n", __FILE__);
    int p = 0;

    p += assert_test(1, "powm1", powm(43531, 61785, 57177) == 49681);
    p += assert_test(2, "powm2", powm(51749, 35309, 93109) == 60606);
    p += assert_test(3, "powm3", powm(45448, 65226, 29714) == 3244);
    p += assert_test(4, "powm4", powm(26408, 83418, 41013) == 5923);
    p += assert_test(5, "powm5", powm(19281, 16583, 52642) == 15131);
    p += assert_test(6, "powm6", powm(15174, 71077, 24499) == 22520);
    p += assert_test(7, "powm7", powm(49843, 34556, 40781) == 859);
    p += assert_test(8, "powm8", powm(59921, 16428, 13092) == 2317);
    p += assert_test(9, "powm9", powm(68870, 57041, 18371) == 15752);

    nat d;
    intg x, y;

    d = euclid(60979, 21673, &x, &y);
    p += assert_test(10, "euclid1", d == 1 && x == -8063 && y == 22686);
    d = euclid(66383, 67539, &x, &y);
    p += assert_test(11, "euclid2", d == 1 && x == -28336 && y == 27851);
    d = euclid(41260, 23503, &x, &y);
    p += assert_test(12, "euclid3", d == 1 && x == 634 && y == -1113);
    d = euclid(96008, 75669, &x, &y);
    p += assert_test(13, "euclid4", d == 11 && x == -1916 && y == 2431);
    d = euclid(62951, 81324, &x, &y);
    p += assert_test(14, "euclid5", d == 1 && x == -19573 && y == 15151);
    d = euclid(22379, 33931, &x, &y);
    p += assert_test(15, "euclid6", d == 1 && x == -13432 && y == 8859);
    d = euclid(75363, 16510, &x, &y);
    p += assert_test(16, "euclid7", d == 1 && x == 657 && y == -2999);
    d = euclid(89279, 77745, &x, &y);
    p += assert_test(17, "euclid8", d == 73 && x == 182 && y == -209);
    d = euclid(62879, 97554, &x, &y);
    p += assert_test(18, "euclid9", d == 1 && x == -26533 && y == 17102);

    printf("\n%sPassed: %d.%s\n", GREEN, p, WHITE);
    printf("%sFailed: %d.%s\n", RED, 18 - p, WHITE);
    return 0;
}