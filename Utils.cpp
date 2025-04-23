#include <LazyOrm/DbVariant.h>
#include <LazyOrm/AbstractLazy.h>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include <iomanip>

extern "C" {

int myFunction(int a, int b) {
    return a + b;
}

const char *libVersion() {
    return LazyOrm::AbstractLazy::version;
}

const char *wrapperVersion() {
    return wrapper_version;
}

void freeString(const char* str) {
    free((void*)str);
}

volatile const double doubleSend(volatile const double d){
    return d;
}

const long long int64Send(const long long d){
    return d;
}

}
