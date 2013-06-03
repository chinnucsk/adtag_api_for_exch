#ifndef  __CAMPAIGN_MANAGEMENT_DATA_LAYER__
#define  __CAMPAIGN_MANAGEMENT_DATA_LAYER__

#pragma once
#include "ICampaignManagerImpl.h"
class CampaignManagementDataLayer
{
	private:
		ICampaignManagerImpl * p_impl;


	public:
		CampaignManagementDataLayer(ICampaignManagerImpl  * impl)
	{
		if(impl!=NULL)
			this->p_impl = impl;
		else
			throw "NULL pointer was passed to CampaignManagementDataLayer constructor";
	}



	~CampaignManagementDataLayer(void)
	{
		delete p_impl; p_impl=NULL;
	}
 
  	bool addFlight(unsigned long campaign_id, unsigned long flightId, string flightContents_json){
  		if(this->p_impl->addFlight( campaign_id, flightId,  flightContents_json))
  			return true;
  		else
  			//throw ("could not add the flight.");
  		return false;
  }
	 bool removeFlight(unsigned long campaign_id, unsigned long flightId){
	 	if(this->p_impl->removeFlight( campaign_id, flightId))
  			return true;
  		else
  			throw ("could not remove the flight.");
  		return false;
	 }
	 bool updateFlight(unsigned long campaign_id, unsigned long flightId, string flightContents_json){
	 	if(this->p_impl->updateFlight( campaign_id, flightId,  flightContents_json))
  			return true;
  		else
  			//throw ("could not update the flight.");
  		return false;
	 }
	 bool pauseCampaign(unsigned long campaign_id){
	 	if(this->p_impl->pauseCampaign(campaign_id))
  			return true;
  		else
  			//throw ("campaign could not be paused, probably it does not exist in the records.");
  		return false;
	 }
	 bool resumeCampaign(unsigned long campaign_id){
	 	if(this->p_impl->resumeCampaign(campaign_id))
  			return true;
  		else
  			//throw ("campaign could not be paused, probably it does not exist in the records.");
  		return false;
	 }
	 bool addCampaign(unsigned long campaign_id, string campaignContents_json){
	 	if(this->p_impl->addCampaign(campaign_id, campaignContents_json))
  			return true;
  		else
  			//throw ("could not add the campaign. probably because it does not exists in records");
  		return false;

	 }
	 bool removeCampaign(unsigned long campaign_id)
	 {
	 	if(this->p_impl->removeCampaign( campaign_id))
  			return true;
  		else
  			//throw ("could not remove the campaign. probably because it does not exists in records");
  		return false;
	 }
     
	 string getFlightDetailsbyFlightId(unsigned long campaign_id, unsigned long flightId)
	 {
		return this->p_impl->getFlightDetailsbyFlightId( campaign_id, flightId);
  			
	 }
	void test()
	{

	//	this->p_impl->test();
	}

};

#endif