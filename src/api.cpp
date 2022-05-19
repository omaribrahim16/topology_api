#include "api.hpp"

// using namespace std;
using std::cout;
std::vector<Json::Value> __TOPOLOGIES__;


Result readJSON(const char *filename)
{
  std::ifstream file(filename);
  Json::Value top_val;
  Json::Reader read;

  if (!read.parse(file, top_val))
  {
    cout << "Failed to parse JSON file\n";
    return 1;
  }

  __TOPOLOGIES__.push_back(top_val);

  cout << "Parsed and stored JSON topology successfully\n";

  return 0;
}
Result readJSON(std::string filename)
{
  return readJSON(filename.c_str());
}


Result writeJSON(TopologyID id, const char *filename)
{
  for (auto top : __TOPOLOGIES__)
  {
    if (top["id"].asString() == id)
    {
      std::ofstream file(filename);
      Json::StyledStreamWriter writer;

      writer.write(file, top);
      file.close();

      cout << "Wrote JSON topology successfully\n";
      return 0;
    }
  }

  cout << "Could not find topology with id " << id << std::endl;
  return 1;
}
Result writeJSON(TopologyID id, std::string filename)
{
  return writeJSON(id, filename.c_str());
}


TopologyList queryTopologies()
{
  TopologyList top_list;

  for (auto top : __TOPOLOGIES__)
  {
    top_list.push_back(top["id"].asString());
  }

  return top_list;
}


Result deleteTopology(TopologyID id)
{
  for (int i = 0; i < __TOPOLOGIES__.size(); i++)
  {
    if (__TOPOLOGIES__[i]["id"].asString() == id)
    {
      __TOPOLOGIES__.erase(__TOPOLOGIES__.begin() + i);
      cout << "Deleted topology with id " << id << std::endl;
      return 0;
    }
  }

  cout << "Could not find topology with id " << id << std::endl;
  return 1;
}


DeviceList queryDevices(TopologyID id)
{
  DeviceList dev_list;

  for (auto top : __TOPOLOGIES__)
  {
    if (top["id"].asString() == id)
    {
      for (auto dev : top["components"])
      {
        dev_list.push_back(dev["id"].asString());
      }
      return dev_list;
    }
  }

  cout << "Could not find topology with id " << id << std::endl;
  return dev_list;
}


DeviceList queryDevicesWithNetlistNode(TopologyID id, NetlistNodeID node)
{
  DeviceList dev_list;

  for (auto top : __TOPOLOGIES__)
  {
    if (top["id"].asString() == id)
    {
      for (auto dev : top["components"])
      {
        for (auto netlist_key : dev["netlist"].getMemberNames())
        {
          if (dev["netlist"][netlist_key].asString() == node)
          {
            dev_list.push_back(dev["id"].asString());
            break;
          }
        }
      }
      return dev_list;
    }
  }

  cout << "Could not find topology with id " << id << std::endl;
  return dev_list;
}

