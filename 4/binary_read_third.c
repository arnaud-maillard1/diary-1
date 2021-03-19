#include <stdio.h>
#include <stdlib.h>

typedef struct Entry
{
    int year;
    double temperature;
} Entry;

int main()
{
    Entry entry;

    FILE *fp = fopen("output.dat", "rb");
    if (fp == NULL)
        abort();

    fseek(fp, 3 * sizeof(Entry), SEEK_SET);
    fread(&entry, sizeof(Entry), 1, fp);
    fclose(fp);

    printf("Year: %d\n", entry.year);
}
