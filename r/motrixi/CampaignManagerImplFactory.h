#ifndef  __CAMPAIGN_MANAGER_IMPL_FACTORY__
#define  __CAMPAIGN_MANAGER_IMPL_FACTORY__

#pragma once

#include "ICampaignManagerImpl.h"
#include "RedisCampaignManagerImpl.h"

class CampaignManagerImplFactory
{
public:

	 public:
        static ICampaignManagerImpl * getInstance()
        {
            static ICampaignManagerImpl *   instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
			instance =  new RedisCampaignManagerImpl();		
            return (instance);
        }
 private:
        CampaignManagerImplFactory() {};                   // Constructor? (the {} brackets) are needed here.
        // Dont forget to declare these two. You want to make sure they
        // are unaccessable otherwise you may accidently get copies of
        // your singleton appearing.
        CampaignManagerImplFactory(CampaignManagerImplFactory const&);              // Don't Implement
        void operator=(CampaignManagerImplFactory const&); // Don't implement
};
#endif