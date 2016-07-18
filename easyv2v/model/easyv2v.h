/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
#ifndef EASYV2V_H
#define EASYV2V_H
#include "ns3/object.h"

namespace ns3 {

class AppModuleBase:public Object
{
public:
	static TypeId GetTypeId (void);
protected:
	virtual void Init()=0;
	virtual void Start()=0;
};

}

#endif /* EASYV2V_H */

