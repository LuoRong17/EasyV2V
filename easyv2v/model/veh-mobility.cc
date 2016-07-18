#include "veh-mobility.h"
#include "ns3/log.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("VehMobility");
NS_OBJECT_ENSURE_REGISTERED(VehMobility);

TypeId VehMobility::GetTypeId(void)
{
	static TypeId tid = TypeId("v2g::VehMobility");
	tid.SetParent<AppModuleBase>();
	tid.SetGroupName("EasyV2V");
	return tid;
}

void VehMobility::Init()
{

}

void VehMobility::Start()
{

}

}//end of namespace ns3