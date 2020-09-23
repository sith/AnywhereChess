#ifndef ANYWHERECHESS_MEMORYMANAGMENTUTILS_H
#define ANYWHERECHESS_MEMORYMANAGMENTUTILS_H

#include <cstdio>
#include <cstdlib>

int countOfObjectsInFreeSpace = 0;

void operator delete(void *p) noexcept {
    std::free(p);
    countOfObjectsInFreeSpace--;
}

void *operator new(size_t size) {
    void *p = malloc(size);
    countOfObjectsInFreeSpace++;
    return p;
}

#endif //ANYWHERECHESS_MEMORYMANAGMENTUTILS_H
