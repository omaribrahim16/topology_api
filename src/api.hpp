#ifndef TOPOLOGY_API_HPP
#define TOPOLOGY_API_HPP

// #include "my_classes.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>

typedef int Result;
typedef std::string TopologyID;
typedef std::string DeviceID;
typedef std::string NetlistNodeID;

typedef std::vector<TopologyID> TopologyList;
typedef std::vector<DeviceID> DeviceList;

Result readJSON(const char *filename);
Result readJSON(std::string filename);

Result writeJSON(TopologyID id, const char *filename);
Result writeJSON(TopologyID id, std::string filename);

TopologyList queryTopologies();

Result deleteTopology(TopologyID id);
DeviceList queryDevices(TopologyID id);
DeviceList queryDevicesWithNetlistNode(TopologyID id, NetlistNodeID node);



#endif
