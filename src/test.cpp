#include "api.hpp"

using namespace std;

int main()
{
    cout << "Main started" << endl;

    std::string filename, topologyname;
    int response;

    filename = "../../topology.json";
    cout << "Reading JSON file: " << filename << endl;
    response = readJSON(filename);
    cout << "   Response is " << response << endl << endl;

    filename = "../../topology2.json";
    cout << "Reading JSON file: " << filename << endl;
    response = readJSON(filename);
    cout << "   Response is " << response << endl << endl;

    // filename = "../topology2.json";
    // topologyname = "top1";
    // cout << "Writing " << topologyname << " to JSON file: " << filename << endl;
    // response = writeJSON(topologyname, filename);
    // cout << "   Response is " << response << endl << endl;

    filename = "../../topology3.json";
    topologyname = "non_existent_topology";
    cout << "Writing " << topologyname << " to JSON file: " << filename << endl;
    response = writeJSON(topologyname, filename);
    cout << "   Response is " << response << endl << endl;

    TopologyList top_list = queryTopologies();
    cout << "Topologies: " << endl;
    for (auto top : top_list)
    {
        cout << "   " << top << endl;
    }

    topologyname = "top1";
    cout << "Deleting topology " << topologyname << endl;
    response = deleteTopology(topologyname);
    cout << "   Response is " << response << endl << endl;

    top_list = queryTopologies();
    cout << "Topologies: " << endl;
    for (auto top : top_list)
    {
        cout << "   " << top << endl;
    }
    cout << endl;

    DeviceList dev_list = queryDevices("top2");
    cout << "Devices in topology " << "top2" << endl;
    for (auto dev : dev_list)
    {
        cout << "   " << dev << endl;
    }
    cout << endl;

    dev_list = queryDevicesWithNetlistNode("top2", "vss");
    cout << "Devices in topology " << "top2" << " with netlist node " << "vss" << endl;
    for (auto dev : dev_list)
    {
        cout << "   " << dev << endl;
    }

    cout << "Main ended" << endl;

    return 0;
}
