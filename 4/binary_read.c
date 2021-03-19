#include <stdio.h>
#include <stdlib.h>

typedef struct Entry
{
    int year;
    double temperature;
} Entry;

int main()
{
    Entry data[10];
    const size_t size = sizeof(data) / sizeof(data[0]);

    FILE *fp = fopen("output.dat", "rb");
    if (fp == NULL)
        abort();

    fread(data, sizeof(Entry), size, fp);
    fclose(fp);

    for (int i = 0; i < size; i++)
    {
        printf("Year: %d\n", data[i].year);
    }
}
