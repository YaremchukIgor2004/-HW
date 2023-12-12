#include <iostream>
#include <vector>

void waiting_time(const std::vector<double>& service_times, std::vector<double>& waiting) {
    int current_time = 0;

    for (size_t i = 0; i < service_times.size(); ++i) {
        waiting[i] = current_time;
        current_time += service_times[i];
    }
}

int main() {
    size_t n;
    std::cout << "input count of cuctomers: ";
    std::cin >> n;

    std::vector<double> service_times(n);
    std::cout << "input the service time for each customer:" << std::endl;
    for (size_t i = 0; i < n; i++) {
        std::cout << "customer " << i + 1 << ": ";
        std::cin >> service_times[i];
    }

    std::vector<double> waiting_times(n, 0);
    waiting_time(service_times, waiting_times);

    size_t min_time = 0;
    for (size_t i = 1; i < n; ++i) {
        if (waiting_times[i] < waiting_times[min_time]) {
            min_time = i;
        }
    }
    std::cout << "customer number that requires the least amount of time to service: " << min_time + 1 << std::endl;

    size_t maxTimeCustomer = 0;
    for (size_t i = 1; i < n; ++i) {
        if (waiting_times[i] > waiting_times[maxTimeCustomer]) {
            maxTimeCustomer = i;
        }
    }
    std::cout << "the number of the buyer who stood in the queue the longest: " << maxTimeCustomer + 1 << std::endl;

    return 0;
}