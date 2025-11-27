#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <string>
using namespace std;
map<string, map<char, set<string>>> nfa;
map<set<string>, map<char, set<string>>> dfa;
set<string> nfa_states = {"q0", "q1", "q2", "q3", "q4"};
set<string> accepting_states = {"q4"};   
void add_nfa_transition(string from, char input, string to) {
    nfa[from][input].insert(to);
}

void print_dfa() {
    cout << "\nDFA States and Transitions:\n";
    for (auto &[state_set, transitions] : dfa) {
        cout << "{ ";
        for (auto s : state_set) cout << s << " ";
        cout << "}";
        for (auto &[input, dest_set] : transitions) {
            cout << "  --" << input << "--> { ";
            for (auto s : dest_set) cout << s << " ";
            cout << "}\n";
        }
    }
}

bool is_accepting(const set<string> &state_set) {
    for (auto s : state_set) {
        if (accepting_states.count(s)) return true;
    }
    return false;
}

int main() {
    // Step 1: Define NFA transitions for 1001
    add_nfa_transition("q0", '1', "q1");
    add_nfa_transition("q1", '0', "q2");
    add_nfa_transition("q2", '0', "q3");
    add_nfa_transition("q3", '1', "q4");

    // Step 2: Convert NFA to DFA using subset construction
    queue<set<string>> q;
    set<set<string>> visited;

    set<string> start_state = {"q0"};
    q.push(start_state);
    visited.insert(start_state);

    while (!q.empty()) {
        set<string> current = q.front(); q.pop();

        for (char input : {'0', '1'}) {
            set<string> next_state;

            for (auto s : current) {
                if (nfa[s][input].size()) {
                    next_state.insert(nfa[s][input].begin(), nfa[s][input].end());
                }
            }

            if (!next_state.empty()) {
                dfa[current][input] = next_state;
                if (visited.count(next_state) == 0) {
                    visited.insert(next_state);
                    q.push(next_state);
                }
            }
        }
    }

    print_dfa();
    string input;
    cout << "\nEnter binary string to test: ";
    cin >> input;

    set<string> current_state = {"q0"};
    for (char ch : input) {
        if (dfa[current_state].count(ch)) {
            current_state = dfa[current_state][ch];
        } else {
            current_state.clear();
            break;
        }
    }

    if (is_accepting(current_state))
        cout << "String accepted by converted DFA!";
    else
        cout << "String rejected.";
}
