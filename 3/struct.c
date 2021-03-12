#include <stdio.h>

typedef int longueur;

typedef struct Point {
    int x;
    int y;
} Point;

void process_string(const char *str, Point *p) {
    int size = strlen(str);
    for (int i = 0; i < size; i++) {
        const char c = str[i];
        if (c == '-') p->x++;
        else if (c == '.') p->y++;
    }
}

void move(Point *s) {
    s->x += 10;
    s->y -= 20;
}

void display_position(Point r) {
    printf(
        "{\n"
        "    \"x\": %d,\n"
        "    \"y\": %d\n"
        "}\n", r.x, r.y);
}

int main() {
    Point p = {.x = 42, .y = 23};
    Point q = {.x = 12, .y = 7};

    longueur a = 23;

    process_string("....--.--...", &q);

    display_position(p);
    move(&p);
    display_position(p);

    display_position(q);
}
