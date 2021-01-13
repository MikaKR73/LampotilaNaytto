#ifndef ajastin_h
#define ajastin_h
#include "Arduino.h"

class ajastin
{
public:
  ajastin(unsigned long JAKSO);
  bool timeIsUp();

private:
  unsigned long _vertailuHetki;
  unsigned long _jaksonPituus;
};

#endif
