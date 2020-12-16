#ifndef SM_8mosfet_h
#define SM_8mosfet_h
#include "Arduino.h"
#include <inttypes.h>

class SM_8mosfet
{
  public:
    SM_8mosfet();
    uint8_t begin(uint8_t);
    uint8_t begin();
    uint8_t writeChannel(uint8_t, uint8_t);
    uint8_t writeChannel(int, int);
    uint8_t readChannel(uint8_t);
    uint8_t writeAll(uint8_t);
    uint8_t readAll();
     
    inline uint8_t readChannel(int channel) { return readChannel((uint8_t)channel); }
    inline uint8_t writeAll(int val) { return writeAll((uint8_t)val); }
  private:
    uint8_t _hwAdd;
    uint8_t rawRead(uint8_t *val);
    uint8_t rawWrite(uint8_t val);
};

#endif
