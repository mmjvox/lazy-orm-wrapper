#include <LazyOrm/WhereFilter.h>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <string>

extern "C" {

    void* WhereFilter_create(){
        return new LazyOrm::WhereFilter();
    }

    void WhereFilter_destroy(void* obj) {
        delete static_cast<LazyOrm::WhereFilter*>(obj);
    }

}
