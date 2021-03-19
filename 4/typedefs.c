#include <stdint.h> // Autre types entiers
#include <stdlib.h> // size_t
// Types de base
char c;
int i;
float f;
double d;
long l;
long long int ll;
unsigned long long int ull;

// Depuis C99
uint8_t u8;
uint32_t u32;
int64_t i64;
uint_least32_t ul32;
uint_fast32_t uf32;
size_t s;

// Mon type à moi !
typedef uint16_t Counter;
// typedef <type existant> <nouveau type>

void foo(Counter u);

int bar()
{
    Counter count = 42;
}

/**
 * Structures
 * - C'est des conteneurs de données
 */
int x;
int t;
int y;
int z;

int take_point(int x, int y, int z);
void get_point(int *x, int *y, int *z);

struct Point
{
    int x;
    int y;
    int z;
};

typedef struct Point Point;

typedef struct Point2D
{
    int x;
    int y;
} Point2D;

int main()
{
    struct Point p = {.x = 1, .y = 2, .z = 3};
    p.x = 42;
    Point r; // Utilise le typedef

    Point2D q = {.x = 42, .y = 23};
}

int take_point2(Point p)
{
    printf("x: %d, y: %d, z: %d\n", p.x, p.y, p.z);
}

Point get_point2()
{
    Point p;
    p.x = rand();
    p.y = rand();
    p.z = rand();
    return p;
}
