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
    m2gType = dual;
    drawable = true;
    graphloaded = false;
    NoOfPartitions=2;
    srand(time(NULL));
}

bool GraphPart::isDrawable()
{
    return drawable;
}

bool GraphPart::GraphIsLoaded()
{
    return graphloaded;
}

string GraphPart::removeWSpacesB(string str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');

    return str.substr(first, (last-first+1));
}

void GraphPart::checkIfDrawable()
{
    ifstream myfile(path_input);
    string temp;

    getline(myfile, temp);

    // remove whitespaces from the beginning
    temp = removeWSpacesB(temp);

    temp=temp.substr(0,temp.find(" "));

    if(stoi(temp) > 200000)
        drawable = false;
    else
        drawable = true;
}

void GraphPart::setInputFileName(string filename)
{
    path_input = filename;
    graphloaded= true;
    checkIfDrawable();
}

void GraphPart::setNumberOfPart(int noOfPartitions)
{
    NoOfPartitions = noOfPartitions;
}

void GraphPart::mesh2graph()
{
    //PARTITIONING
    string MetisCommand="m2gmetis ";

    if(m2gType == nodal)
         MetisCommand += " -gtype=nodal ";

    MetisCommand += path_input;
    MetisCommand += " ";
    path_input+=".graph";
    MetisCommand += path_input;
    system(MetisCommand.c_str());
}

// returns file name
string GraphPart::extractName()
{
    if(path_input.find("/") != string::npos)
        input_filename = path_input.substr(path_input.find_last_of("/")+1,path_input.length());
    else
        input_filename = path_input;
    return input_filename;
}

bool GraphPart::CheckInputFile()
{
    ifstream myfile(path_input);
    string temp;
    getline(myfile, temp);

    // remove whitespaces from the beginning
    temp = removeWSpacesB(temp);

    if((temp.find(" ")!=string::npos && inputType==graph) || (temp.find(" ")==string::npos && inputType==mesh)) return true;
    else return false;
}

Mesh2GraphType GraphPart::getM2GType()
{
    return m2gType;
}

string GraphPart::Partition()
{
    if(!QDir("metisOut").exists())
        QDir().mkdir("metisOut");

    QDateTime dateTime = QDateTime::currentDateTime();
    //path_metisOut = "metisOut/out_" + std::to_string(dateTime.toTime_t()) + ".txt";
    path_metisOut = "metisOut/out_" + dateTime.toString(Qt::ISODate).toStdString() + ".txt";

    //PARTITIONING
    string MetisCommand="gpmetis ";
    MetisCommand+=metisParams;
    MetisCommand+=path_input;
    MetisCommand+=" ";
    MetisCommand+= to_string(NoOfPartitions);
    MetisCommand+=" > " + path_metisOut;
    system(MetisCommand.c_str());

    return path_metisOut;
}

void GraphPart::SvgPrepare()
{
    //DRAWING
    string GraphModCommand="ipython3 -c 'import graph_mod; graph_mod.raw_to_svg(\"";
    GraphModCommand=GraphModCommand+path_input+"\",\"" + path_uncolored + "\",progress=False)'";
    system(GraphModCommand.c_str());


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

bool GraphPart::SetInputType(InputType type, Mesh2GraphType m2g)
{
    inputType=type;
    if(CheckInputFile()){
        if(inputType == mesh){
            mesh2graph();
            m2gType = m2g;
        }
        return true;
    }
    else
        return false;
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


