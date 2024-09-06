#include "nutrition.h"

foodItem::foodItem(const string& STOP){
    this->foodName = STOP;
}

foodItem::foodItem(const string& FOOD_NAME, int calories, int totalFat, int totalSugars, int protein, int sodium){
    this->foodName = FOOD_NAME;
    this->calories = calories;
    this->totalFat = totalFat;
    this->totalSugars = totalSugars;
    this->protein = protein;
    this->sodium = sodium;
}

foodItem foodItem::operator+(foodItem rhs){
    foodItem r("sumIntakes", 0, 0, 0, 0, 0);
    r.calories = this->calories + rhs.calories;
    r.totalFat = this->totalFat + rhs.totalFat;
    r.totalSugars = this->totalSugars + rhs.totalSugars;
    r.protein = this->protein + rhs.protein;
    r.sodium = this->sodium + rhs.sodium;
    return r;
}

string foodItem::getFoodName() const{
    return foodName;
}

int foodItem::getCalories() const{
    return calories;
}

int foodItem::getTotalFat() const{
    return totalFat;
}

int foodItem::getTotalSugars() const{
    return totalSugars;
}

int foodItem::getProtein() const{
    return protein;
}

int foodItem::getSodium() const{
    return sodium;
}

void meetDailyIntakes(int totalIntake, int recIntake, string intakeName){
    if(totalIntake > recIntake){
        cout << "You have exceeded the recommended daily intake of approximately " << recIntake << " " << intakeName << endl << endl;
    } else if(totalIntake == recIntake){
        cout << "You have met the recommended daily intake of approximately " << recIntake << " " << intakeName << endl << endl;
    } else{
        cout << "You have not met the recommended daily intake of approximately " << recIntake << " " << intakeName << endl << endl;
    }
}

void belowDailyIntakes(int totalIntake, int recIntake, string intakeName){
    if(totalIntake > recIntake){
        cout << "You have exceeded the recommended daily intake of less than " << recIntake << " " << intakeName << endl << endl;
    } else {
        cout << "You have stayed under the recommended daily intake of less than " << recIntake << " " << intakeName << endl << endl;
    }
}