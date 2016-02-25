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
private:
    int NoOfVertices;
    int NoOfEdges;
    int NoOfParts;
    int EdgeCut;
    int CommunicationVol;
    float MaxImbalance;

};

#endif // METISOUTPUT_H
