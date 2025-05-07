#include <LazyOrm/WhereFilter.h>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>

extern "C" {

    void* WhereFilter_create(){
        return new LazyOrm::WhereFilter();
    }

    void WhereFilter_destroy(void* obj) {
        if (obj != nullptr) {
            delete static_cast<LazyOrm::WhereFilter*>(obj);
        }
    }

    void WhereFilter_addVarinat(void* whereFilter_obj, void* variant_obj) {
        if (whereFilter_obj != nullptr && variant_obj != nullptr) {
            auto variant = static_cast<LazyOrm::DbVariant*>(variant_obj);
            auto whereFilterObj = static_cast<LazyOrm::WhereFilter*>(whereFilter_obj);
            whereFilterObj->append({*variant});
        }
    }

    void WhereFilter_addVarinatVector(void* whereFilter_obj, void* variant_vector_obj) {
        if (whereFilter_obj != nullptr && variant_vector_obj != nullptr) {
            auto variantVector = static_cast<std::vector<LazyOrm::DbVariant>*>(variant_vector_obj);
            auto whereFilterObj = static_cast<LazyOrm::WhereFilter*>(whereFilter_obj);
            whereFilterObj->append({{*variantVector}});
        }
    }

    void WhereFilter_addWhereFilter(void* whereFilter_obj, void* pushing_obj) {
        if (whereFilter_obj != nullptr && pushing_obj != nullptr) {
            auto pushingWhereFilter = static_cast<LazyOrm::WhereFilter*>(pushing_obj);
            auto whereFilterObj = static_cast<LazyOrm::WhereFilter*>(whereFilter_obj);
            whereFilterObj->setWhereFilterVector( {{*pushingWhereFilter}} );
        }
    }

    const char* WhereFilter_toString(void* obj){
        if (obj != nullptr) {
            return strdup(static_cast<LazyOrm::WhereFilter*>(obj)->toString().c_str());
        }
        return "";
    }

    void* WhereFilter_vector_create(){
        return new std::vector<LazyOrm::WhereFilter>();
    }

    void WhereFilter_vector_destroy(void* obj) {
        if (obj != nullptr) {
            delete static_cast<std::vector<LazyOrm::WhereFilter>*>(obj);
        }
    }


    void WhereFilter_vector_push(void* whereFilter_vector_obj, void* pushing_obj) {
        if (whereFilter_vector_obj != nullptr && pushing_obj != nullptr) {
            auto pushingWhereFilter = static_cast<LazyOrm::WhereFilter*>(pushing_obj);
            static_cast<std::vector<LazyOrm::WhereFilter>*>(whereFilter_vector_obj)->push_back(*pushingWhereFilter);
        }
    }

    void WhereFilter_vector_pop(void* whereFilter_vector_obj, void* pushing_obj) {
        if (whereFilter_vector_obj != nullptr && pushing_obj != nullptr) {
            auto pushingWhereFilter = static_cast<LazyOrm::WhereFilter*>(pushing_obj);
            auto whereFilterVector = static_cast<std::vector<LazyOrm::WhereFilter>*>(whereFilter_vector_obj);
            auto it = std::find(whereFilterVector->begin(), whereFilterVector->end(), *pushingWhereFilter);
            if (it != whereFilterVector->end()) {
                whereFilterVector->erase(it);
            }
        }
    }

    void WhereFilter_vector_popback(void* whereFilter_vector_obj) {
        if (whereFilter_vector_obj != nullptr) {
            static_cast<std::vector<LazyOrm::DbVariant>*>(whereFilter_vector_obj)->pop_back();
        }
    }

    void WhereFilter_addWhereFilterVector(void* whereFilter_obj, void* whereFilter_vector_obj) {
        if (whereFilter_obj != nullptr && whereFilter_vector_obj != nullptr) {
            auto whereFilterVector = static_cast<std::vector<LazyOrm::WhereFilter>*>(whereFilter_vector_obj);
            auto whereFilterObj = static_cast<LazyOrm::WhereFilter*>(whereFilter_obj);
            whereFilterObj->setWhereFilterVector( {*whereFilterVector} );
        }
    }

    // void WhereFilter_appendVariant_null(void* obj, const char* key) {
    //     if (obj != nullptr) {
    //         static_cast<LazyOrm::WhereFilter*>(obj)->append("null");
    //     }
    // }

    // void WhereFilter_appendVariant_bool(void* obj, const char* key, const bool value) {
    //     if (obj != nullptr) {
    //         static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
    //     }
    // }

    // void WhereFilter_appendVariant_string(void* obj, const char* key, const char* value) {
    //     if (obj != nullptr) {
    //         static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
    //     }
    // }

    // void WhereFilter_appendVariant_ull(void* obj, const char* key, const unsigned long long value) {
    //     if (obj != nullptr) {
    //         static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
    //     }
    // }

    // void WhereFilter_appendVariant_ll(void* obj, const char* key, const long long value) {
    //     if (obj != nullptr) {
    //         static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
    //     }
    // }

    // void WhereFilter_appendVariant_double(void* obj, const char* key, int typeTag, const double value) {
    //     if (obj != nullptr) {
    //         static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
    //     }
    // }

    // void WhereFilter_appendVariant_ld(void* obj, const char* key, int typeTag, const long double value) {
    //     if (obj != nullptr) {
    //         static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
    //     }
    // }

}
