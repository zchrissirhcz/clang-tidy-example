#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Entity
{
public:
    Entity()
    {
        data = (int*)malloc(sizeof(int) * cameraNum);
        memset(data, 0, sizeof(cameraNum));
    }

    void print()
    {
        printf("data[0] = %d\n", data[0]);
    }

    ~Entity()
    {
        free(data);
    }

    int* data;
    int cameraNum;
};

int main()
{
    Entity e;
    e.print();
    return 0;
}