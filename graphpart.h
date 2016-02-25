#ifndef GRAPHPART_H
#define GRAPHPART_H

#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <QDateTime>
#include <QDir>

#include "stdio.h"
#include "iostream"
#include "string"
#include "time.h"


using namespace std;

typedef struct {
    double r;       // percent
    double g;       // percent
    double b;       // percent
} rgb;

typedef struct {
    double h;       // angle in degrees
    double s;       // percent
    double v;       // percent
} hsv;

enum InputType{
    graph,
    mesh
};

rgb hsv2rgb(hsv in);


class GraphPart
{
public:
    GraphPart();

    void setInputFileName(string filename);
    void GraphColoring();
    bool isDrawable();
    bool GraphIsLoaded();
    void Partition();
    void checkIfDrawable();
    void SvgPrepare();
    void addMetisParameters(string params);
    string getPathUncolored();
    string getPathColored();
    bool SetInputType(InputType type);
    void setNumberOfPart(int noOfPartitions);
    void mesh2graph();
    void extractName();
    bool CheckInputFile();
private:
    string path_input;
    string input_filename;
    const string path_uncolored = "graph_uncolored.svg";
    const string path_colored = "graph_colored.svg";
    string path_metisOut = "out.txt";
    string metisParams="";
    InputType inputType;

    bool drawable;
    bool graphloaded;


    rgb hsv2rgb(hsv in);
    int NoOfPartitions;


};

#endif // GRAPHPART_H
