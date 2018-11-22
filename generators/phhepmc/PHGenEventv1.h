#ifndef PHGENEVENTV1_H
#define PHGENEVENTV1_H

#include "PHGenEvent.h"

#include <phool/phool.h>
#include <phool/PHObject.h>

#include <HepMC/GenEvent.h>


class PHGenEventv1 : public PHGenEvent {
  
 public:

  PHGenEventv1();
  PHGenEventv1(const unsigned int id, HepMC::GenEvent &event);
  PHGenEventv1(const PHGenEventv1& phevent);
  PHGenEventv1(const PHGenEventv1* phevent);  
  virtual ~PHGenEventv1();

  const HepMC::GenEvent* get_event() const {return _event;}
//  HepMC::GenEvent* get_event() {return _event;}
  void set_event(HepMC::GenEvent &event);
  void set_event(HepMC::GenEvent* event);

  unsigned int get_id() const {return _id;}
  void set_id(const unsigned int id) {_id = id;}

  // the number of entries in the array of particles
  size_t particles_size() const;
  size_t vertices_size() const;

  // PHObject interface
  void identify(std::ostream& out = std::cout) const {
    out << "PHGenEventv1" << std::endl;
  }
  void print(std::ostream& out = std::cout) const;
  void Reset();
  
private:

  // a unique id to aid in tracing merged events (multiple container entries) 
  unsigned int _id;

  // the ASCII event record of the HepMC event (ROOT responsible for compression)
  // this reduces the central event storage requirement by 41% (Bzip2 achieves 32%)
  // a 2nd version of this class could possibly do better by storing the
  // vertices and particles in classes of their own and rebuilding the HepMC
  // from there. This might make better use of space and ROOT compression.

  HepMC::GenEvent* _event;
  
  ClassDef(PHGenEventv1,1)    
};

#endif
