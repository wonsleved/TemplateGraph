#ifndef LAB3_UNIQUEID_H
#define LAB3_UNIQUEID_H

#include <cinttypes>

typedef uint64_t ID;

ID static getNewId() {
    static ID id = 0;
    return id++;
}

#endif
