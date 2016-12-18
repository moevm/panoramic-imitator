#include "getpbdata.h"

using namespace std;

GetPBData::GetPBData()
{

}

bool GetPBData::parseMSGFromFile()
{
    fstream input("lol", ios::in | ios::binary);
    if (!message.ParseFromIstream(&input))
    {
        cerr << "Failed to parse address book." << endl;
        return -1;
    }
    return 0;
}

bool GetPBData::readData()
{
    if (!parseMSGFromFile())
    {
        angles.horAngle = message.horangle();
        angles.vertAngle = message.vertangle();
        if (message.has_frameheight() && message.has_framewidth())
        {
            frame.height = message.frameheight();
            frame.width = message.framewidth();
        }
    }
}

Angles GetPBData::getAngles()
{
    return angles;
}
Frame GetPBData::getFrame()
{
    if (message.has_frameheight() && message.has_framewidth())
    {
        return frame;
    }
}
