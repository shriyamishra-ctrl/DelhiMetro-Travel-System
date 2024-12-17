#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <stack>
using namespace std;
bool isMonday() {
    time_t currentTime = time(0);
    tm* dateDetails = localtime(&currentTime);
    int dayOfWeek = dateDetails->tm_wday;

    return (dayOfWeek == 1);  // Return true if today is monday
}
string toLowerCase(const string& input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

class DelhiMetroApp
{
public:
 struct Station
 {
  string name;
  unordered_map<string, int> neighbors;
 };
 unordered_map<string, Station> metroMap;
 public:
 // Function to add a new station to the metro map
 void addStation(const string& name)
 {
 Station newStation;
 newStation.name = name;
 metroMap[name] = newStation;
 }
 // Function to add a new metro line between two stations with travel time
 void addMetroLine(const string& station1, const string& station2, int time)
 {
 metroMap[station1].neighbors[station2] = time;
 metroMap[station2].neighbors[station1] = time;
 }
void writeWelcomePageToFile()
 {
 ofstream welcomeFile("welcome_page.txt");
 if (welcomeFile.is_open())
 {
welcomeFile << " _ _ _ _ _ _ _ _ _ \n";
welcomeFile << " \\ \\ / /| || | / _| / _ \\ | \\/ || _| \n";
welcomeFile << " \\ \\/\\/ / | | | |_ | (_ | () || |\\/| || _| \n";
welcomeFile << " \\/\\/ |||| \\| \\/ || ||__| \n";
welcomeFile << " \n";
welcomeFile << "       _  \n";
welcomeFile << "|_ _| / _ \ \n";
welcomeFile << " ||   |(_)| \n";
welcomeFile << " ||    \__/ \n";
welcomeFile << "\n";
welcomeFile << " _ _ _ _ _ _ \n";
welcomeFile << " | \\ | _|| | | || || _| \n";
welcomeFile << " | |) || | | |_ | __ | | | \n";
welcomeFile << " |/ |||||||||_| \n";
welcomeFile << " \n";
welcomeFile << " _ _ _ _ _ _ \n";
welcomeFile << " | \\/ || _|| _|| _ \\ / _ \\ \n";
welcomeFile << " | |\\/| || | | | | /| () | \n";
welcomeFile << " || |||| || ||\\ \\_/ \n";
welcomeFile << " \n";
welcomeFile << " OO O o o o... ___ ____ \n";
welcomeFile << " O __ | | | | \n";
welcomeFile << " ][n_i| ( ooo___ | | | | \n";
welcomeFile << "(_|[_]|__||__| \n";
welcomeFile << " 0--0--0 0 0 0 0 0 0 0 \n";
welcomeFile.close();
 }
 else
 {
 cerr << "Unable to open file for writing welcome page.\n";
 }
 }
 void displayWelcomePageFromFile()
 {
 ifstream welcomeFile("welcome_page.txt");
 if (welcomeFile.is_open())
 {
 string line;
 while (getline(welcomeFile, line))
 {
 cout << line << endl;
 }
 welcomeFile.close();
 }
 else
 {
 cerr << "Unable to open file for reading welcome page.\n";
 }
 }
void writeWelcomePageToFile1()
 {
 ofstream welcomeFile("welcome_page1.txt");
 if (welcomeFile.is_open())
 {
welcomeFile << " _ _ _ _ _ _ _ __ \n";
welcomeFile << " |_ _|| || |/ \\| \\| || |/ / \n";
welcomeFile << " | | | __ || - || . || < \n";
welcomeFile << " || ||||||||\\|||\\_\\ \n";
welcomeFile << " _ _ _ _ _ \n";
welcomeFile << " \\ \\ / / / _ \\ | | | | \n";
welcomeFile << " \\ / | () || || | \n";
welcomeFile << " || \\/ \\_/ \n";
welcomeFile << " _ _ _ \n";
welcomeFile << "| __| / _ \\ | _ \\ \n";
welcomeFile << "| | | () || / \n";
welcomeFile << "|| \\/ ||\\ \n";
welcomeFile << "_ _ _ _ _ _ _ _ _ _ \n";
welcomeFile << "\\ \\ / /|_ |/ || || || || \\| | / _|\n";
welcomeFile << " \\ / | | \\_ \\ | | | | | | | . || ( |\n";
welcomeFile <<"\\/ |||/|| || |||||| \\__|\n";
welcomeFile.close();
 }
 else
 {
 cerr << "Unable to open file for writing welcome page.\n";
 }
 }
 void displayWelcomePageFromFile1()
 {
 ifstream welcomeFile("welcome_page1.txt");
 if (welcomeFile.is_open())
 {
 string line;
 while (getline(welcomeFile, line))
 {
 cout << line << endl;
 }
 welcomeFile.close();
 }
 else
 {
 cerr << "Unable to open file for reading welcome page.\n";
 }
 }
 void clearScreen() {
 #ifdef _WIN32
 system("cls");
 #else
 system("clear");
  #endif
 }

 // Function to find the shortest path between two stations using Dijkstra's algorithm
 vector<string> findShortestPath(const string& startStation, const string& endStation)
 {
 unordered_map<string, int> distance;
 unordered_map<string, string> previous;
 priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
 for (const auto& entry : metroMap)
 {
 distance[entry.first] = INT_MAX;
 }
 distance[startStation] = 0;
 pq.push({0, startStation});
 while (!pq.empty())
 {
 string current = pq.top().second;
 int currentDistance = pq.top().first;
 pq.pop();
 if (currentDistance > distance[current])
 continue;

 for (const auto& neighbor : metroMap[current].neighbors)
 {
 int newDistance = currentDistance + neighbor.second;
 if (newDistance < distance[neighbor.first])
 {
 distance[neighbor.first] = newDistance;
 previous[neighbor.first] = current;
 pq.push({newDistance, neighbor.first});
 }
 }
 }
 // Reconstruct the path
 vector<string> path;
 string current = endStation;
 if (previous.find(current) == previous.end() && current != startStation)
{
        return {}; // Return an empty vector
}
 while (!previous[current].empty())
 {
 path.push_back(current);
 current = previous[current];
 }
 path.push_back(startStation);
 reverse(path.begin(), path.end());
 return path;
 }
 pair<double, int> calculateFare(const vector<string>& path)
{
    double totalFare = 10; // Base fare
    int totalDistance = path.size() - 1;
    const double discountRate = 0.1;     // 10% discount for monday

    // Get the current day of the week
    time_t now = time(0);
    tm* localTime = localtime(&now);
    int dayOfWeek = localTime->tm_wday; // 0 = Sunday, 1 = Monday, ..., 6 = Saturday

    // Calculate total distance
    int totalDistance1 = 0;
    for (size_t i = 0; i < path.size() - 1; ++i)
    {
        const string& currentStation = path[i];
        const string& nextStation = path[i + 1];

        // Add the distance between the current and the next station
        if (metroMap[currentStation].neighbors.find(nextStation) != metroMap[currentStation].neighbors.end())
        {
            // Assume an average speed of 40 km/h (or 0.67 km/min) for distance estimation
           double averageSpeedInKmPerMin = 0.67;
           totalDistance += metroMap[currentStation].neighbors[nextStation] * averageSpeedInKmPerMin;

        }
        else
        {
            cerr << "Error: No direct connection between " << currentStation << " and " << nextStation << endl;
            return {-1, -1}; // Error value for invalid paths
        }
    }

    // Calculate total fare
    if (totalDistance <= 2) totalFare = 10; // For 0-2 km
    else if (totalDistance <= 5) totalFare = 20; // For 3-5 km
    else if (totalDistance <= 10) totalFare = 40;// For 6-10 km
    else if (totalDistance <= 20) totalFare = 50;
    else if (totalDistance <= 30) totalFare = 60;
    else if (totalDistance <= 40) totalFare = 65;
    else totalFare = 110; // Capped fare for >10 km

    // Apply a 10% discount if today is monday
    if (isMonday())
     {
    totalFare -= totalFare * discountRate;
     }

     // Round up the fare
    totalFare = ceil(totalFare);

    // Return both fare and distance
    return {totalFare, totalDistance};
}

 //travel time
 void displayTravelTime(const vector<string>& path)
{
    int totalTime = 0;

    for (size_t i = 0; i < path.size() - 1; ++i)
    {
        const string& currentStation = path[i];
        const string& nextStation = path[i + 1];

        // Add travel time between the current and next station
        if (metroMap[currentStation].neighbors.find(nextStation) != metroMap[currentStation].neighbors.end())
        {
            totalTime += metroMap[currentStation].neighbors[nextStation];
        }
        else
        {
            cerr << "Error: No direct connection between " << currentStation << " and " << nextStation << endl;
            return;
        }
    }

    cout << "Total Travel Time: " << totalTime << " minutes\n";
}
vector<string> searchStations(const string& partialName) const {
    vector<string> matches;
    string lowerPartialName = toLowerCase(partialName);
    for (const auto& entry : metroMap) {
        string lowerStationName = toLowerCase(entry.first);
        if (lowerStationName.find(lowerPartialName) != string::npos) {
            matches.push_back(entry.first);
        }
    }
    return matches; // Return a list of matching stations
}

void printColoredStation(const string& station, const string& color)
{
 cout << "\033[1;" << color << "m" << station << "\033[0m";
}
int getValidStationNumber(const string& prompt, const DelhiMetroApp& metroApp) {
 int stationNumber;
 stack<string> errorStack;
 do {
 cout << prompt;
 cin >> stationNumber;
 if (stationNumber < 1 ||stationNumber> metroApp.metroMap.size()) {
 errorStack.push("Invalid input. Please choose a valid station number.");
 } else {
 return stationNumber;
 }
 cin.clear();
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 while (!errorStack.empty()) {
 cerr << "Error: " << errorStack.top() << endl;
 errorStack.pop();
 }
 } while (true);
}
};

int main()
{
 DelhiMetroApp metroApp;
 metroApp.writeWelcomePageToFile();
 metroApp.displayWelcomePageFromFile();
 cout << "\nPress Enter to continue...";
 cin.get();
 metroApp.clearScreen();
 metroApp.addStation("Noida_Sector_62~B");
 metroApp.addStation("Botanical_Garden~B");
 metroApp.addStation("Yamuna_Bank~B");
 metroApp.addStation("Rajiv_Chowk~BY");
 metroApp.addStation("Vaishali~B");
 metroApp.addStation("Moti_Nagar~B");
 metroApp.addStation("Janak_Puri_West~BO");
 metroApp.addStation("Dwarka_Sector_21~B");
 metroApp.addStation("Huda_City_Center~Y");
 metroApp.addStation("Saket~Y");
 metroApp.addStation("Vishwavidyalaya~Y");
 metroApp.addStation("Chandni_Chowk~Y");
 metroApp.addStation("New_Delhi~YO");
 metroApp.addStation("AIIMS~Y");
 metroApp.addStation("Shivaji_Stadium~O");
 metroApp.addStation("DDS_Campus~O");
 metroApp.addStation("IGI_Airport~O");
 metroApp.addStation("Rajouri_Garden~BP");
 metroApp.addStation("Netaji_Subhash_Place~PR");
 metroApp.addStation("Punjabi_Bagh_West~P");
 metroApp.addStation("Laxmi_Nagar~B");
 metroApp.addStation("Preet_Vihar~B");
 metroApp.addStation("Nirman_Vihar~B");
 metroApp.addStation("Karol_Bagh~B");
 metroApp.addStation("Rohini_Sector_18~R");
 metroApp.addStation("Rithala~R");
 metroApp.addStation("Shahdara~R");
 metroApp.addStation("Seelampur~R");
 metroApp.addStation("Welcome~R");
 metroApp.addStation("Kashmere_Gate~R");
 metroApp.addStation("GTB_Nagar~Y");
 metroApp.addStation("Azadpur~Y");
 metroApp.addStation("Adarsh_Nagar~Y");
 metroApp.addStation("Model_Town~Y");
 metroApp.addStation("Jahangirpuri~Y");
 metroApp.addStation("Samaypur_Badli~Y");
 metroApp.addStation("Dilshad_Garden~R");
 metroApp.addStation("Jhilmil~R");
 metroApp.addStation("Mundka~G");
 metroApp.addStation("Tikri_Kalan~G");
 metroApp.addStation("Inderlok~R");
metroApp.addStation("Pitampura~R");
metroApp.addStation("Shalimar_Bagh~R");
metroApp.addStation("Kanhaiya_Nagar~R");
metroApp.addStation("Civil_Lines~Y");
metroApp.addStation("Dilli_Haat~P");
metroApp.addStation("INA~Y");
metroApp.addStation("Lajpat_Nagar~P");
metroApp.addStation("Kalkaji_Mandir~V");
metroApp.addStation("Nehru_Place~V");
metroApp.addStation("Okhla_Bird_Sanctuary~M");
metroApp.addStation("Jamia_Millia_Islamia~M");
metroApp.addStation("Sarita_Vihar~V");
metroApp.addStation("Jasola_Vihar~V");
metroApp.addStation("Govindpuri~V");
metroApp.addStation("Tughlakabad~V");
metroApp.addStation("Badarpur_Border~V");
metroApp.addStation("Faridabad~V");
metroApp.addStation("Ballabhgarh~V");
metroApp.addStation("Ramakrishna_Ashram_Marg~B");
metroApp.addStation("Jhandewalan~B");
metroApp.addStation("Ajmal_Khan_Park~B");
metroApp.addStation("noida city centre");
metroApp.addStation("Rajendra_Place~B");
metroApp.addStation("Pusa_Road~B");
metroApp.addStation("Satya_Niketan~B");
metroApp.addStation("Patel_Nagar~B");
metroApp.addStation("East_Patel_Nagar~B");
metroApp.addStation("West_Patel_Nagar~B");
metroApp.addStation("Baljeet_Nagar~B");
metroApp.addStation("Punjabi_Bagh_East~B");
metroApp.addStation("Mansarovar_Garden~B");
metroApp.addStation("Kirti_Nagar~B");
metroApp.addStation("Rajouri_Garden~B");
metroApp.addStation("Tagore_Garden~B");
metroApp.addStation("Subhash_Nagar~B");
metroApp.addStation("Tilak_Nagar~B");
metroApp.addStation("Janak_Puri_East~B");
metroApp.addStation("Janak_Puri_West~B");
metroApp.addStation("Uttam_Nagar_East~B");
 metroApp.addMetroLine("Noida_Sector_62~B", "Botanical_Garden~B", 15);
 metroApp.addMetroLine("Botanical_Garden~B", "Yamuna_Bank~B", 30);
 metroApp.addMetroLine("Yamuna_Bank~B", "Vaishali~B", 25);
 metroApp.addMetroLine("Yamuna_Bank~B", "Rajiv_Chowk~BY", 6);
 metroApp.addMetroLine("Rajiv_Chowk~BY", "Moti_Nagar~B", 9);
 metroApp.addMetroLine("Moti_Nagar~B", "Janak_Puri_West~BO", 7);
 metroApp.addMetroLine("Janak_Puri West~BO", "Dwarka_Sector_21~B", 6);
 metroApp.addMetroLine("Huda_City_Center~Y", "Saket~Y", 15);
 metroApp.addMetroLine("Saket~Y", "AIIMS~Y", 10);
 metroApp.addMetroLine("AIIMS~Y", "Rajiv_Chowk~BY", 7);
 metroApp.addMetroLine("Rajiv_Chowk~BY", "New_Delhi~YO", 1);
 metroApp.addMetroLine("New_Delhi~YO", "Chandni_Chowk~Y", 2);
 metroApp.addMetroLine("Chandni_Chowk~Y", "Vishwavidyalaya~Y", 5);
 metroApp.addMetroLine("New_Delhi~YO", "Shivaji_Stadium~O", 2);
 metroApp.addMetroLine("Shivaji_Stadium~O", "DDS_Campus~O", 7);
 metroApp.addMetroLine("DDS_Campus~O", "IGI_Airport~O", 8);
 metroApp.addMetroLine("Moti_Nagar~B", "Rajouri_Garden~BP", 2);
 metroApp.addMetroLine("Punjabi_Bagh_West~P", "Rajouri_Garden~BP", 2);
 metroApp.addMetroLine("Punjabi_Bagh_West~P", "Netaji_Subhash_Place~PR", 3);
 metroApp.addMetroLine("Laxmi_Nagar~B", "Preet_Vihar~B", 5);
 metroApp.addMetroLine("Preet_Vihar~B", "Nirman_Vihar~B", 4);
 metroApp.addMetroLine("Nirman_Vihar~B", "Shahdara~R", 12);
 metroApp.addMetroLine("Shahdara~R", "Seelampur~R", 8);
 metroApp.addMetroLine("Seelampur~R", "Welcome~R", 7);
 metroApp.addMetroLine("Welcome~R", "Kashmere_Gate~R", 10);
 metroApp.addMetroLine("Kashmere_Gate~R", "GTB_Nagar~Y", 6);
 metroApp.addMetroLine("GTB_Nagar~Y", "Azadpur~Y", 5);
 metroApp.addMetroLine("Azadpur~Y", "Adarsh_Nagar~Y", 4);
 metroApp.addMetroLine("Adarsh_Nagar~Y", "Model_Town~Y", 3);
 metroApp.addMetroLine("Model_Town~Y", "Jahangirpuri~Y", 6);
 metroApp.addMetroLine("Jahangirpuri~Y", "Samaypur_Badli~Y", 7);
 metroApp.addMetroLine("Dilshad_Garden~R", "Jhilmil~R", 4);
 metroApp.addMetroLine("Jhilmil~R", "Seelampur~R", 6);
 metroApp.addMetroLine("Kashmere_Gate~R", "Karol_Bagh~B", 10);
 metroApp.addMetroLine("Mundka~G", "Tikri_Kalan~G", 12);
 metroApp.addMetroLine("Rajouri_Garden~BP", "Mundka~G", 9);
 metroApp.addMetroLine("Tikri_Kalan~G", "Dwarka_Sector_21~B", 15);
 metroApp.addMetroLine("Inderlok~R", "Kanhaiya_Nagar~R", 6);
metroApp.addMetroLine("Kanhaiya_Nagar~R", "Shalimar_Bagh~R", 7);
metroApp.addMetroLine("Shalimar_Bagh~R", "Pitampura~R", 8);
metroApp.addMetroLine("Pitampura~R", "Rohini_Sector_18~R", 10);
metroApp.addMetroLine("Rithala~R", "Shalimar_Bagh~R", 12);
metroApp.addMetroLine("Kashmere_Gate~R", "Civil_Lines~Y", 5);
metroApp.addMetroLine("Civil_Lines~Y", "Model_Town~Y", 4);
metroApp.addMetroLine("INA~Y", "Dilli_Haat~P", 3);
metroApp.addMetroLine("INA~Y", "AIIMS~Y", 5);
metroApp.addMetroLine("Kalkaji_Mandir~V", "Nehru_Place~V", 4);
metroApp.addMetroLine("Nehru_Place~V", "Govindpuri~V", 6);
metroApp.addMetroLine("Govindpuri~V", "Jasola_Vihar~V", 5);
metroApp.addMetroLine("Jasola_Vihar~V", "Sarita_Vihar~V", 4);
metroApp.addMetroLine("Sarita_Vihar~V", "Tughlakabad~V", 5);
metroApp.addMetroLine("Tughlakabad~V", "Badarpur_Border~V", 6);
metroApp.addMetroLine("Badarpur_Border~V", "Faridabad~V", 10);
metroApp.addMetroLine("Faridabad~V", "Ballabhgarh~V", 8);
metroApp.addMetroLine("Okhla_Bird_Sanctuary~M", "Jamia_Millia_Islamia~M", 6);
metroApp.addMetroLine("Jamia_Millia_Islamia~M", "Lajpat_Nagar~P", 8);
metroApp.addMetroLine("Lajpat_Nagar~P", "Kalkaji_Mandir~V", 7);
metroApp.addMetroLine("Rajiv_Chowk~BY", "Ramakrishna_Ashram_Marg~B", 4);
metroApp.addMetroLine("Ramakrishna_Ashram_Marg~B", "Jhandewalan~B", 3);
metroApp.addMetroLine("Jhandewalan~B", "Ajmal_Khan_Park~B", 5);
metroApp.addMetroLine("Ajmal_Khan_Park~B", "Rajendra_Place~B", 4);
metroApp.addMetroLine("Rajendra_Place~B", "Pusa_Road~B", 5);
metroApp.addMetroLine("Pusa_Road~B", "Patel_Nagar~B", 3);
metroApp.addMetroLine("Patel_Nagar~B", "East_Patel_Nagar~B", 2);
metroApp.addMetroLine("East_Patel_Nagar~B", "West_Patel_Nagar~B", 2);
metroApp.addMetroLine("West_Patel_Nagar~B", "Baljeet_Nagar~B", 3);
metroApp.addMetroLine("Baljeet_Nagar~B", "Punjabi_Bagh_East~B", 4);
metroApp.addMetroLine("Punjabi_Bagh_East~B", "Mansarovar_Garden~B", 5);
metroApp.addMetroLine("Mansarovar_Garden~B", "Kirti_Nagar~B", 3);
metroApp.addMetroLine("Kirti_Nagar~B", "Rajouri_Garden~B", 4);
metroApp.addMetroLine("Rajouri_Garden~B", "Tagore_Garden~B", 3);
metroApp.addMetroLine("Tagore_Garden~B", "Subhash_Nagar~B", 4);
metroApp.addMetroLine("Subhash_Nagar~B", "Tilak_Nagar~B", 3);
metroApp.addMetroLine("Tilak_Nagar~B", "Janak_Puri_East~B", 5);
metroApp.addMetroLine("Janak_Puri_East~B", "Janak_Puri_West~B", 4);
metroApp.addMetroLine("Janak_Puri_West~B", "Uttam_Nagar_East~B", 6);
metroApp.addMetroLine("Rajiv_Chowk~BY", "Ramakrishna_Ashram_Marg~B", 4);
metroApp.addMetroLine("Ramakrishna_Ashram_Marg~B", "Jhandewalan~B", 3);
metroApp.addMetroLine("Jhandewalan~B", "Ajmal_Khan_Park~B", 5);
metroApp.addMetroLine("Ajmal_Khan_Park~B", "Karol_Bagh~B", 4);
metroApp.addMetroLine("noida_sector_62", "noida city centre", 10);
metroApp.addMetroLine("Model_Town~Y", "Nehru_Place~V", 10);


 cout << " ***\033[1;33mWELCOME TO DELHI METRO RAIL CORPORATION \033[0m****]" << endl;
 cout << " *****" << endl;
 cout << "\nList of Metro Stations:\n";
 int stationNumber = 1;
 for (const auto& entry : metroApp.metroMap)
 {
 cout << stationNumber << ". ";
 metroApp.printColoredStation(entry.first, "32");
 cout << " ";
 cout << endl;
 stationNumber++;
 }
 cout << endl;
 cout << "Do you want to search by name or select by number?\n";
cout << "1. Search by name\n";
cout << "2. Select by number\n";
int choice;
cin >> choice;
string startStationName, endStationName;

if (choice == 1) {
while (true) {
    // Search by name for the start station
    cout << "Enter the partial or full name of the START STATION:\n";
    string input;
    cin.ignore(); // Clear any leftover input
    getline(cin, input);

    vector<string> matches = metroApp.searchStations(input);

    if (matches.empty()) {
        cout << "No stations found matching: " << input << endl;
        cout << "Please try again.\n";
}
    else if (matches.size() == 1) {
    // If only one match, select it automatically
       cout << "Station found: " << matches[0] << endl;
       startStationName=matches[0];
       break;
}
    else {
    // Display list of matches for user to choose
       cout << "Multiple stations found. Please select one:\n";
       for (size_t i = 0; i < matches.size(); ++i) {
           cout << i + 1 << ". " << matches[i] << endl;
    }
       cout << "Enter your choice (1-" << matches.size() << "): ";
       int choice;
       cin >> choice;
       if (choice >= 1 && choice <= matches.size()) {
           cout << "You selected: " << matches[choice - 1] << endl;
           startStationName=matches[choice - 1];
           break;
    }  else {
          cout << "Invalid choice. Exiting.\n";
          cout << "Please try again.\n";
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}}
while(true){
    cout << "Enter the partial or full name of the DESTINATION STATION:\n";
    string input;
    cin.ignore();
    getline(cin, input);
    vector<string> matches = metroApp.searchStations(input);
    matches = metroApp.searchStations(input);

     if (matches.empty()) {
        cout << "No stations found matching: " << input << endl;
}    else if (matches.size() == 1) {
    // If only one match, select it automatically
          cout << "Station found: " << matches[0] << endl;
          endStationName=matches[0];
          break;
}    else {
    // Display list of matches for user to choose
         cout << "Multiple stations found. Please select one:\n";
         for (size_t i = 0; i < matches.size(); ++i) {
               cout << i + 1 << ". " << matches[i] << endl;
    }
         cout << "Enter your choice (1-" << matches.size() << "): ";
          int choice;
          cin >> choice;
      if (choice >= 1 && choice <= matches.size()) {
        cout << "You selected: " << matches[choice - 1] << endl;
        endStationName=matches[choice-1];
        break;
    } else {
        cout << "Invalid choice. Exiting.\n";
    }

}}}
else if (choice == 2) {
    // Select by number for the start and end stations
    int startStationNumber = metroApp.getValidStationNumber("\nPlease enter the number corresponding to your START STATION:\n", metroApp);
    int endStationNumber = metroApp.getValidStationNumber("\nPlease enter the number corresponding to your DESTINATION STATION:\n", metroApp);

    // Map station numbers to station names
    int currentIndex = 1;
    for (const auto& entry : metroApp.metroMap) {
        if (currentIndex == startStationNumber) {
            startStationName = entry.first;
        }
        if (currentIndex == endStationNumber) {
            endStationName = entry.first;
        }
        currentIndex++;
    }
}
cout << "\nCalculating the shortest path...\n";
 vector<string> shortestPath = metroApp.findShortestPath(startStationName, endStationName);
 if (shortestPath.empty()) {
    // No path found
    cout << "No path found between " << startStationName << " and " << endStationName << ".\n";
} else {
 cout << "\nShortest Path from ";
 metroApp.printColoredStation(startStationName, "32");
 cout << " to ";
 metroApp.printColoredStation(endStationName, "34");
 cout << ":\n";
 for (size_t i = 0; i < shortestPath.size(); ++i)
 {
 metroApp.printColoredStation(shortestPath[i], "33");
 if (i < shortestPath.size() - 1)
 {
 cout << " -> ";
 }
 }
}

auto [fare, distance] = metroApp.calculateFare(shortestPath);


 // Display travel time
 cout << "\nTotal Distance: " << distance << " km"; // Display distance
 cout<<endl;
 cout<<endl;
 metroApp.displayTravelTime(shortestPath);
 cout << "\nTotal Fare: $" << fare << "\n";
 cout<<endl;

 cout<<endl;
 cout<<endl;
 cout<<"*******"<<endl;

 metroApp.writeWelcomePageToFile1();
 metroApp.displayWelcomePageFromFile1();
 return 0;
}
