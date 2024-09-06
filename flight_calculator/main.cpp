#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <vector>

using namespace std;

vector<string> locationsVec = {"Miami Beach, FL, USA ","Fargo, ND, USA", "Idaho City, ID, USA","Pittsburg, KS, USA","Burlington, IA, USA", 
"Monroe, LA, USA","Paris, KY, USA","Vincennes, IN, USA","Auburn, ME, USA","Rockville, MD, USA"};
vector<double> latitudeVec = {25.793449, 46.877186, 43.828850, 37.406769, 40.810947, 32.509930, 38.206348, 38.678299,	44.090008, 39.086437};
vector<double> longitudeVec = {-80.139198,-96.789803,-115.837860,-94.705528,-91.131844,-92.121742,-84.270172,-87.522491,-70.271439,-77.161263};
    
class Location {
    public:
        Location(int input){
            location = locationsVec[input];
            latitude = latitudeVec[input];
            longitude = longitudeVec[input];
        }
        string GetLocation();
        double GetLatitude();
        double GetLongitude();
   private:
      string location;
      double latitude;
      double longitude;
};

double haversine(double lat1, double long1, double lat2, double long2, double radius);

double getFlightTime(double lat1, double long1, double lat2, double long2);

void displayLocList(int vectorSize);

void eraseDepartLoc(int index);

void obtainLocation(unsigned int& inputAsInt);

int main(){
    unsigned int input;
    
    cout << "The flight calculator will compute the amount of time it takes an airplane to fly from one GPS location to another." << endl << 
    "Please select your departure location and destination location from the list below." << endl << endl;
    
    displayLocList(locationsVec.size());
    
    obtainLocation(input); //obtain departure location
    
    input--; //set obtained location as departure
    Location departLoc(input);
    
    eraseDepartLoc(input);//remove departure location
    
    displayLocList(locationsVec.size());
    
    obtainLocation(input); //obtain destination location
    
    input--; //set obtained location as destination
    Location destinLoc(input);
    
    cout << "The approximate time it will take to fly from " << departLoc.GetLocation() << " to " << destinLoc.GetLocation() << " is about " 
    << getFlightTime(departLoc.GetLatitude(), departLoc.GetLongitude(), destinLoc.GetLatitude(), destinLoc.GetLongitude()) << " hours." << endl; 
    //calculates and prints out flight time 
    return 0;
}

string Location::GetLocation() {
   return location;
}

double Location::GetLatitude() {
   return latitude;
}

double Location::GetLongitude() {
   return longitude;
}

double haversine(double lat1, double long1, double lat2, double long2, double radius){
    return 2*radius*asin(sqrt(pow((sin((lat2-lat1)/2)),2) + cos(lat1)*cos(lat2)*pow((sin((long2-long1)/2)),2)));
}

double getFlightTime(double lat1, double long1, double lat2, double long2){
    const double PLANE_SPD = 575.0;
    const double EARTH_RADIUS = 3958.8;
    return (haversine(lat1, long1, lat2, long2, EARTH_RADIUS)) / PLANE_SPD;
}

void displayLocList(int vectorSize){
    for(int i = 0; i < vectorSize; i++){
        cout << i + 1 << ". "<< locationsVec[i] << "  " << latitudeVec[i] << "  " << longitudeVec[i] << endl;
    }
}

void eraseDepartLoc(int index){
    locationsVec.erase(locationsVec.begin() + index);
    latitudeVec.erase(latitudeVec.begin() + index);
    longitudeVec.erase(longitudeVec.begin() + index);
}

void obtainLocation(unsigned int& inputAsInt){
    string userInput;
    const int isString = 0;
    do{
        cout << endl << "Select your location: ";
        cin >> userInput;
        cout << endl;
        inputAsInt = atoi(userInput.c_str());
    } while (inputAsInt == isString || inputAsInt > locationsVec.size());
}