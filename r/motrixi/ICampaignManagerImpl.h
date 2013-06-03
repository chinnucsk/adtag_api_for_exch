#ifndef __I_CAMPAIGN_MANAGER_IMPL__
#define __I_CAMPAIGN_MANAGER_IMPL__
#pragma once
#include <string>
using namespace std;
class ICampaignManagerImpl
{
public:
	virtual bool addFlight(unsigned long campaign_id, unsigned long flightId, string flightContents_json)=0;
	virtual bool removeFlight(unsigned long campaign_id, unsigned long flightId)=0;
	virtual bool updateFlight(unsigned long campaign_id, unsigned long flightId, string flightContents_json)=0;
	virtual bool pauseCampaign(unsigned long campaign_id)=0;
	virtual bool resumeCampaign(unsigned long campaign_id)=0;
	virtual bool addCampaign(unsigned long campaign_id, string campaignContents_json)=0;
	virtual bool removeCampaign(unsigned long campaign_id)=0;
	virtual string getFlightDetailsbyFlightId(unsigned long campaign_id, unsigned long flightId)=0;
	
};

#endif