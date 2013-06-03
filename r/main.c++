/* 
 * File:   main.c++
 * Author: murtaza
 *
 * Created on May 22, 2013, 4:36 PM
 */

#include <cstdlib>
#include <string>
#include <cstdlib>
#include <tr1/memory>
#include <memory>
#include <iostream>
#include <stdio.h>
#include <stdexcept>


#include "redislib/redisclient.h"

#include "motrixi/CampaignManagementDataLayer.h"
#include "motrixi/CampaignManagerImplFactory.h"
#include "AdTagInfoClass.c++"



using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

 /*  CampaignManagementDataLayer objCMDL(CampaignManagerImplFactory::getInstance());
  
  //Add new Campaign 
 
  try {
    string campaignContents_json   =   "{\"campaign_id\": 1234,\"flight_id\": 905, \"number\": 123, \"Ad_tag\": \"Creative Tag\"}";
  
    bool isCampAdded  =   objCMDL.addCampaign(1234, campaignContents_json);
  }
  catch(const std::exception& e) {
       std::cout << "Caught exception: " << e.what() << endl;
 }
   //Add new Flight 
 
  
 string flightContents_json   =   "{\"campaign_id\": 1234,\"flight_id\": 905, \"number\": 123, \"Ad_tagFlight\": \"Creative Tag Of Flight\"}";
  
 objCMDL.addFlight(1234, 905, flightContents_json);

  
  //count << "Hello";
    string resp    =   objCMDL.getFlightDetailsbyFlightId(1234, 905);
    cout << resp << endl;*/
 
  
  //Checking of Parsing and getting the value from Redis Server
  const char * txtResp    =   "{\"campaign_id\": 1234,\"flight_id\": 905}";
  
  string txtAdTagData   =   objAdTag->getAdTagByCompaintNFlightID(txtResp);
  cout << txtAdTagData << endl;
  return 0;
}

