// Class for managing place details
class Place
{
public:
    string name;
    string description;
    string weather;
    double rating;

    Place(string n, string desc, string w, double r) : name(n), description(desc), weather(w), rating(r) {}
};

// Class for managing places to visit
class PlacesToVisit
{
private:
    vector<Place> indianPlaces;
    vector<Place> internationalPlaces;

public:
    // Method to add an Indian place to visit
    void addIndianPlace(string name, string description, string weather, double rating)
    {
        indianPlaces.push_back(Place(name, description, weather, rating));
        savePlacesToFile("indian_places.txt", indianPlaces);
        return;
    }
    // Method to add an international place to visit
    void addInternationalPlace(string name, string description, string weather, double rating)
    {
        internationalPlaces.push_back(Place(name, description, weather, rating));
        savePlacesToFile("international_places.txt", internationalPlaces);
        return;
    }
    // Method to save places to a file
    void savePlacesToFile(string fileName, const vector<Place>& places)
    {
        ofstream outFile(fileName);
        if (outFile.is_open())
        {
            for (const auto& place : places)
            {
                outFile << "Name: " << place.name << endl;
                outFile << "Description: " << place.description << endl;
                outFile << "Weather: " << place.weather << endl;
                outFile << "Rating: " << place.rating << endl;
                outFile << endl; // Separate entries with a blank line
            }
            outFile.close();
        }
        else
        {
            cout << "Unable to open file: " << fileName << endl;
        }
        return;
    }
    // Method to load places from a file
    void loadPlacesFromFile(string fileName)
    {
        ifstream inFile(fileName);
        if (inFile.is_open())
        {
            string line;
            while (getline(inFile, line))
            {
                if (line.empty())
                {
                    continue; // Skip blank lines
                }
                string name = line.substr(line.find(": ") + 2); // Extract name
                getline(inFile, line); // Read description
                string description = line.substr(line.find(": ") + 2); // Extract description
                getline(inFile, line); // Read weather
                string weather = line.substr(line.find(": ") + 2); // Extract weather
                getline(inFile, line); // Read rating
                double rating = stod(line.substr(line.find(": ") + 2)); // Extract rating
                if (fileName == "indian_places.txt")
                {
                    indianPlaces.push_back(Place(name, description, weather, rating));
                }
                else if (fileName == "international_places.txt")
                {
                    internationalPlaces.push_back(Place(name, description, weather, rating));
                }
            }
            inFile.close();
        }
        else
        {
            cout << "Unable to open file: " << fileName << endl;
        }
        return;
    }
    // Method to display all Indian places to visit
    void displayIndianPlaces()
    {
        cout << "Indian Places to Visit:\n";
        for (const auto& place : indianPlaces)
        {
            cout << "Name: " << place.name << endl;
            cout << "Description: " << place.description << endl;
            cout << "Weather: " << place.weather << endl;
            cout << "Rating: " << place.rating << endl;
            cout << endl;
        }
        return;
    }
    // Method to display all international places to visit
    void displayInternationalPlaces()
    {
        cout << "International Places to Visit:\n";
        for (const auto& place : internationalPlaces)
        {
            cout << "Name: " << place.name << endl;
            cout << "Description: " << place.description << endl;
            cout << "Weather: " << place.weather << endl;
            cout << "Rating: " << place.rating << endl;
            cout << endl;
        }
        return;
    }
};
