#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

struct Variable {
    string name;
    double value;
};

class Function {
public:
    string name;
    vector<string> arguments;
    string expression;
    double result;
};

class Program {
private:
    vector<Variable> variables;
    map<string, Function> functions;

    double evaluateExpression(string expr);

public:
    void readInstructionsFromFile(string fileName);
    void executeInstructions();
    void printValue(string name);
    void printAllValues();
};

void Program::readInstructionsFromFile(string fileName) {
    ifstream file(fileName);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            string token;
            istringstream iss(line);

            while (iss >> token) {
                // Process token
            }
        }

        file.close();
    }
}

void Program::executeInstructions() {
    // Execute instructions
}

void Program::printValue(string name) {
    // Print value of specific variable
}

void Program::printAllValues() {
    // Print values of all variables
}

double Program::evaluateExpression(string expr) {
    // Evaluate expression and return result
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    Program program;
    program.readInstructionsFromFile(argv[1]);
    program.executeInstructions();

    return 0;
}
