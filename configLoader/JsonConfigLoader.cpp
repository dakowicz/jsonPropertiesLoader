//
// Created by tomasz on 09.06.16.
//

#include "JsonConfigLoader.h"

int JsonConfigLoader::getInt(std::string key) {
    printKey(key);
    std::queue<std::shared_ptr<Key>> parsedKeys;
    KeyParser keyParser(key, parsedKeys);
    int loadedValue = jsonParser.getInt(parsedKeys);
    printValue(loadedValue);
    return loadedValue;
}

std::string JsonConfigLoader::getString(std::string key) {
    printKey(key);
    std::queue<std::shared_ptr<Key>> parsedKeys;
    KeyParser keyParser(key, parsedKeys);
    std::string loadedValue = jsonParser.getString(parsedKeys);
    printValue(loadedValue);
    return loadedValue;
}

void JsonConfigLoader::printValue(int value) const { std::cout << "Value: " << value << std::endl; }

void JsonConfigLoader::printValue(std::string &value) const { std::cout << "Value: " << value << std::endl; }

void JsonConfigLoader::printKey(const std::string &key) const { std::cout << "Key: " << key << std::endl; }



