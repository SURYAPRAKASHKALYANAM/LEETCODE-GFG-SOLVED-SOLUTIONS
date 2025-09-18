class TaskManager {
public:
    unordered_map<int, pair<int, int>> taskMap;
    set<pair<int, int>> tasksOrder;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto task : tasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        tasksOrder.insert({priority, taskId});
        taskMap[taskId] = {priority, userId};
    }

    void edit(int taskId, int newPriority) {
        auto prev = taskMap[taskId];
        tasksOrder.erase({prev.first, taskId});
        tasksOrder.insert({newPriority, taskId});
        taskMap[taskId].first = newPriority;
    }

    void rmv(int taskId) {
        auto task = taskMap[taskId];
        tasksOrder.erase({task.first, taskId});
        taskMap.erase(taskId);
    }

    int execTop() {
        if (tasksOrder.empty())
            return -1;
        auto task = *(tasksOrder.rbegin());
        int userId = taskMap[task.second].second;
        taskMap.erase(task.first);
        tasksOrder.erase(task);
        return userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */