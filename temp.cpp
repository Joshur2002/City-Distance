
#include "temp.h"

/*
read_CSV
    DESCRIPTION: Function that takes in a .csv file and converts it to a 2D matrix. 
        - Row syntax:
            city[0]    latitude[1]     longitude[2]     country[3]    population[4]
        - Both Koreas have an "extra" column after [3] to denote whether it's North or South


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

float calc_dist(string city1, string city2) {
    /* initialize */
    float dist = 0.0;

    return dist;
}

int main() {
    /* call func to get data matrix */
    vector<vector<string>> city_matrix = read_CSV("worldcities_clean.csv");

    /* call func to calc dist between the two cities */



    /* test */
    // printf("%s\n", city_matrix[20][3].c_str());

    // for (const auto& row : city_matrix) {
    //     for (const auto& element : row) {
    //         cout << element << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}