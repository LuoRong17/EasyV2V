#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/vehicle.h"
#include "ns3/mobility-manager.h"
#include "ns3/simulation-singleton.h"
using namespace ns3;


int
main (int argc, char *argv[])
{
  LogComponentEnable ("MobilityManager", LOG_LEVEL_DEBUG);
  std::string file_name = "easyv2v.xml";
  /*Ptr<Vehicle> test_v = CreateObject<Vehicle>();
  test_v->SetStartTime(Seconds(5));

  NodeContainer nc;
  nc.Create(1);
  nc.Get(0)->AddApplication(test_v);*/

  
  /*VehMobilityInfo test_info(50.0/3,25.0/9);
  test_info.SetRun();*/

  MobilityManager *mobility_manager = SimulationSingleton<MobilityManager>::Get();
  mobility_manager->ReadXml(file_name);
  std::vector<VehInitInfo> test_vector = mobility_manager->GetVehInitInfoList();
  std::vector<VehInitInfo>::iterator it = test_vector.begin();
  for (;it != test_vector.end();it++)
    std::cout << *it << std::endl;

  Simulator::Stop(Seconds(20));
  Simulator::Run ();
  Simulator::Destroy ();
  return 0;
}