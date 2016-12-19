#include "getpbdata.h"

using namespace std;

GetPBData::GetPBData()
{
    angles.horAngle = 0;
    angles.vertAngle = 0;
}
void GetPBData::setAngles(Angles angles)
{
    this->angles.horAngle = angles.horAngle;
    this->angles.vertAngle = angles.vertAngle;
}

bool GetPBData::parseMSGFromFile()
{
    fstream input("angles", ios::in | ios::binary);
    if (!message.ParseFromIstream(&input))
    {
        cerr << "Failed to parse message" << endl;
        return 1;
    }
    return 0;
}

bool GetPBData::readData()
{
    if (!parseMSGFromFile())
    {
        if (message.has_horangle()) {angles.horAngle = message.horangle();}
        if (message.has_vertangle()){angles.vertAngle = message.vertangle();}
        return 0;
    }
    return 1;
}
bool GetPBData::writeData()
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
void GetPBData::anglesShortener()
{
    if (angles.vertAngle < -360.0 || angles.vertAngle > 360.0)
        angles.vertAngle = angles.vertAngle - (angles.vertAngle / 360.0) * 360.0;
    if (angles.horAngle < -360.0 || angles.horAngle > 360.0)
        angles.horAngle = angles.horAngle - (angles.horAngle / 360.0) * 360.0;
}

Angles GetPBData::getAngles()
{
    anglesShortener();
    return angles;
}
