#include "metisoutput.h"
using namespace std;

MetisOutput::MetisOutput(string FileName)
{

    ifstream myfile (FileName);
    string line,temp;

    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            temp=line;
            if(temp.find("#Vertices")!=string::npos){
                temp=temp.substr(temp.find("#Vertices")+11,temp.length());
                NoOfVertices=stoi(temp.substr(0,temp.find(",")));
                temp=line;
            }
            if(temp.find("#Edges")!=string::npos){
                temp=temp.substr(temp.find("#Edges")+8,temp.length());
                NoOfEdges=stoi(temp.substr(0,temp.find(",")));
                temp=line;
            }
            if(temp.find("#Parts")!=string::npos){
                temp=temp.substr(temp.find("#Parts")+8,temp.length());
                NoOfParts=stoi(temp.substr(0,temp.find("\n")));
                temp=line;
            }
            if(temp.find("Edgecut")!=string::npos){
                temp=temp.substr(temp.find("Edgecut")+9,temp.length());
                EdgeCut=stoi(temp.substr(0,temp.find(",")));
                temp=line;
            }
            if(temp.find("communication volume")!=string::npos){
                temp=temp.substr(temp.find("communication volume")+22,temp.length());
                CommunicationVol=stoi(temp.substr(0,temp.find(".")));
                temp=line;
            }
            if(temp.find("constraint #0")!=string::npos){
                temp=temp.substr(temp.find("constraint #0")+16,temp.length());
                MaxImbalance=stof(temp.substr(0,temp.find(" ")));
                temp=line;
            }
        }
        myfile.close();
    }
}


int MetisOutput::GetNoOfVertices() const
{
    return NoOfVertices;
}

int MetisOutput::GetNoOfEdges() const
{
    return NoOfEdges;
}

int MetisOutput::GetNoOfParts() const
{
    return NoOfParts;
}

int MetisOutput::GetEdgeCut() const
{
    return EdgeCut;
}

int MetisOutput::GetCommunicationVol() const
{
    return CommunicationVol;
}

float MetisOutput::GetMaxImbalance() const
{
    return MaxImbalance;
}
