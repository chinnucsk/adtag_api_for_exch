/* 
 * File:   AdTagInfoClass.c++
 * Author: murtaza
 * 
 * Created on May 24, 2013
 */

#include "AdTagInfoClass.h"
#include "rapidjson/include/rapidjson/document.h"
#include <cstdio>
#include <tr1/memory>
#include <typeinfo>

rapidjson::Document document;
std::tr1::shared_ptr<AdTagInfoClass> objAdTag(new AdTagInfoClass());

AdTagInfoClass::AdTagInfoClass()
{
  
}

AdTagInfoClass:: ~AdTagInfoClass(){}
/**
 * This method is used to get the AD Tag info from AdGear API written by Farrukh
 * 
 * @param unsigned long campaign_id
 * @param unsigned long flightId
 * @return string Mark up of the AD Tag
 */
string AdTagInfoClass::getAdTagByCompaintNFlightID(const char* txtResp)
{
    CampaignManagementDataLayer objCMDL(CampaignManagerImplFactory::getInstance());

   // return objCMDL.getFlightDetailsbyFlightId(1234, 905);
    
    //Open the below lines if you r sure that you are getting right response
    
     parseNGetValues(txtResp);
     
     return objCMDL.getFlightDetailsbyFlightId(getCampaignID(), getFlightID());
}//Closing of getAdTagByCompaintNFlightID

/**
 *  Parses the Json and set the Campaign ID and Flight ID
 * @param string jsonTxt
 * @return nothing
 */
void AdTagInfoClass::parseNGetValues(const char* jsonTxt)
{
  //Initialize and parse the RapidJSON object
 
    document.Parse<0>(jsonTxt);
    
    assert(document.IsObject());                // Check the JSON Object found
    
    assert(document.HasMember("campaign_id"));  //Check whether Campaign ID is available
    assert(document["campaign_id"].IsNumber()); // check whether campaign_id is a Number
    assert(document["campaign_id"].IsInt64()); 
    
    //Set Campaign ID
    unsigned long campaign_id =   (unsigned long) document["campaign_id"].GetInt64();
    
    this->setCampaignID(campaign_id);
    
    assert(document.HasMember("flight_id"));  //Check whether Flight ID is available
    assert(document["flight_id"].IsNumber()); // check whether campaign_id is a Number
    assert(document["flight_id"].IsInt64()); 

    //Set Flight ID
    unsigned long flight_id   =   (unsigned long) document["flight_id"].GetInt64();
    
    setFlightID(flight_id);
   
}//Closing of parseNGetValues

/**
 * Property to set Campaign ID
 * @param unsigned long campaign_id
 * @return 
 */

void AdTagInfoClass::setCampaignID(unsigned long campaign_id)
{
  this->campaign_id   = campaign_id;  
}

/**
 * 
 *  Property to get Campaign ID
 * @return 
 */
unsigned long AdTagInfoClass::getCampaignID()
{
  return this->campaign_id;  
}

/**
 *  Property to set Flight ID
 * @param flight_id
 * @return 
 */
void AdTagInfoClass::setFlightID(unsigned long flight_id)
{
    this->flight_id   = flight_id;  
}

/**
 * Property to get Flight ID
 * @return 
 */
unsigned long AdTagInfoClass::getFlightID()
{
  return this->flight_id;  
}

