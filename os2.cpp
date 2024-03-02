#include <iostream>
#include <thread>

int main() {
    int num_programs = 5;
    std::thread programs[num_programs];
    
    for (int i = 0; i < num_programs; ++i) {
        programs[i] = std::thread([i]() {
            std::cout << "Program " << i << " is running.\n";
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::cout << "Program " << i << " has finished.\n";
        });
    }

    for (int i = 0; i < num_programs; ++i) {
        programs[i].join();
    }

    std::cout << "All programs have finished.\n";

    return 0;
}
