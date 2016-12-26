#ifndef PBDATA_H
#define PBDATA_H

#include <iostream>
#include <fstream>
#include "data_structures.h"
#include "src/protobuf/panoramic-imitator-message.pb.h"

class PBData
{
public:
    PBData();
    bool readData();
    bool writeData();
    Angles getAngles();
    void setAngles(Angles angles);
private:
    bool parseMSGFromFile();
    panoramicImitator::Message message;
    Angles angles;
    void anglesShortener();
};

#endif // PBDATA_H
