#include <stdio.h>
#include <stdlib.h>

typedef struct Entry
{
    int year;
    double temperature;
} Entry;

int main()
{
    Entry data[10] = {{2010, 21.6}};

    FILE *fp = fopen("output.csv", "w");
    if (fp == NULL)
        abort();

    fprintf(fp, "Année,Température\n");
    fprintf(fp, "%d,%f\n", data[0].year, data[0].temperature);
    fclose(fp);
}
