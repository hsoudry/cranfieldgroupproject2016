#include "graphpart.h"

/*
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream
*/
using namespace std;

GraphPart::GraphPart()
{
    inputType = graph;
    drawable = true;
    graphloaded = false;
    NoOfPartitions=2;
    srand(time(NULL));
    //checkIfDrawable();
    //GraphColoring();

}

bool GraphPart::isDrawable()
{
    return drawable;
}

bool GraphPart::GraphIsLoaded()
{
    return graphloaded;
}

void GraphPart::checkIfDrawable()
{
    ifstream myfile(path_input);
    string temp;
    getline(myfile, temp);
    temp=temp.substr(0,temp.find(" "));

    if(stoi(temp) > 100000)
        drawable = false;
    else
        drawable = true;

}

void GraphPart::setInputFileName(string filename)
{
    path_input = filename;
}

void GraphPart::setNumberOfPart(int noOfPartitions)
{
    NoOfPartitions = noOfPartitions;
}

void GraphPart::mesh2graph()
{
    //PARTITIONING
    string MetisCommand="m2gmetis ";

    MetisCommand += path_input;
    MetisCommand += " ";
    path_input+=".graph";
    MetisCommand += path_input;
    system(MetisCommand.c_str());
}

void GraphPart::extractName()
{
    if(path_input.find("/") != string::npos)
        input_filename = path_input.substr(path_input.find_last_of("/")+1,path_input.length());
    else
        input_filename = path_input;
}

void GraphPart::Partition()
{
    if(inputType == mesh)
        mesh2graph();

    //PARTITIONING
    string MetisCommand="gpmetis ";
    MetisCommand+=metisParams;
    MetisCommand+=path_input;
    MetisCommand+=" ";
    MetisCommand+= to_string(NoOfPartitions);
    MetisCommand+=" > " + path_metisOut;
    system(MetisCommand.c_str());
}

void GraphPart::SvgPrepare()
{
    //DRAWING
    string GraphModCommand="ipython3 -c 'import graph_mod; graph_mod.raw_to_svg(\"";
    GraphModCommand=GraphModCommand+path_input+"\",\"" + path_uncolored + "\",progress=False)'";
    system(GraphModCommand.c_str());
    graphloaded= true;

}

void GraphPart::addMetisParameters(string params)
{
    metisParams=params;
}

string GraphPart::getPathUncolored()
{
    return path_uncolored;
}

string GraphPart::getPathColored()
{
    return path_colored;
}

rgb GraphPart::hsv2rgb(hsv in)
{
    double      hh, p, q, t, ff;
    long        i;
    rgb         out;

    if(in.s <= 0.0) {       // < is bogus, just shuts up warnings
        out.r = in.v;
        out.g = in.v;
        out.b = in.v;
        return out;
    }
    hh = in.h;
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = in.v * (1.0 - in.s);
    q = in.v * (1.0 - (in.s * ff));
    t = in.v * (1.0 - (in.s * (1.0 - ff)));

    switch(i) {
    case 0:
        out.r = in.v;
        out.g = t;
        out.b = p;
        break;
    case 1:
        out.r = q;
        out.g = in.v;
        out.b = p;
        break;
    case 2:
        out.r = p;
        out.g = in.v;
        out.b = t;
        break;

    case 3:
        out.r = p;
        out.g = q;
        out.b = in.v;
        break;
    case 4:
        out.r = t;
        out.g = p;
        out.b = in.v;
        break;
    case 5:
    default:
        out.r = in.v;
        out.g = p;
        out.b = q;
        break;
    }
    return out;
}

void GraphPart::GraphColoring(){
    string partitionFileName=path_input+".part."+to_string(NoOfPartitions);
    string line;
    ifstream myfile (path_uncolored);
    ifstream colors (partitionFileName);
    ofstream newfile (path_colored);
    vector <int> colorVec;
    if (colors.is_open())
    {
        while ( getline (colors,line) )
        {
            colorVec.push_back(stoi(line));
        }
    }
    colors.close();
    int id=1;

    if (myfile.is_open())
    {
        vector <int> colorRnd;
        for (int i=0;i<NoOfPartitions;i++) colorRnd.push_back(i);
        random_shuffle(colorRnd.begin(),colorRnd.end());
        while ( getline (myfile,line) )
        {
            if(line.find("node"+std::to_string(id))!=string::npos){
                newfile << line<<"\n";
                getline (myfile,line);
                int pos=line.find("l=\"#");
                stringstream color;
                int partNo=colorVec.at(id-1);

                float H=float(colorRnd.at(partNo))/float(NoOfPartitions);

                hsv hsvCol;
                rgb rgbCol;
                hsvCol.h=H*360;
                hsvCol.s=0.9;
                hsvCol.v=0.9;

                rgbCol=hsv2rgb(hsvCol);
                color<<std::hex<<int(rgbCol.r*255)<<int(rgbCol.g*255)<<int(rgbCol.b*255);

                line.replace(pos+4,6,color.str());
                pos=line.find("e=\"#");
                line.replace(pos+4,6,color.str());

                id++;
            }
            newfile << line<<"\n";
        }
        myfile.close();
        newfile.close();
    }

}
