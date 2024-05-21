#include <stdio.h>
#include <stdlib.h>
#define x 10
#define y 100

int test = 0;

float euclids(int m, int n) {
    int remainder, iterations = 0;
    while (n != 0) {
        remainder = m%n;
        m = n;
        n = remainder;
        iterations++;
    }
    return iterations;
}

float consecutiveIntegerChecking(int m, int n) {
    float iterations = 1;
    int t = (m > n)? n : m;
    while (t > 0) {
        if (m % t == 0 && n % t == 0) {
            return iterations;
        } else {
            t--;
            iterations++;
        }
    }
    return -1;
}

float modifiedEuclids(int m, int n) {
    int iterations = 1;
    while (m != n) {
        if (m > n)
            m = m - n;
        else
            n = n - m;
        iterations++;
    }
    return iterations;
}

void analysis(int ch) {
    int m, n, i, j, k;
    float count, maxcount, mincount;
    FILE *fp1, *fp2;
    for(i =  x; i <= y; i += 10) {
        maxcount=0; mincount=10000;
        for (j = 2; j <= i; j++) { // To generate the data
            for(k = 2; k <= i; k++) {
                count=0;
                m=j;
                n=k;
                switch(ch) {
                    case 1:
                        count=euclids(m,n);
                        break;
                    case 2:
                        count=consecutiveIntegerChecking(m,n);
                        break;
                    case 3:
                        count=modifiedEuclids(m,n);
                        break;
                }
                if(count>maxcount) // To find the maximum basic operations among all the combinations between 2 to n
                    maxcount=count;
                if(count<mincount) // To find the minimum basic operations among all the combinations between 2 to n
                    mincount=count;
            }
        }
        switch(ch) {
            case 1:
                fp2=fopen("e_b.txt","a");
                fp1=fopen("e_w.txt","a");
                break;
            case 2:
                fp2=fopen("c_b.txt","a");
                fp1=fopen("c_w.txt","a");
                break;
            case 3:
                fp2=fopen("m_b.txt","a");
                fp1=fopen("m_w.txt","a");
                break;
        }
        fprintf(fp2,"%d %.2f\n",i,mincount);
        fclose(fp2);
        fprintf(fp1,"%d %.2f\n",i,maxcount);
        fclose(fp1);
    }
}

int main() {
    int option;
    while(1) {
        printf("\nChoose any one of the following options to calculate GCD of two non-negative integers:\n");
        printf("1.Euclid's Algorithm\n2.Consecutive Integer Checking Method\n3.Modified Euclidean Algorithm\n0. Exit\n");
        scanf("%d",&option);
        switch(option) {
            case 1:
            case 2:
            case 3: analysis(option); break;
            default: return 0;
        }
    }
    return 0;
}