#include "key_value_store.h"

std::optional<std::string> KeyValueStore::Get(const std::string &key) {
  auto it = key_value_store_.find(key);

  if (it != key_value_store_.end()) {
    return it->second;
  } else {
    return "[empty_key]";
  }
}

bool KeyValueStore::Put(const std::string &key, const std::string &value) {
  if (key.empty()) {
    return false;
  }
  key_value_store_[key] = value;
  return true;
}

bool KeyValueStore::Del(const std::string &key) {
  auto success = key_value_store_.erase(key);
  return success;
}
