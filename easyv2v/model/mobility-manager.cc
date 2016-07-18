#include "mobility-manager.h"
#include "ns3/log.h"
#include "ns3/nstime.h"
#include "ns3/simulator.h"
namespace ns3{

NS_LOG_COMPONENT_DEFINE ("MobilityManager");

VehMobilityInfo::VehMobilityInfo(double maxVeclocity,double acerrlatration):m_isRun(false),m_lastUpdate(0),m_startTime(0),m_firstMaxVeclocityTime(0)
,m_maxVelocity(maxVeclocity),m_acerrlatration(acerrlatration)
,m_currentVelocity(0),m_position(0)
{
	NS_LOG_FUNCTION(this);
}

void VehMobilityInfo::SetRun()
{
	NS_LOG_FUNCTION(this);
	m_isRun = true;
	m_startTime = Simulator::Now();
	m_firstMaxVeclocityTime = m_startTime + Seconds(m_maxVelocity/m_acerrlatration);
	Simulator::Schedule(Seconds(1),&VehMobilityInfo::Update,this);
}

void VehMobilityInfo::Update()
{
	NS_LOG_FUNCTION(this);
	if(!m_isRun) return;
	Time now_time = Simulator::Now();
	if (now_time <= m_firstMaxVeclocityTime)
	{
		Time offset_time = now_time - m_startTime;
		double distant = offset_time.GetSeconds()*offset_time.GetSeconds()*m_acerrlatration/2;
		m_position = distant;
		m_currentVelocity = m_acerrlatration*offset_time.GetSeconds();
	}
	else
	{
		Time speedUp_time = m_firstMaxVeclocityTime - m_startTime;
		double distant_one = speedUp_time.GetSeconds()*speedUp_time.GetSeconds()*m_acerrlatration/2;
		m_currentVelocity = m_maxVelocity;
		Time constVelocity_time = now_time - m_firstMaxVeclocityTime;
		double distant_two = constVelocity_time.GetSeconds()*m_maxVelocity;
		m_position = distant_one + distant_two;
	}
	Simulator::Schedule(Seconds(1),&VehMobilityInfo::Update,this);
	NS_LOG_INFO("Update__time:"<<Simulator::Now().As(Time::S) << ",velocity:" << m_currentVelocity <<"m/s,position:" << m_position<<"m");
}

////////////////////////////////////////////////////////////////////////

VehInitInfo::VehInitInfo(std::string category,double velocity,double acerrlatration,int num)
:m_category(category),m_velocity(velocity),m_acerrlatration(acerrlatration),m_num(num){}

std::ostream & operator << (std::ostream & os, const VehInitInfo & info)
{
	os<<"category:"<<info.m_category;
	os<<"velocity:"<<info.m_velocity;
	os<<"acerrlatration:"<<info.m_acerrlatration;
	os<<"num"<<info.m_num;
	return os;
}
/////////////////////////////////////////////////////////////////////////

void MobilityManager::VehInformStartRun(const std::string& vehID)
{
	NS_LOG_FUNCTION(this);
}

std::vector<VehInitInfo> MobilityManager::GetVehInitInfoList()
{
	return m_vehInitInfoList;
}

void MobilityManager::ReadXml(std::string file_name)
{
	NS_LOG_FUNCTION(file_name);
	file<> fdoc(file_name.data());
	NS_LOG_DEBUG(fdoc.data());
	xml_document<> doc;
	doc.parse<0>(fdoc.data());

	xml_node<> *root = doc.first_node();

	xml_node<> *category_node = root->first_node("CATEGORY");
	
	while(category_node)
	{
		std::string category_id = category_node->value();
		NS_LOG_DEBUG(category_node->name() << ":" << category_id);
		
		xml_node<> *velocity_node = category_node->first_node("VELOCITY");	
		NS_LOG_DEBUG(velocity_node->name() << "  "  <<  velocity_node->value());
		double velocity = atof(velocity_node->value());
		velocity = velocity*1000/3600;//trans unit from km/h to m/s

		xml_node<> *acerrlatration_node = category_node->first_node("ACERRLATRATION");	
		NS_LOG_DEBUG(acerrlatration_node->name() << "  "  << acerrlatration_node->value());
		double acerrlatration = atof(acerrlatration_node->value());
		acerrlatration = 100*1000/3600/acerrlatration;//trans it to m/s2

		xml_node<> *num_node = category_node->first_node("NUM");	
		NS_LOG_DEBUG(num_node->name() << "  "  << num_node->value());
		int num = atoi(num_node->value());

		VehInitInfo temp_info(category_id,velocity,acerrlatration,num);
		m_vehInitInfoList.push_back(temp_info);
		category_node = category_node->next_sibling("CATEGORY");
	}
}

}//ns3