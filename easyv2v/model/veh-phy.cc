#include "veh-phy.h"
#include "ns3/log.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("VehPhy");
NS_OBJECT_ENSURE_REGISTERED(VehPhy);

TypeId VehPhy::GetTypeId(void)
{
	static TypeId tid = TypeId("v2g::VehPhy");
	tid.SetParent<AppModuleBase>();
	tid.SetGroupName("EasyV2V");
	return tid;
}

void VehPhy::Init()
{

}

void VehPhy::Start()
{

}

}//end of namespace ns3