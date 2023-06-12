
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>

#define M_PI     3.14159265358979323846

using namespace std;

vector<vector<string>> read_CSV(const string& filename);
float calc_dist(char* city1, char* city2);
float deg_to_rad(float deg);


