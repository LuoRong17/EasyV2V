#include "vehicle.h"
#include "ns3/log.h"
#include "ns3/simulator.h"
namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("Vehicle");
NS_OBJECT_ENSURE_REGISTERED(Vehicle);

TypeId Vehicle::GetTypeId(void)
{
	static TypeId tid = TypeId("v2g::Vehicle");
	tid.SetParent<Application>();
	tid.SetGroupName("EasyV2V");
	return tid;
}

std::string Vehicle::GetVehID()
{
	return m_vehicleID;
}

void Vehicle::StartApplication()
{
	std::cout << "test........................." << std::endl;
}
}//end of namespace ns3