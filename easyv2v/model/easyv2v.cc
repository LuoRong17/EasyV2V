/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */

#include "easyv2v.h"
#include "ns3/log.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("EasyV2V");
NS_OBJECT_ENSURE_REGISTERED(AppModuleBase);

TypeId AppModuleBase::GetTypeId(void)
{
	static TypeId tid = TypeId("v2g::AppModuleBase");
	tid.SetParent<Object>();
	tid.SetGroupName("EasyV2V");
	return tid;
}

}//end of namespace ns3

