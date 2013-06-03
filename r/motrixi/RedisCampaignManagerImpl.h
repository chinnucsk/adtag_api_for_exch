#ifndef __REDIS_CAMPAIGN_MANAGER__
#define  __REDIS_CAMPAIGN_MANAGER__
#pragma once
#include "ICampaignManagerImpl.h"
#include "../redislib/redisclient.h"
#include <sstream>


class RedisCampaignManagerImpl :
	public ICampaignManagerImpl
{
private:
	boost::shared_ptr<redis::client> redis_client;
	boost::shared_ptr<redis::client> init_connection()
	{
		  const char* c_host = getenv("REDIS_HOST");
            string host = "54.214.232.60";
		//  if(c_host)
		 //   host = c_host;
		  return boost::shared_ptr<redis::client>( new redis::client(host) );
	}

	string long_to_string(unsigned long number)
	{
		std::string str_number;
		std::stringstream strstream;
		strstream << number;
		strstream >> str_number;
		return str_number;
	}

	bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
	}


public:

RedisCampaignManagerImpl(void)
{
	this->redis_client = init_connection();
}


~RedisCampaignManagerImpl(void)
{

}


bool addFlight(unsigned long campaign_id, unsigned long flightId, string flightContents_json)
{
	redis::client & c = *redis_client;

	std::string str_campaign,str_flight;

	str_campaign = long_to_string(campaign_id);
	str_campaign = "C-"+str_campaign;

	str_flight = long_to_string(flightId);
	str_flight = "F-"+str_flight;

	bool retval = c.hset(str_campaign, str_flight, flightContents_json);

	return retval;
}
bool removeFlight(unsigned long campaign_id, unsigned long flightId)
{

	redis::client & c = *redis_client;

	std::string str_campaign,str_flight;

	str_campaign = long_to_string(campaign_id);
	str_campaign = "C-"+str_campaign;

	str_flight = long_to_string(flightId);
	str_flight = "F-"+str_flight;

	bool retval=false; 
	if(c.hexists(str_campaign, str_flight))
		retval = c.hdel(str_campaign, str_flight);

	return retval;

}
bool updateFlight(unsigned long campaign_id, unsigned long flightId, string flightContents_json)
{
	
	redis::client & c = *redis_client;

	std::string str_campaign,str_flight;

	str_campaign = long_to_string(campaign_id);
	str_campaign = "C-"+str_campaign;

	str_flight = long_to_string(flightId);
	str_flight = "F-"+str_flight;

	bool retval=false; 
	if(c.hexists(str_campaign, str_flight))
		retval = c.hset(str_campaign, str_flight, flightContents_json);
	

	return retval;

}
bool pauseCampaign(unsigned long campaign_id)
{
	
	redis::client & c = *redis_client;

	std::string str_campaign;

	str_campaign = long_to_string(campaign_id);
	str_campaign = "C-"+str_campaign;



	bool retval=false; 
	if(c.hexists(str_campaign, "data"))
	{
		string data = c.hget(str_campaign, "data");
		replace(data,"\"status\":\"ACTIVE\"","\"status\":\"PAUSED\"");		
		retval = c.hset(str_campaign, "data", data);
	}	
	return retval;
}
bool resumeCampaign(unsigned long campaign_id)
{
	redis::client & c = *redis_client;

	std::string str_campaign;

	str_campaign = long_to_string(campaign_id);
	str_campaign = "C-"+str_campaign;



	bool retval=false; 
	if(c.hexists(str_campaign, "data"))
	{
		string data = c.hget(str_campaign, "data");
		replace(data,"\"status\":\"PAUSED\"","\"status\":\"ACTIVE\"");		
		retval = c.hset(str_campaign, "data", data);
	}	
	return retval;
}

bool addCampaign(unsigned long campaign_id, string campaignContents_json)
{
	redis::client & c = *redis_client;

	std::string str_campaign,str_flight;

	str_campaign = long_to_string(campaign_id);
	str_campaign = "C-"+str_campaign;
	
	bool retval = c.hset(str_campaign, "data", campaignContents_json);

	return retval;	
}
bool removeCampaign(unsigned long campaign_id)
{
	 redis::client & c = *redis_client;

	std::string str_campaign,str_flight;

	str_campaign = long_to_string(campaign_id);
	str_campaign = "C-"+str_campaign;

	bool retval=false; 
	if(c.hexists(str_campaign, "data"))
	{
		redis::client::string_pair_vector entries;
    	c.hgetall(str_campaign, entries);
    	for(uint i=0;i<entries.size();i++)
    	{
    		str_flight = entries[i].first;
    		if(!c.hdel(str_campaign,str_flight))
    			return retval;
    	}
    	retval = true;

    }
    return retval;
}
string getFlightDetailsbyFlightId(unsigned long campaign_id, unsigned long flightId)
{
	redis::client & c = *redis_client;

	std::string str_campaign,str_flight;

	str_campaign = long_to_string(campaign_id);
	str_campaign = "C-"+str_campaign;

	str_flight = long_to_string(flightId);
	str_flight = "F-"+str_flight;
	string flightContents_json("");
	if(c.hexists(str_campaign, str_flight))
		flightContents_json = c.hget(str_campaign, str_flight);
	
	return flightContents_json;

	

}






};

#endif