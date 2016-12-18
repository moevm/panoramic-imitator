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
    Angles getAngles();
    Frame getFrame();

private:
    bool parseMSGFromFile();
    panoramicImitator::Message message;
    Angles angles;
    Frame frame;
};

#endif // GETPBDATA_H
