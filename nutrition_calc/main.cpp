#include <iostream>
#include <vector>
#include "nutrition.h"

using namespace std;

int main(){
    string itemNum;
    int inputAsInt;
    foodItem sumIntakes("sumIntakes", 0, 0, 0, 0, 0);
    vector<foodItem> foodList;
    foodList.push_back(foodItem("Apple", 95, 0 , 19 , 1, 2));
    foodList.push_back(foodItem("French Fries", 312, 18, 1, 5, 300));
    foodList.push_back(foodItem("Burger", 350, 20, 2, 20, 700));
    foodList.push_back(foodItem("Instant Ramen", 400, 20, 2, 10, 2000));
    foodList.push_back(foodItem("Protein Bar", 300, 15, 10, 15, 300));
    foodList.push_back(foodItem("Egg", 70, 5, 1, 6, 70));
    foodList.push_back(foodItem("Baguette", 180, 2, 1, 5, 400));
    foodList.push_back(foodItem("Steak", 210, 12, 0, 25, 5));
    foodList.push_back(foodItem("Grilled Cheese Sandwich", 350, 20, 2, 15, 600));
    foodList.push_back(foodItem("Ratatouille", 120, 7, 3, 4, 400));
    foodList.push_back(foodItem("Finished"));
    
    cout << "Welcome to the Nutrition Calculator!\nPlease select your foods from the list below:\n" << endl;
    
    do{
        for(int i = 0; i < foodList.size(); i++){
            cout << i + 1 << ": "<< (foodList[i]).getFoodName() << endl;
        }
        
        cout << "\nEnter item number: ";
        cin >> itemNum;
        inputAsInt = atoi(itemNum.c_str());
        cout << endl;
        if(inputAsInt <= 10 && inputAsInt > 0){
            cout << "Item added!\n" << endl;
            sumIntakes = sumIntakes + foodList.at(inputAsInt - 1);
        } else if(inputAsInt > 11 || inputAsInt <= 0){
            cout << "Invalid item. Retry.\n" << endl;
        }
    }while(inputAsInt != 11);
    
    cout << "Total Calories: " << sumIntakes.getCalories() << " cal." << endl;
    meetDailyIntakes(sumIntakes.getCalories(), 2000, "cal.");
    cout << "Total Fat: " << sumIntakes.getTotalFat() << " g." << endl;
    belowDailyIntakes(sumIntakes.getTotalFat(), 70, "g.");
    cout << "Total Sugars: " << sumIntakes.getTotalSugars() << " g." << endl;
    belowDailyIntakes(sumIntakes.getTotalSugars(), 30, "g.");
    cout << "Total Protein: " << sumIntakes.getProtein()  << " g." << endl;
    meetDailyIntakes(sumIntakes.getProtein(), 50, "g.");
    cout << "Total Sodium: " << sumIntakes.getSodium() << " mg." << endl;
    belowDailyIntakes(sumIntakes.getSodium(), 2300, "mg.");
    
    return 0;
}
