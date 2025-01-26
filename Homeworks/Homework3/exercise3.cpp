#include <iostream>
using namespace std;

struct Task {
    int taskID;             // Unique ID for the task int level
    int level;              // Task level (1, 2, or 3)
    int estTime;	        // Estimated time for the task int loggedTime
    int loggedTime;         // Time logged for the task
};

struct Worker {
    int workerID;           // Unique ID for the worker
    int totalLoggedTime;    // Total time logged by the worker
    Task tasks[3];          // Array to store up to 3 tasks for the worker int taskCount
    int taskCount;          // Number of tasks currently assigned
};

void AssignTask(struct Worker* workerPtr, int taskID);
void AssignBulTasks(int workerCount, struct Worker workerList[], int taskCount, struct Task taskList[]);
void LogTaskTime(struct Worker* workerPtr, struct Task* taskPtr, int time);
void PrintTaskTimeLog(struct Task task);
void PrintWorkerTaskList(struct Worker worker);
void PrintWorkerTimeDetails(struct Worker worker);
void PrintWorkersInTxtFile(int workerCount, struct Worker workerList[], FILE *filePtr);
struct Worker NewWorker();
struct Task NewTask();

int main() {
    int workerCount, taskCount;

    cout << "Enter the number of workers: ";
    cin >> workerCount;

    cout << "Enter the number of tasks: ";
    cin >> taskCount;

    Worker workers[workerCount];
    for (int i = 0; i < workerCount; i++) {
        workers[i] = NewWorker();
        workers[i].workerID = i;
    }

    Task tasks[taskCount];
    for (int i = 0; i < taskCount; i++) {
        tasks[i] = NewTask();
        tasks[i].taskID = i;
        tasks[i].level = i % 3 + 1;
    }

    // for (Worker worker : workers)
    //     PrintWorkerTimeDetails(worker);

    // for (Task task : tasks)
    //     PrintTaskTimeLog(task);

    int option = 0;

    while (option != 8) {

        cout << endl;
        cout << "1. Assign task to worker" << endl;
        cout << "2. Assign all tasks to all workers" << endl;
        cout << "3. Log time for a task" << endl;
        cout << "4. Display task time log" << endl;
        cout << "5. Display worker task list" << endl;
        cout << "6. Display worker time details" << endl;
        cout << "7. Export worker details in text file" << endl;
        cout << "8. Exit program" << endl;
        cout << endl;

        cout << "Select one of the above choices: ";
        cin >> option;

        while (option < 1 || option > 8) {
            cout << "Invalid choice, please reenter: ";
            cin >> option;
        }

        int currentWorkerID, currentTaskID;

        switch (option) {
            case 1:
                cout << "Enter worker ID: ";
                cin >> currentWorkerID;
                cout << "Enter task ID: ";
                cin >> currentTaskID;
                AssignTask(&workers[currentWorkerID], currentTaskID);
                cout << endl;
                break;
            case 2:
                cout << "Assigning tasks..." << endl << endl;
                AssignBulTasks(workerCount, workers, taskCount, tasks);
                break;
            case 3:
                int numHours;
                cout << "Enter worker ID: ";
                cin >> currentWorkerID;
                cout << "Enter task ID: ";
                cin >> currentTaskID;
                cout << "Enter number of hours: ";
                cin >> numHours;
                LogTaskTime(&workers[currentWorkerID], &tasks[currentTaskID], numHours);
                break;
            case 4:
                cout << "Enter task ID: ";
                cin >> currentTaskID;
                PrintTaskTimeLog(tasks[currentTaskID]);
                break;
            case 5:
                cout << "Enter worker ID: ";
                cin >> currentWorkerID;
                PrintWorkerTaskList(workers[currentWorkerID]);
                break;
            case 6:
                cout << "Enter worker ID: ";
                cin >> currentWorkerID;
                PrintWorkerTimeDetails(workers[currentWorkerID]);
                break;
            case 7:
                string fileName = "workers.txt";
                // cout << "Enter file name: ";
                // getline(cin, fileName);
                FILE *filePtr = fopen(fileName.c_str(), "w");
                PrintWorkersInTxtFile(workerCount, workers, filePtr);
                fclose(filePtr);
                break;
        }
    }
}

