#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct Entry
{
    int32_t year;
    // 4 bytes de padding.
    double temperature;
} Entry;

int main()
{
    // 10 * sizeof(Entry)
    //      sizeof(int) + sizeof(double)
    //      4           + 8
    //      12
    // 120
    Entry data[10] = {
        {2010, 21.6}, {2020, 23.9}, {2011, 21.6}, {2020, 23.9}, {2012, 21.6}, {2020, 23.9}, {2013, 21.6}, {2020, 23.9}, {2014, 21.6}, {2020, 23.9}};
    const size_t size = sizeof(data) / sizeof(data[0]);

    FILE *fp = fopen("output.dat", "wb");
    if (fp == NULL)
        abort();

#if 0
    for (int i = 0; i < size; i++)
    {
#if 0
        fwrite(&data[i].year, sizeof(int), 1, fp);
        fwrite(&data[i].temperature, sizeof(double), 1, fp);
#else
        fwrite(&data[i], sizeof(data), 1, fp);
#endif
    }
#else
    fwrite(data, sizeof(Entry), size, fp);
#endif

    fclose(fp);
}

// little endian da 07 00 00 -> 0x000007da
