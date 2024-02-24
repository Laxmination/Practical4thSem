#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class FiniteAutomata {
private:
    vector<int> states;
    unordered_map<int, unordered_map<char, int>> transitions;
    int initialState;
    vector<int> finalStates;
    int currentState;

public:
    FiniteAutomata(vector<int> states, unordered_map<int, unordered_map<char, int>> transitions,
                   int initialState, vector<int> finalStates) {
        this->states = states;
        this->transitions = transitions;
        this->initialState = initialState;
        this->finalStates = finalStates;
        this->currentState = initialState;
    }

    bool processInput(const string& input) {
        currentState = initialState;
        for (char c : input) {
            if (transitions[currentState].find(c) != transitions[currentState].end()) {
                currentState = transitions[currentState][c];
            } else {
                return false; // Transition not defined for current state and input
            }
        }
        // return find(finalStates.begin(), finalStates.end(), currentState) != finalStates.end();
    }
};

int main() {
    // Define states
    vector<int> states = {0, 1, 2, 3};

    // Define transitions
    unordered_map<int, unordered_map<char, int>> transitions = {
        {0, {{'a', 1}, {'b', 0}}},
        {1, {{'a', 2}, {'b', 1}}},
        {2, {{'a', 2}, {'b', 3}}},
        {3, {{'a', 3}, {'b', 3}}}
    };

    // Define initial state
    int initialState = 0;

    // Define final states
    vector<int> finalStates = {2};

    // Create Finite Automata object
    FiniteAutomata fa(states, transitions, initialState, finalStates);

    // Process input strings
    vector<string> inputs = {"abab", "aab", "abb", "baa"};

    for (const string& input : inputs) {
        cout << "Input: " << input << " -> ";
        if (fa.processInput(input)) {
            cout << "Accepted" << endl;
        } else {
            cout << "Rejected" << endl;
        }
    }

    return 0;
}
