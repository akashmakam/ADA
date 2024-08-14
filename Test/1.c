#include <stdio.h>
#include <stdlib.h>

int euclids(int m, int n, int mode) {
    int a, b, count = 0;
    if (m > n) {
        a = m;
        b = n;
    } else {
        a = n;
        b = m;
    }
    while (b != 0) {
        int remainder = a%b;
        a = b;
        b = remainder;
        count++;
    }
    if (mode == 0) {
        printf("\nThe GCD of the numbers %d and %d is %d!\n", m, n, a);
    }
    return count;
}

int consecutiveIntegerChecking(int m, int n, int mode) {
    int t, count = 0, a = m, b = n;
    t = (m > n)? n : m;
    while (t > 0) {
        if (m%t == 0 && n%t == 0) {
            if (mode == 0)
                printf("\nThe GCD of the numbers %d and %d is %d!\n", a, b, t);
            return count + 1;
        } else {
            t--;
            count++;
        }
    }
    return -1;
}

int repeatedSubtraction(int m, int n, int mode) {
    int a = m, b = n, count = 0;
    while (m != n) {
        if (m > n)
            m = m - n;
        else
            n = n - m;
        count++;
    }
    if (mode == 0)
        printf("\nThe GCD of the numbers %d and %d is %d!\n", a, b, m);
    return count + 1;
}

void tester(int choice) {
    int m, n;
    printf("\nEnter any two numbers:\n");
    scanf("%d %d", &m, &n);
    switch(choice) {
        case 1: euclids(m, n, 0); break;
        case 2: consecutiveIntegerChecking(m, n, 0); break;
        case 3: repeatedSubtraction(m, n, 0); break;
        case 4: return;
        default: printf("\nInvalid option!\n");
    }
}

void plotter(int choice) {
    int m, n;
    int count, maxcount, mincount;
    FILE *f1, *f2;
    for(int i = 10; i <= 100; i += 10) {
        maxcount = 0; mincount = 10000;
        for(int j = 2; j <= i; j++) {
            for(int k = 2; k <= i; k++) {
                count = 0;
                m = j;
                n = k;
                switch(choice) {
                    case 1:
                        count = euclids(m, n, 1);
                        break;
                    case 2:
                        count = consecutiveIntegerChecking(m, n, 1);
                        break;
                    case 3:
                        count = repeatedSubtraction(m, n, 1);
                        break;
                }
                if(count > maxcount)
                    maxcount = count;
                if(count < mincount)
                    mincount = count;
            }
        }
        switch(choice) {
            case 1:
                f1 = fopen("e_b.txt","a");
                f2 = fopen("e_w.txt","a");
                break;
            case 2:
                f1 = fopen("c_b.txt","a");
                f2 = fopen("c_w.txt","a");
                break;
            case 3:
                f1 = fopen("m_b.txt","a");
                f2 = fopen("m_w.txt","a");
                break;
        }
        fprintf(f1,"%d %d\n", i, mincount);
        fclose(f1);
        fprintf(f2,"%d %d\n", i, maxcount);
        fclose(f2);
    }
}

int main() {
    int choice;
    printf("Select an algorithm:\n"
        "1. Euclid's algorithm\n"
        "2. Consecutive Integer Checking algorithm\n"
        "3. Modified Euclid's algorithm\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: tester(choice); plotter(choice); break;
            case 2: tester(choice); plotter(choice); break;
            case 3: tester(choice); plotter(choice); break;
            case 4: exit(0); break;
            default: printf("\nInvalid option!\n");
        }
    return 0;
}