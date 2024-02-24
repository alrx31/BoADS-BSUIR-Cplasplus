
/*


4. —истема состоит из трех процессоров P1, P2, P3, очереди F, стека
S и распределител€ задач R.¬ систему поступают запросы на выполнение
задач трЄх типов Ц T1, T2 и T3, кажда€ дл€ своего процессора.ѕоступающие
запросы став€тс€ в очередь.≈сли в начале очереди находитс€ задача Ti и
процессор Pi свободен, то распределитель R ставит задачу на выполнение в
процессор Pi, а если процессор Pi зан€т, то распределитель R отправл€ет
задачу в стек и из очереди извлекаетс€ следующа€ задача.≈сли в вершине
стека находитс€ задача, процессор которой в данный момент свободен, то эта
задача извлекаетс€ и отправл€етс€ на выполнение.


*/




#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

// Task class representing a task of type Ti
class Task {
    int type; // Type of the task (1, 2, or 3)
    int processor; // Processor for which the task is intended

public:
    Task(int type, int processor) : type(type), processor(processor) {}

    int getType() const {
        return type;
    }

    int getProcessor() const {
        return processor;
    }
};

// Processor class representing a processor P1, P2, or P3
class Processor {
    bool isFree;

public:
    Processor() : isFree(true) {}

    bool getIsFree() const {
        return isFree;
    }

    void setIsFree(bool free) {
        isFree = free;
    }
};

// Task distributor class R
class TaskDistributor {
public:
    // Distribute tasks from the queue to the processors and stack
    static void distributeTasks(queue<Task>& taskQueue, stack<Task>& taskStack, vector<Processor>& processors) {
        while (!taskQueue.empty()) {
            Task currentTask = taskQueue.front();
            taskQueue.pop();

            int processorIndex = currentTask.getProcessor() - 1; // Processor index is 0-based

            if (processors[processorIndex].getIsFree()) {
                // If the processor is free, assign the task to it
                cout << "Task T" << currentTask.getType() << " assigned to Processor P" << currentTask.getProcessor() << endl;
                processors[processorIndex].setIsFree(false);
            }
            else {
                // If the processor is busy, push the task to the stack
                cout << "Processor P" << currentTask.getProcessor() << " is busy. Pushing task T" << currentTask.getType() << " to the stack." << endl;
                taskStack.push(currentTask);
            }
        }
    }

    // Process tasks from the stack
    static void processStack(stack<Task>& taskStack, vector<Processor>& processors) {
        while (!taskStack.empty()) {
            Task currentTask = taskStack.top();
            taskStack.pop();

            int processorIndex = currentTask.getProcessor() - 1; // Processor index is 0-based

            if (processors[processorIndex].getIsFree()) {
                // If the processor is free, assign the task to it
                cout << "Task T" << currentTask.getType() << " from the stack assigned to Processor P" << currentTask.getProcessor() << endl;
                processors[processorIndex].setIsFree(false);
            }
            else {
                // If the processor is still busy, push the task back to the stack
                cout << "Processor P" << currentTask.getProcessor() << " is still busy. Pushing task T" << currentTask.getType() << " back to the stack." << endl;
                taskStack.push(currentTask);
                break; // Break the loop to prevent infinite loop
            }
        }
    }
};

int main() {
    // Create three processors
    vector<Processor> processors(3);

    // Create a queue to hold incoming tasks
    queue<Task> taskQueue;

    // Create a stack to hold tasks that cannot be immediately processed
    stack<Task> taskStack;

    // Add some tasks to the queue
    taskQueue.push(Task(1, 1));
    taskQueue.push(Task(2, 2));
    taskQueue.push(Task(3, 3));
    taskQueue.push(Task(1, 2));
    taskQueue.push(Task(3, 1));

    // Distribute tasks from the queue
    TaskDistributor::distributeTasks(taskQueue, taskStack, processors);

    // Process tasks from the stack
    TaskDistributor::processStack(taskStack, processors);

    return 0;
}
