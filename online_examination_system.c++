#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Question {
public:
    string questionText;
    vector<string> options;
    int correctOption;

    Question(string text, const vector<string>& opts, int correctOpt)
        : questionText(text), options(opts), correctOption(correctOpt) {}

    void displayQuestion() const {
        cout << questionText << endl;
        for (size_t i = 0; i < options.size(); ++i) {
            cout << i + 1 << ". " << options[i] << endl;
        }
    }

    bool isCorrect(int selectedOption) const {
        return (selectedOption - 1) == correctOption;
    }
};

class Exam {
public:
    string examId;
    vector<Question> questions;

    Exam(string id, const vector<Question>& qs)
        : examId(id), questions(qs) {}

    void conductExam() const {
        cout << "Welcome to Exam ID: " << examId << endl;
        int score = 0;

        for (size_t i = 0; i < questions.size(); ++i) {
            cout << "Question " << i + 1 << ":" << endl;
            questions[i].displayQuestion();

            int selectedOption;
            cout << "Select your answer (1-" << questions[i].options.size() << "): ";
            cin >> selectedOption;

            if (questions[i].isCorrect(selectedOption)) {
                cout << "Correct!" << endl;
                score++;
            } else {
                cout << "Incorrect. Correct answer: " << questions[i].correctOption + 1 << endl;
            }
        }

        cout << "Exam completed. Your score: " << score << "/" << questions.size() << endl;
    }
};

class OnlineExamSystem {
public:
    vector<Exam> exams;

    void addExam(const Exam& exam) {
        exams.push_back(exam);
        cout << "Exam added successfully." << endl;
    }

    void conductExam(string examId) {
        for (const auto& exam : exams) {
            if (exam.examId == examId) {
                exam.conductExam();
                return;
            }
        }
        cout << "Exam not found." << endl;
    }
};

int main() {
    OnlineExamSystem examSystem;

    // Adding sample exams with questions
    vector<Question> questions1 = {
        {"What is the capital of France?", {"Berlin", "Paris", "Madrid", "Rome"}, 1},
        {"Which programming language is this sample written in?", {"Java", "Python", "C++", "JavaScript"}, 3},
        // Add more questions as needed
    };

    Exam exam1("E001", questions1);
    examSystem.addExam(exam1);

    // Conducting an exam
    examSystem.conductExam("E001");

    return 0;
}
