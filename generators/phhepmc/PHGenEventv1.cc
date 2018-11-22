#include "PHGenEventv1.h"

#include <HepMC/GenEvent.h>

#include <sstream>

ClassImp(PHGenEventv1)

using namespace std;

PHGenEventv1::PHGenEventv1()
  : _id(0),
    _event(nullptr)
{}

PHGenEventv1::PHGenEventv1(const unsigned int id, HepMC::GenEvent& event)
   : _id(id),
     _event(nullptr) {  
   set_event(event);
 }

PHGenEventv1::PHGenEventv1(const PHGenEventv1& phevent)
   : _id(phevent.get_id()),
     _event(nullptr)
{}

PHGenEventv1::PHGenEventv1(const PHGenEventv1* phevent)
   : _id(phevent->get_id()),
     _event(NULL)
{}

PHGenEventv1::~PHGenEventv1() {
  delete _event;  
}

void PHGenEventv1::set_event(HepMC::GenEvent& event) {

  *_event = event;
}

void PHGenEventv1::set_event(HepMC::GenEvent* event) {

  _event = event;
}

size_t PHGenEventv1::particles_size() const {
  return _event->particles_size();
}

size_t PHGenEventv1::vertices_size() const {
  return _event->vertices_size();
}

void PHGenEventv1::Reset() {
  _id = 0;
    delete _event;
    _event = nullptr;
}

void PHGenEventv1::print(std::ostream& out) const {
  identify(out);
  out << " id = " << _id << endl;
//  _event->print(out);
}

