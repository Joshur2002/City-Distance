
#include "city_dist.h"

/*
read_CSV
    DESCRIPTION: Function that takes in a .csv file and converts it to a 2D matrix. 
        - Row syntax:
            city[0]    latitude[1]     longitude[2]     country[3]    population[4]
        - Both Koreas have an "extra" column after [3] to denote whether it's North or South.
    INPUTS: filename -- Name of the file that will be converted to 2D matrix.
    RETURN: city_matrix -- 2D matrix that was converted from filename.
*/
vector<vector<string>> read_CSV(const string& filename) {
    /* initialize */
    ifstream file(filename);
    vector<vector<string>> city_matrix;
    string line;
    string cell;
    bool is_first_row = true;

    /* extract each row */
    while (getline(file, line)) {
        /* skip first row of data */
        if (is_first_row == true) {
            is_first_row = false;
            continue;
        }
        vector<string> row;
        stringstream linestream(line);
        bool is_korea = false;

        /* extract each col from a specific row */
        while (getline(linestream, cell, ',')) {
            /* KOREA edge case */
            if (cell == "\"Korea") { 
                is_korea = true;
                continue;
            }
            else if (is_korea == true) {
                if (cell == " South\"") {
                    row.push_back("South Korea");
                    is_korea = false;
                }
                else {   
                    row.push_back("North Korea");
                    is_korea = false;
                }
            }
            /* Not KOREA */
            else {
                row.push_back(cell);
            }
        }
        city_matrix.push_back(row);
    }
    return city_matrix;
}

/*
calc_dist
    DESCRIPTION: Searches through the city matrix for its inputs' lat/lon and calculates their distances.
        Does so without caring about capitalizations.
    INPUTS: city1 -- City string to search for.
            city2 -- City string to search for.
    RETURN: dist -- Distance between the two cities.
*/
float calc_dist(const char* city1, const char* city2) {
    /* initialize */
    float city1_lat, city1_lon, city2_lat, city2_lon;
    int i;
    bool found_city1 = false;
    bool found_city2 = false;

    double haversine;
    double temp;
    double dist;

    /* get data matrix */
    vector<vector<string>> city_matrix = read_CSV("worldcities_clean.csv");

    /* find the lat/lon of the two cities */
    for (i = 0; i < city_matrix.size(); i++) {
        const char* city_matrix_entry = city_matrix[i][0].c_str();
        /* city 1 */
        if (strcmpi(city1, city_matrix_entry) == 0) {
            city1_lat = stoi(city_matrix[i][1]);
            city1_lon = stoi(city_matrix[i][2]); 
            found_city1 = true;
        }
        /* city 2 */
        if (strcmpi(city2, city_matrix_entry) == 0) {
            city2_lat = stoi(city_matrix[i][1]);
            city2_lon = stoi(city_matrix[i][2]);
            found_city2 = true; 
        }
        /* both have been found */
        if (found_city1 == true && found_city2 == true)  
            break;
    }

    /* error in the names */
    if (found_city1 == false && found_city2 == true)
        return -1;
    else if (found_city1 == true && found_city2 == false)
        return -2;
    else if (found_city1 == false && found_city2 == false)
        return -3;
    /* both have been found */
    else {
        city1_lat = deg_to_rad(city1_lat);
        city1_lon = deg_to_rad(city1_lon);
        city2_lat = deg_to_rad(city2_lat);
        city2_lon = deg_to_rad(city2_lon);

        haversine = (pow(sin((1.0 / 2) * (city2_lat - city1_lat)), 2)) + ((cos(city1_lat)) * (cos(city2_lat)) * (pow(sin((1.0 / 2) * (city2_lon - city1_lon)), 2)));
        temp = 2 * asin(min(1.0, sqrt(haversine)));
        dist = 6371 * temp;
        return dist;
    }
}

/*
deg_to_rad
    DESCRIPTION: Converts an inputted degree value into a radian.
    INPUTS: deg -- Float value of a degree.
    RETURN: rad -- Float value of converted degree.
*/
float deg_to_rad(float deg) {
    float rad = deg*(M_PI/180);
    return rad;
}

int main() {
    /* test 1: check if getCSV works */
    /* call func to get data matrix */
    // vector<vector<string>> city_matrix = read_CSV("worldcities_clean.csv");

    // printf("%s\n", city_matrix[20][3].c_str());
    // printf("%s\n", city_matrix[20][3].c_str());

    /* call func to calc dist between the two cities */
    const char* city1 = "shanghai";
    const char* city2 = "mexico city";
    float city_dist = calc_dist(city1, city2);
    int x = (int)city_dist;
    if (x < 0 && x != -3) {
        printf("Did you type the name of city %d correctly?\n", -x);
        return 0;
    }
    else if (x == -3) {
        printf("Did you type the name of both cities correctly?\n");
        return 0;
    }
    else {
        printf("Distance from %s to %s is %f km\n", city1, city2, city_dist);
        return 0;
    }
}