void AssignTask(struct Worker* workerPtr, int taskID) {
    // To assign 3 or less tasks
    if (workerPtr->taskCount < 3) {
        // No repeated ID
        for (int i = 0; i < workerPtr->taskCount; i++) {
            if (workerPtr->tasks[i].taskID == taskID) {
                cout << "Given task already assigned to worker" << endl;
                return;
            }
        }
        // Create new task
        Task task = NewTask();
        // Initialize task ID
        task.taskID = taskID;
        // Append task to worker tasks
        workerPtr->tasks[workerPtr->taskCount] = task;
        // Increment worker task count
        workerPtr->taskCount++;
        // Confirmation message
        cout << "Assigned task ID " << taskID << " to worker ID " << workerPtr->workerID << endl;
    } else
        // Display error message
        cout << "Task limit of 3 is exceeded. Task not assigned." << endl;
}

void AssignBulTasks(int workerCount, struct Worker workers[], int taskCount, struct Task tasks[]) {
    int t = 0; // task index
    int w = 0; // worker index

    // Repeat till all tasks or all workers are finished
    while (t < taskCount && w < workerCount) {
        // Assign 3 or less tasks
        if (workers[w].taskCount < 3) {
            AssignTask(&workers[w], tasks[t].taskID);
            t++;
        // Move to next worker
        } else
            w++;
    }

    if (t < taskCount) {
        do {
            cout << "Unable to assign task ID " << tasks[t].taskID << endl;
            t++;
        } while (t < taskCount);
    }
}

void LogTaskTime(struct Worker* workerPtr, struct Task* taskPtr, int time) {
    for (int i = 0; i < workerPtr->taskCount; i++) {
        if (workerPtr->tasks[i].taskID == taskPtr->taskID) {
            taskPtr->loggedTime += time;
            workerPtr->totalLoggedTime += time;
            cout << "Time logging successful." << endl;
            return;
        }
    }
    cout << "Given task is not assigned to given worker. Time not logged." << endl;
}

void PrintTaskTimeLog(struct Task task) {
    cout << "Task ID: " << task.taskID << endl;
    cout << "\tTask Level: " << task.level << endl;
    cout << "\tEstimated Time: " << task.estTime << endl;
    cout << "\tLogged Time: " << task.loggedTime << endl;
}

void PrintWorkerTaskList(struct Worker worker) {
    cout << "Worker ID: " << worker.workerID << endl;
    for (int i = 0; i < worker.taskCount; i++) {
        Task task = worker.tasks[i];
        cout << "\tTask ID: " << task.taskID << endl;
        cout << "\t\tTask Level: " << task.level << endl;
        cout << "\t\tEstimated Time: " << task.estTime << endl;
    }
}

void PrintWorkerTimeDetails(struct Worker worker) {
    cout << "Worker ID: " << worker.workerID << endl;

    // Calculate assigned time
    int timeAssigned = 0;
    for (int i = 0; i < worker.taskCount; i++)
        timeAssigned += worker.tasks[i].estTime;

    cout << "\tTotal Time Assigned: " << timeAssigned << endl;
    cout << "\tTotal Time Logged: " << worker.totalLoggedTime << endl;
    
    if (timeAssigned == worker.totalLoggedTime)
        return;
    if (timeAssigned > worker.totalLoggedTime)
        cout << "\tRemaining Time: " << timeAssigned - worker.totalLoggedTime << endl;
    else
        cout << "\tExcess Time: " << worker.totalLoggedTime - timeAssigned << endl;
}

void PrintWorkersInTxtFile(int workerCount, struct Worker workerList[], FILE *filePtr) {
    if (filePtr) {
        for (int i = 0; i < workerCount; i++) {
            Worker worker = workerList[i];

            // Write to file
            fputs((
                    "Worker ID: " + to_string(worker.workerID) +
                    "\n\tTask count: " + to_string(worker.taskCount) +
                    "\n\tTotal Logged Time: " + to_string(worker.totalLoggedTime)
                 ).c_str(), filePtr);
            
            if (worker.taskCount)
                fputs("\n\tAssigned Tasks:", filePtr);
            for (int j = 0; j < worker.taskCount; j++) {
                Task task = worker.tasks[j];
                fputs((
                        "\n\t\tTask ID: " + to_string(task.taskID) +
                        "\n\t\t\tLevel: " + to_string(task.level) +
                        "\n\t\t\tEstimated Time: " + to_string(task.estTime) +
                        "\n\t\t\tLogged Time: " + to_string(task.loggedTime)
                    ).c_str(), filePtr);
            }
            putc('\n', filePtr);
        }
    }
}

struct Worker NewWorker() {
    return {0, 0, {}, 0};
}

struct Task NewTask() {
    return {0, 0, 0, 0};
}