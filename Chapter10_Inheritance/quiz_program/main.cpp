#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Question {
    public:
    Question(string text, int pointValue){
        this->text = text;
        this->pointValue = pointValue;
        isCorrect = false;
    }
    
    virtual void askQuestion() = 0;
    
    int getPointsScored(){
        return pointValue * isCorrect;
    }
    
    protected:
    string text;
    bool isCorrect;
    int pointValue;
};

class TrueFalseQuestion : public Question {
    public:
    TrueFalseQuestion(string text, bool correctAnswer, int pointValue) : Question(text, pointValue) {
        this->correctAnswer = correctAnswer;
    }
    
    void askQuestion(){
        cout << text << endl;
        cout << "Enter T for True or F for False:" << endl;
        char userInput;
        cin >> userInput;
        
        bool userAnswer = false;
        if(userInput == 'T' || userInput == 't'){
            userAnswer = true;
        }
        
        if(userAnswer == correctAnswer){
            isCorrect = true;
        }
    }
    
    private:
    bool correctAnswer;
};

class MathQuestion : public Question {
    public:
    MathQuestion(string text, double correctAnswer, int pointValue) : Question(text, pointValue) {
        this->correctAnswer = correctAnswer;
    }
    
    void askQuestion(){
        cout << text << endl;
        double userAnswer;
        cin >> userAnswer;
        
        if(abs(userAnswer - correctAnswer) < 0.01){
            isCorrect = true;
        }
    }
    
    private:
    double correctAnswer;
};

int main(){
    
    vector<Question*> quiz;
    quiz.push_back(new TrueFalseQuestion("Joe Biden hates C++.", true, 10));
    quiz.push_back(new MathQuestion("2 + 2 = ?", 4.0, 10));
    quiz.push_back(new MathQuestion("4 / 2 = ?", 2.0, 10));
    
    int totalScore = 0;
    for(int i = 0; i < quiz.size(); i++){
        quiz.at(i)->askQuestion();
        totalScore += quiz.at(i)->getPointsScored();
    }
    
    cout << "Points Scored: " << totalScore << endl;
    
    /*
    Question* question1 = new TrueFalseQuestion("Joe Biden hates C++.", true, 10);
    Question* question2 = new MathQuestion("2 + 2 = ?", 4.0, 10);
    Question* question3 = new MathQuestion("4 / 2 = ?", 2.0, 10);
    
    question1->askQuestion();
    question2->askQuestion();
    question3->askQuestion();
    
    cout << "Points Scored: " << question1->getPointsScored() + 
                                 question2->getPointsScored() + 
                                 question3->getPointsScored() << endl;
    */
    
    return 0;
}