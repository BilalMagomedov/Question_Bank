#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <windows.h>

using namespace std;

// Structure to hold each quiz question
struct Question
{
  string problem_def;     // The question text
  vector<string> options; // The options for the question
  char correct_answer;    // The correct answer before shuffling
  char shuffled_answer;   // The correct answer after shuffling
};

// Function prototypes
string parseLine(string &line);
void shuffleQuestions(vector<Question> &questions);
void shuffleOptions(Question &q);
string getQuestionString(const Question &q, int qNum);
int getUserChoice();
void saveToFile(const string &content);

int main()
{
  HANDLE console_color;
  console_color = GetStdHandle(STD_OUTPUT_HANDLE);

  vector<Question> question_bank;
  string filename = "questions.txt";
  fstream file(filename);

  // Reading questions from the file
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      Question q;
      q.problem_def = line.substr(4); // Extract question text

      // Read and parse options
      for (int i = 0; i < 4; ++i)
      {
        getline(file, line);
        q.options.push_back(parseLine(line));
      }

      // Read and store the correct answer
      getline(file, line);
      q.correct_answer = line[5];
      q.shuffled_answer = q.correct_answer; // Initialize shuffled answer

      getline(file, line); // Skip empty line between questions

      question_bank.push_back(q);
    }
    file.close();
  }
  else
  {
    cout << "Error! Unable to open file" << endl;
    return -1;
  }

  // Get user choice for shuffling
  int userChoice = getUserChoice();

  // Shuffle questions and/or options based on user choice
  if (userChoice == 1 || userChoice == 3)
  {
    shuffleQuestions(question_bank);
  }

  if (userChoice == 2 || userChoice == 3)
  {
    for (Question &q : question_bank)
    {
      shuffleOptions(q);
    }
  }

  // Prepare and display the shuffled questions
  stringstream output;
  int qNum = 1;
  cout << "\n";
  for (const Question &q : question_bank)
  {
    output << getQuestionString(q, qNum++);
  }

  string outputStr = output.str();
  cout << outputStr;

  // Prompt to save questions to a file
  saveToFile(outputStr);

  return 0;
}

// Function to parse each line from the input file
string parseLine(string &line)
{
  return line.length() > 3 ? line.substr(3) : "Error: Line too short";
}

// Function to shuffle the order of the questions
void shuffleQuestions(vector<Question> &questions)
{
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  shuffle(questions.begin(), questions.end(), default_random_engine(seed));
}

// Function to shuffle options within each question
void shuffleOptions(Question &q)
{
  vector<string> originalOptions = q.options;
  char originalAnswer = toupper(q.correct_answer);

  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  shuffle(q.options.begin(), q.options.end(), default_random_engine(seed));

  for (int i = 0; i < q.options.size(); ++i)
  {
    if (q.options[i] == originalOptions[originalAnswer - 'A'])
    {
      q.shuffled_answer = tolower('A' + i);
      break;
    }
  }
}

// Function to convert question data to a formatted string (Used StackOverFlow)
string getQuestionString(const Question &q, int qNum)
{
  stringstream ss;
  ss << "Q" << qNum << ": " << q.problem_def << endl;
  for (int i = 0; i < q.options.size(); ++i)
  {
    ss << char(tolower('A' + i)) << ". " << q.options[i] << endl;
  }
  ss << "ANS: " << q.shuffled_answer << endl
     << endl;
  return ss.str();
}

// Function to save the question data to a file
void saveToFile(const string &content)
{
  HANDLE console_color;
  console_color = GetStdHandle(STD_OUTPUT_HANDLE);

  char choice;
  cout << "Do you want to save these questions to a file? (Y/N): ";
  cin >> choice;

  if (toupper(choice) == 'Y')
  {
    ofstream outFile("SavedQuestions.txt");
    if (outFile.is_open())
    {
      outFile << content;
      outFile.close();
      SetConsoleTextAttribute(console_color, 13);
      cout << "Questions saved to 'SavedQuestions.txt'." << endl
           << endl;
    }
    else
    {
      SetConsoleTextAttribute(console_color, 12);
      cerr << "Error opening file for writing." << endl;
    }
  }
  SetConsoleTextAttribute(console_color, 15);
}

// Function to get user's choice for shuffling
int getUserChoice()
{
  HANDLE console_color;
  console_color = GetStdHandle(STD_OUTPUT_HANDLE);

  int choice;

  SetConsoleTextAttribute(console_color, 12);
  cout << "\n\n***************************************************\n";
  cout << "*                                                 *\n";
  cout << "*            BILAL MAGOMEDOV 200201107            *\n";
  cout << "*                 PROJECT ON C++                  *\n";
  cout << "*                                                 *\n";
  cout << "***************************************************\n";
  cout << "*                                                 *\n";
  SetConsoleTextAttribute(console_color, 13);
  cout << "*                • Shuffle Menu •                 *\n";
  SetConsoleTextAttribute(console_color, 14);
  cout << "*            1. Shuffle Questions Only            *\n";
  cout << "*            2. Shuffle Options Only              *\n";
  cout << "*            3. Shuffle Both                      *\n";
  cout << "*            4. Do Not Shuffle                    *\n";

  SetConsoleTextAttribute(console_color, 15);
  cout << "*                                                 *\n";
  cout << "***************************************************\n";
  cout << "› Enter your choice (1-4): ";

  SetConsoleTextAttribute(console_color, 10);
  cin >> choice;

  SetConsoleTextAttribute(console_color, 15);
  return choice;
}
