/*
Initialize:

N philosophers and N forks (represented as mutexes).

Each fork is shared between two philosophers.

Philosopher behavior (repeated in a loop):

Think for a random time.

Try to pick up forks:

To prevent deadlock: Always pick up the lower-numbered fork first.

If philosopher i:

leftFork = i

rightFork = (i + 1) % N

Pick the fork with the smaller index first, then the other.

Eat for a random time.

Put down both forks.

Repeat.

End condition: Can run indefinitely or for a fixed number of iterations.
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <random>

using namespace std;

const int N = 5; // Number of philosophers

mutex forks[N];

void philosopher(int id) {
    int left = id;
    int right = (id + 1) % N;

    // Random generator for thinking/eating time
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 3);

    for (int i = 0; i < 3; i++) { // Each philosopher eats 3 times
        cout << "Philosopher " << id << " is thinking.\n";
        this_thread::sleep_for(chrono::seconds(dis(gen)));

        // Deadlock prevention: pick lower-numbered fork first
        if (left < right) {
            forks[left].lock();
            forks[right].lock();
        } else {
            forks[right].lock();
            forks[left].lock();
        }

        cout << "Philosopher " << id << " is eating.\n";
        this_thread::sleep_for(chrono::seconds(dis(gen)));

        forks[left].unlock();
        forks[right].unlock();

        cout << "Philosopher " << id << " finished eating.\n";
    }
}

int main() {
    vector<thread> philosophers;

    // Create philosopher threads
    for (int i = 0; i < N; i++) {
        philosophers.push_back(thread(philosopher, i));
    }

    // Join threads
    for (auto &p : philosophers) {
        p.join();
    }

    return 0;
}
