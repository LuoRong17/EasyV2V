#include "veh-mac.h"
#include "ns3/log.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("VehMac");
NS_OBJECT_ENSURE_REGISTERED(VehMac);

TypeId VehMac::GetTypeId(void)
{
	static TypeId tid = TypeId("v2g::VehMac");
	tid.SetParent<AppModuleBase>();
	tid.SetGroupName("EasyV2V");
	return tid;
}

void VehMac::Init()
{

}

void VehMac::Start()
{

}

}//end of namespace ns3