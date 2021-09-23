//
// Created by yacopsae on 17/09/2021.
//

#pragma once

#include <string>
#include <map>

template <typename Resource, typename Identifier>
class ResourceManager {

 public:

  ResourceManager(std::string resourcePath);

  virtual Resource* getResource(Identifier resourceId) {
	return resMap.find(resourceId);
  }

 protected:
  virtual void loadResource() = 0;

 private:
  std::map<Identifier, Resource*> resMap;

};


