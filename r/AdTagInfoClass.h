/* 
 * File:   AdTagInfoClass.h
 * Author: murtaza
 *
 * Created on May 24, 2013
 */

#ifndef ADTAGINFOCLASS_H
#define	ADTAGINFOCLASS_H


#include <cstdlib>
#include <string>
#include <cstdlib>
#include <tr1/memory>
#include <memory>
#include <iostream>


#include "motrixi/CampaignManagementDataLayer.h"
#include "motrixi/CampaignManagerImplFactory.h"
using namespace std;

class AdTagInfoClass {
public:
  AdTagInfoClass();
  //AdTagInfoClass(const AdTagInfoClass& orig);
  virtual ~AdTagInfoClass();
  
  string  getAdTagByCompaintNFlightID(const char* txtResp ) ;
  
  void setCampaignID(unsigned long campaign_id);
  unsigned long getCampaignID();
  
  void setFlightID(unsigned long flight_id);
  unsigned long getFlightID();
  
  
private:
  
  unsigned long campaign_id;
  unsigned long flight_id;
  
  void parseNGetValues(const char* jsonTxt);
};


#endif	/* ADTAGINFOCLASS_H */

