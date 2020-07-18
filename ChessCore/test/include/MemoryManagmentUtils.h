#ifndef ANYWHERECHESS_MEMORYMANAGMENTUTILS_H
#define ANYWHERECHESS_MEMORYMANAGMENTUTILS_H

#include <cstdio>
#include <cstdlib>

int countOfAllocatedObjectsInFreeSpace = 0;

void operator delete(void *p) noexcept {
    std::free(p);
    countOfAllocatedObjectsInFreeSpace++;
}

void *operator new(size_t size) {
    void *p = malloc(size);
    countOfAllocatedObjectsInFreeSpace--;
    return p;
}

#endif //ANYWHERECHESS_MEMORYMANAGMENTUTILS_H
