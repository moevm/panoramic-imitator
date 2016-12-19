#ifndef GETPBDATA_H
#define GETPBDATA_H

#include <iostream>
#include <fstream>
#include "data_structures.h"
#include "protobuf/panoramic-imitator-message.pb.h"

class GetPBData
{
public:
    GetPBData();
    bool readData();
    bool writeData();
    Angles getAngles();
    void setAngles(Angles angles);
private:
    bool parseMSGFromFile();
    void anglesShortener();
    panoramicImitator::Message message;
    Angles angles;
};

#endif // GETPBDATA_H
