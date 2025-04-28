#include <LazyOrm/DbVariant.h>
#include <LazyOrm/DbList.h>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>

enum MatchingType {
    Null = 0,
    Bool,
    Int32,
    UInt32,
    Int64,
    UInt64,
    Float,
    Double,
    String,
};

extern "C" {

    void* DbVariant_create(){
        return new LazyOrm::DbVariant{};
    }

    void DbVariant_destroy(void* obj) {
        if (obj != nullptr) {
            delete static_cast<LazyOrm::DbVariant*>(obj);
        }
    }

    void DbVariant_set_null(void* obj) {
        if (obj != nullptr) {
            static_cast<LazyOrm::DbVariant*>(obj)->set("NULL");
        }
    }

    void DbVariant_set_bool(void* obj, const bool value) {
        if (obj != nullptr) {
            static_cast<LazyOrm::DbVariant*>(obj)->set(value);
        }
    }

    void DbVariant_set_string(void* obj, const char* value) {
        if (obj != nullptr) {
            static_cast<LazyOrm::DbVariant*>(obj)->set(std::string(value));
        }
    }

    void DbVariant_set_ull(void* obj, const unsigned long long value) {
        if (obj != nullptr) {
            static_cast<LazyOrm::DbVariant*>(obj)->set(value);
        }
    }

    void DbVariant_set_ll(void* obj, const long long value) {
        if (obj != nullptr) {
            static_cast<LazyOrm::DbVariant*>(obj)->set(value);
        }
    }

    void DbVariant_set_double(void* obj, int typeTag, const double value) {
        if (obj != nullptr) {
            static_cast<LazyOrm::DbVariant*>(obj)->set(value);
        }
    }

    void DbVariant_set_ld(void* obj, int typeTag, const long double value) {
        if (obj != nullptr) {
            static_cast<LazyOrm::DbVariant*>(obj)->set(value);
        }
    }

    void* DbVariant_create_vector(){
        return new std::vector<LazyOrm::DbVariant>{};
    }

    void DbVariant_destroy_vector(void* obj) {
        if (obj != nullptr) {
            delete static_cast<std::vector<LazyOrm::DbVariant>*>(obj);
        }
    }

    void DbVariant_vector_push(void* vector_obj, void* variant_obj) {
        if (vector_obj != nullptr && variant_obj != nullptr) {
            auto variant = static_cast<LazyOrm::DbVariant*>(variant_obj);
            static_cast<std::vector<LazyOrm::DbVariant>*>(vector_obj)->push_back(*variant);
        }
    }

    void DbVariant_vector_pop(void* vector_obj, void* variant_obj) {
        if (vector_obj != nullptr && variant_obj != nullptr) {
            auto variant = static_cast<LazyOrm::DbVariant*>(variant_obj);
            auto variantsVector = static_cast<std::vector<LazyOrm::DbVariant>*>(vector_obj);
            auto it = std::find(variantsVector->begin(), variantsVector->end(), *variant);
            if (it != variantsVector->end()) {
                variantsVector->erase(it);
            }
        }
    }

    void DbVariant_vector_popback(void* vector_obj) {
        if (vector_obj != nullptr) {
            static_cast<std::vector<LazyOrm::DbVariant>*>(vector_obj)->pop_back();
        }
    }


    void* DbList_create(){
        return new LazyOrm::DbList{};
    }

    void DbList_destroy(void* obj) {
        if (obj != nullptr) {
            delete static_cast<LazyOrm::DbList*>(obj);
        }
    }

    void DbList_setList(void* obj, void* vector_obj) {
        if (obj != nullptr && vector_obj != nullptr) {
            auto dbVariantVector = static_cast<std::vector<LazyOrm::DbVariant>*>(vector_obj);
            static_cast<LazyOrm::DbList*>(obj)->setList(*dbVariantVector);
        }
    }

}
