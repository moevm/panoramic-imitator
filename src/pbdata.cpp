#include "inc/pbdata.h"

using namespace std;

PBData::PBData()
{
    angles.horAngle = 0;
    angles.vertAngle = 0;
}
void PBData::setAngles(Angles angles)
{
    this->angles.horAngle = angles.horAngle;
    this->angles.vertAngle = angles.vertAngle;
    anglesShortener();
}

bool PBData::parseMSGFromFile()
{
    fstream input("angles", ios::in | ios::binary);
    if (!message.ParseFromIstream(&input))
    {
        cerr << "Failed to parse message" << endl;
        return 1;
    }
    return 0;
}
bool PBData::readData()
{
    if (!parseMSGFromFile())
    {
        if (message.has_horangle()) {angles.horAngle = message.horangle();}
        if (message.has_vertangle()){angles.vertAngle = message.vertangle();}
        return 0;
    }
    return 1;
}
bool PBData::writeData()
{
    message.set_horangle(angles.horAngle);
    message.set_vertangle(angles.vertAngle);

    fstream output("angles", ios::out | ios::trunc | ios::binary);
    if (!message.SerializeToOstream(&output))
    {
        cerr << "Failed to write message" << endl;
        return 1;
    }
    return 0;
}
void PBData::anglesShortener()
{
    while(angles.vertAngle<0)
        angles.vertAngle+=360;
    while(angles.vertAngle>180)
        angles.vertAngle-=360;
    while(angles.horAngle<-180)
        angles.horAngle+=360;
    while(angles.horAngle>180)
        angles.horAngle-=360;
}
Angles PBData::getAngles()
{
    anglesShortener();
    return angles;
}
