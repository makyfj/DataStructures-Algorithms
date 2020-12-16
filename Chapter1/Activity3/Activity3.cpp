/*
 * Simulating a Queue for a Share Printer in an Office
 *
 * Implement a queue for handling print sequence to a shared
 * printer in an office. Follow these steps to complete the activity
 *
 */

#include <iostream>
#include <queue>

class Job {
private:
  int id;
  std::string user;
  int time;
  static int count;

public:
  Job(const std::string &user, int time)
      : user(user), time(time), id(++count) {}

  friend std::ostream &operator<<(std::ostream &os, const Job &j) {

    os << "id: " << j.id << ", user: " << j.user << ", time: " << j.time
       << " seconds" << std::endl;
    return os;
  }
};

int Job::count = 0;

template <size_t N> class Printer {
  std::queue<Job> jobs;

public:
  bool addNewJob(const Job &job) {
    if (jobs.size() == N) {
      return false;
    }
    std::cout << "Added job in the queue: " << job;
    jobs.push(job);
    return true;
  }

  void startPrinting() {
    while (not jobs.empty()) {
      std::cout << "Processing Job: " << jobs.front();
      jobs.pop();
    }
  }
};

int main() {
  Printer<5> printer;
  Job j1("Kaitli", 10);
  Job j2("Nicol", 2);
  Job j3("Sara", 8);
  Job j4("Andrea", 3);
  Job j5("Sarah", 11);
  Job j6("Pedro", 1);

  printer.addNewJob(j1);
  printer.addNewJob(j2);
  printer.addNewJob(j3);
  printer.addNewJob(j4);
  printer.addNewJob(j5);

  if (not printer.addNewJob(j6)) // can't add as queue is full
  {
    std::cout << "Couldn't add job 6th" << std::endl;
  }

  printer.startPrinting();

  printer.addNewJob(j6); // Can add now, as queue got emptied
  printer.startPrinting();
}
