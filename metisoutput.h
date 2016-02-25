#ifndef METISOUTPUT_H
#define METISOUTPUT_H
#include <string>
#include <fstream>
#include <iostream>
class MetisOutput
{
public:
    MetisOutput(std::string FileName);
    int GetNoOfVertices() const;
    int GetNoOfEdges() const;
    int GetNoOfParts() const;
    int GetEdgeCut() const;
    int GetCommunicationVol() const ;
    float GetMaxImbalance() const;
    std::string GetPtype() const;
    std::string GetObjtype() const;
    std::string GetCtype() const;
    std::string GetIptype() const;
private:
    int NoOfVertices;
    int NoOfEdges;
    int NoOfParts;
    int EdgeCut;
    int CommunicationVol;
    float MaxImbalance;
    std::string ptype;
    std::string objtype;
    std::string ctype;
    std::string iptype;


};

#endif // METISOUTPUT_H
