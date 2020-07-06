#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include "input.h"
#include <queue>
#include <time.h>
#include <unistd.h>


using namespace std;

class pathplanning
{
public:
    /* data */
    arginput data;
    pathplanning(){
        data.read("data/pathplanning.json");
    };
public:
    void Solution(){
        
    };

};

int main(int argc, char const *argv[])
{
    
    pathplanning out;

    out.Solution();
    
    
    return 0;
}
