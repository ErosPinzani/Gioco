//
// Created by erosp on 08/06/2021.
//

#ifndef GAME_H_RESOURCEHOLDER_H
#define GAME_H_RESOURCEHOLDER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <memory>
#include <stdexcept>
#include <cassert>

template <typename Resource, typename Identifier>
class ResourceHolder {
public:
    Resource& get(Identifier id) {
        auto found = mResourceMap.find(id);
        assert(found != mResourceMap.end());

        return *found->second;
    }

    const Resource& get(Identifier id) const {

        auto found = mResourceMap.find(id);
        assert(found != mResourceMap.end());

        return *found->second;
    }

    void load(Identifier id, const std::string& filename) {

        // Create and load resource
        std::unique_ptr<Resource> resource(new Resource());
        if (!resource->loadFromFile(filename))
            throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);

        // If loading successful, insert resource to map
        insertResource(id, std::move(resource));
    }

    template <typename Parameter>
    void load(Identifier id, const std::string& filename, const Parameter& secondParam) {
        std::unique_ptr<Resource> resource(new Resource());
        if (!resource->loadFromFile(filename, secondParam))
            throw std::runtime_error("ResourceHolder::load - Failed to load "+ filename);

        insertResource(id, std::move(resource));
    }

private:
    void insertResource(Identifier id, std::unique_ptr<Resource> resource) {

        auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
        //checks if the texture is actually loaded, it fails if it was already loaded
        assert(inserted.second);
    }

    std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

#endif //GAME_H_RESOURCEHOLDER_H
