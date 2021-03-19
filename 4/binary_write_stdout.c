#include <stdio.h>
#include <stdlib.h>

typedef struct Entry
{
    int year;
    double temperature;
} Entry;

int main()
{
    Entry data[10] = {
        {2010, 21.6}, {2020, 23.9}, {2011, 21.6}, {2020, 23.9}, {2012, 21.6}, {2020, 23.9}, {2013, 21.6}, {2020, 23.9}, {2014, 21.6}, {2020, 23.9}};
    const size_t size = sizeof(data) / sizeof(data[0]);

    fwrite(data, sizeof(Entry), size, stdout);
}
