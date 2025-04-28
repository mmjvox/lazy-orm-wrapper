#include <LazyOrm/MariadbLazy.h>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <string>

LazyOrm::Filters castFilterType(const char* filter){

    const auto filterName = std::string(filter);
    auto filtersMap = LazyOrm::DbVariant{}.getFiltersToStringMap();
    auto it = filtersMap.find(filterName);
    if(it!=filtersMap.end()){
        return it->second;
    }
    return LazyOrm::Filters::None;
}

extern "C" {

  void* MariadbLazy_create() {
      return new LazyOrm::MariadbLazy();
  }

  void MariadbLazy_destroy(void* obj) {
      if (obj != nullptr) {
        delete static_cast<LazyOrm::MariadbLazy*>(obj);
      }
      std::cout << __func__ << std::endl;
  }

  void MariadbLazy_setTabeName(void* obj, const char* tabeName) {
      if (obj != nullptr && tabeName != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->setTabeName(std::string(tabeName));
      }
  }

  const char* MariadbLazy_getTabeName(void* obj) {
      if (obj != nullptr) {
          return strdup(static_cast<LazyOrm::MariadbLazy*>(obj)->tabeName().c_str());
      }
      return "";
  }

  void MariadbLazy_setQueryType(void* obj, const int queryType) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->setQueryType( static_cast<LazyOrm::Query>(queryType) );
      }
  }

  void MariadbLazy_setQueryTypeStr(void* obj, const char* queryType) {

      std::map<std::string, int> LazyOrmQuery = {
          {"UNDEFINED", -1},
          {"INIT", 0},
          {"INSERT", 10},
          {"SELECT", 11},
          {"UPDATE", 12},
          {"DELETE", 13},
          {"INSERT_UPDATE", 14},
          {"BULK_INSERT", 15},
          {"INSERT_IGNORE", 16},
          {"BULK_UPDATE", 17}
          // TODO: BATCH_INSERT_UPDATE
      };
      std::string key(queryType);
      auto it = LazyOrmQuery.find(key);
      if (it != LazyOrmQuery.end()) {
          if (obj != nullptr) {
              static_cast<LazyOrm::MariadbLazy*>(obj)->setQueryType( static_cast<LazyOrm::Query>(it->second) );
          }
      }
  }

  void MariadbLazy_setProperty(void* obj, const char* key) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), {});
      }
  }

  void MariadbLazy_setProperty_null(void* obj, const char* key) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), NULL);
      }
  }

  void MariadbLazy_setProperty_bool(void* obj, const char* key, const bool value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
      }
  }

  void MariadbLazy_setProperty_string(void* obj, const char* key, const char* value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
      }
  }

  void MariadbLazy_setProperty_ull(void* obj, const char* key, const unsigned long long value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
      }
  }

  void MariadbLazy_setProperty_ll(void* obj, const char* key, const long long value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
      }
  }

  void MariadbLazy_setProperty_double(void* obj, const char* key, int typeTag, const double value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
      }
  }

  void MariadbLazy_setProperty_ld(void* obj, const char* key, int typeTag, const long double value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->setProperty(std::string(key), value);
      }
  }

  void MariadbLazy_setFiltering_bool(void* obj, const char* key, const bool value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->appendFilter(castFilterType(key), value);
      }
  }

  void MariadbLazy_setFiltering_string(void* obj, const char* key, const char* value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->appendFilter(castFilterType(key), std::string(value));
      }
  }

  void MariadbLazy_setFiltering_ull(void* obj, const char* key, const unsigned long long value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->appendFilter(castFilterType(key), value);
      }
  }

  void MariadbLazy_setFiltering_ll(void* obj, const char* key, const long long value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->appendFilter(castFilterType(key), value);
      }
  }

  void MariadbLazy_setFiltering_double(void* obj, const char* key, int typeTag, const double value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->appendFilter(castFilterType(key), value);
      }
  }

  void MariadbLazy_setFiltering_ld(void* obj, const char* key, int typeTag, const long double value) {
      if (obj != nullptr) {
          static_cast<LazyOrm::MariadbLazy*>(obj)->appendFilter(castFilterType(key), value);
      }
  }

  void MariadbLazy_setWhereFilter(void* obj, void* pushing_obj) {
      if (obj != nullptr && pushing_obj != nullptr) {
          auto pushingWhereFilter = static_cast<LazyOrm::WhereFilter*>(pushing_obj);
          static_cast<LazyOrm::MariadbLazy*>(obj)->setNestedWhere(*pushingWhereFilter);
      }
  }

  const char* MariadbLazy_queryString(void* obj) {
      if (obj != nullptr) {
          return strdup(static_cast<LazyOrm::MariadbLazy*>(obj)->queryString().c_str());
      }
      return "";
  }



}
