#include <stdio.h>

/**
 * 0 stdin
 * 1 stdout
 * 2 stderr
 * 3..n
 */
int main() {
    FILE *ffoo = fopen("foo", "r"); // 3
    FILE *fp = fopen("bar", "w"); // 4
    printf("a"); // 2
    fprintf(stdout, "b"); // 2
    fprintf(stderr, "c"); // 1
    fprintf(fp, "d"); // 4
    int i;
    char c;
    fscanf(stdin, "%d", &i); // scanf("%d", &i); // 0
    fscanf(ffoo, "%c", &c); // 3
}
