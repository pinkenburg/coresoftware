#include "DumpMicromegasRawHitContainer.h"

#include <phool/PHIODataNode.h>

#include <ffarawobjects/MicromegasRawHit.h>
#include <ffarawobjects/MicromegasRawHitContainer.h>

#include <ostream>
#include <string>

using MyNode_t = PHIODataNode<MicromegasRawHitContainer>;

DumpMicromegasRawHitContainer::DumpMicromegasRawHitContainer(const std::string &NodeName)
  : DumpObject(NodeName)
{
  return;
}

int DumpMicromegasRawHitContainer::process_Node(PHNode *myNode)
{
  MicromegasRawHitContainer *micromegasrawhitcontainer = nullptr;
  MyNode_t *thisNode = static_cast<MyNode_t *>(myNode);  // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)
  if (thisNode)
  {
    micromegasrawhitcontainer = thisNode->getData();
  }
  if (micromegasrawhitcontainer)
  {
    unsigned int nhits = micromegasrawhitcontainer->get_nhits();
    *fout << "size: " << micromegasrawhitcontainer->get_nhits() << std::endl;
    for (unsigned int ihit = 0; ihit < nhits; ihit++)
    {
      MicromegasRawHit *rawhit = micromegasrawhitcontainer->get_hit(ihit);
      *fout << "bco: " << rawhit->get_bco() << std::endl;
      *fout << "gtm_bco: " << rawhit->get_gtm_bco() << std::endl;
      *fout << "packetid: " << rawhit->get_packetid() << std::endl;
      *fout << "fee: " << rawhit->get_fee() << std::endl;
      *fout << "sampaaddress: " << rawhit->get_sampaaddress() << std::endl;
      *fout << "sampachannel: " << rawhit->get_sampachannel() << std::endl;
      *fout << "sample range: " << rawhit->get_sample_begin() << "," << rawhit->get_sample_end() << std::endl;
      for (auto isamp = rawhit->get_sample_begin(); isamp < rawhit->get_sample_end(); isamp++)
      {
        *fout << "adc[" << isamp << "] =  " << rawhit->get_adc(isamp) << std::endl;
      }
    }
  }
  return 0;
}
