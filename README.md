# City-Distance
- Calculates the distance between two cities on Earth

## Details
- Program extracts data from dataset ([worldcities_clean.csv](#worldcities_cleancsv)).
- Converts dataset into a 2D matrix to lookup information and applies [Haversine formula](https://en.wikipedia.org/wiki/Haversine_formula) based off the inputs' latitude and longitude.
    - Details regarding the dataset can be found under [worldcities_clean.csv](#worldcities_cleancsv).

## Specs
- As of git history "Updated README v1.1", the following was used.
    - Visual Studio Code
    - MSYS2 compiler was used
    - g++ version used at the time that this was written is 12.1.0
    - gdb version used at the time that this was written is 12.1

## Sources
# worldcities_clean.csv
- The following link is where I discovered the dataset utilized in the repository. [Found at this Github page](https://gist.github.com/curran/13d30e855d48cdd6f22acdf0afe27286/).
- Explicit thanks to "curran" on Github for the simplified dataset from [Simplemaps: World Cities Database](https://simplemaps.com/data/world-cities) October 2019
    - This dataset has five different columns (city name, latitude, longitude, country, population).
- Legal license regarding the dataset and its uses are present in the Github link provided above (First link under [worldcities_clean.csv](#worldcities_cleancsv)).
