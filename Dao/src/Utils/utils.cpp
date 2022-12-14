#include "Utils/utils.hpp"

std::vector<int> argsort(std::vector<double> &fit){
    using namespace std;
    vector<int> o_fit(fit.size());
        iota(o_fit.begin(), o_fit.end(), 0);

        stable_sort(o_fit.begin(), o_fit.end(),
            [&fit](int i1, int i2) {return fit[i1] < fit[i2];});
    return o_fit;
};

int read2DMatrix(std::vector<std::vector<double>>& data, std::string filename){
    using namespace std;
    ifstream fin;
    fin.open(filename);
    if(!fin)return 0;
    string oneline;
    data.clear();
    
    vector<double> xy;
    while (!fin.eof())
    {
        getline(fin, oneline);
        if (oneline == "")
        {
            break;
        }
        istringstream is(oneline);
        double t;
        while(is >> t){
            char ch;
            xy.push_back(t);
            is >> ch;
        }
        data.push_back(xy);
        xy.clear();
    }
    fin.close();
    return 1;
};

void readRobotShape(std::vector<std::vector<int>>& robot_shape, std::string filename){
    using namespace std;
    ifstream fin;
    fin.open(filename);
    string oneline;
    robot_shape.clear();

    vector<int> xy;


    while (!fin.eof())
    {
        getline(fin, oneline);
        
        if (oneline == "")
        {
            break;
        }
        istringstream is(oneline);
        float t;
        while(is >> t){
            char ch;
            
            xy.push_back(t);
            is >> ch;
        }
        robot_shape.push_back(xy);
        
        xy.clear();
    }
    fin.close();
    std::cout<<robot_shape.size()<<std::endl;   
};

std::vector<double> readGene(std::string filename, int index){
    using namespace std;
    std::vector<double> gene;
    ifstream fin;
    fin.open(filename);
    string oneline;

    vector<double> xy;
    while (!fin.eof())
    {   
        xy.clear();
        getline(fin, oneline);
        
        if (oneline == "")
        {
            break;
        }
        istringstream is(oneline);
        float t;
        while(is >> t){
            char ch;
            
            xy.push_back(t);
            is >> ch;
        }
    }
    fin.close();
    return xy;   

};

double distance3D(double x1, double y1, double z1, double x2, double y2, double z2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2)+ pow(z1-z2,2));
};

double distance2D(double x1, double y1, double x2, double y2){
    return sqrt(pow(x1-x2,2) + pow(y1-y2,2));
};