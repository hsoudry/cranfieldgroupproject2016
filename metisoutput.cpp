#include "metisoutput.h"
using namespace std;

MetisOutput::MetisOutput(string FileName, string name)
{

    ifstream myfile (FileName);
    string line,temp;

    Name = name;

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
            if(temp.find("ptype")!=string::npos){
                temp=temp.substr(temp.find("ptype=")+6,temp.length());
                ptype=temp.substr(0,temp.find(","));
                temp=line;

                temp=temp.substr(temp.find("objtype=")+8,temp.length());
                objtype=temp.substr(0,temp.find(","));
                temp=line;

                temp=temp.substr(temp.find("ctype=")+6,temp.length());
                ctype=temp.substr(0,temp.find(","));
                temp=line;

                temp=temp.substr(temp.find("iptype=")+7,temp.length());
                iptype=temp.substr(0,temp.find("\n"));
            }
        }
        myfile.close();
    }
}

string MetisOutput::GetName() const
{
    return Name;
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

string MetisOutput::GetPtype() const
{
    return ptype;
}

string MetisOutput::GetObjtype() const
{
    return objtype;
}

string MetisOutput::GetCtype() const
{
    return ctype;
}

string MetisOutput::GetIptype() const
{
    return iptype;
}
