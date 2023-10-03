#include <iostream> 
#include <vector> 

using namespace std;

void add(vector <int> &priority_queue, int x) {
    priority_queue.push_back(x);
    
    int index = (int)priority_queue.size() - 1;

    while (index != 1) {
        int parent_index = index / 2;
        
        if (priority_queue[parent_index] > priority_queue[index]) {
            swap(priority_queue[parent_index], priority_queue[index]);
        } else {
            break;
        }
    }
}

int top(vector <int> &priority_queue) {
    if (priority_queue.size() <= 1) {
        assert(false);
    } else {
        return priority_queue[1];
    }
}


void remove(vector <int> &priority_queue, int index) {
    int last_element_index = priority_queue.size() - 1;


    swap(priority_queue[last_element_index], priority_queue[index]);
    priority_queue.pop_back();

    if (last_element_index != index) {
        while(true) {
            int left_index = index * 2;
            int right_index = index * 2 + 1;

            if (left_index >= priority_queue.size()) {
                left_index = -1;
            }
            if (right_index >= priority_queue.size()) {
                right_index = -1;
            }

            if (left_index == -1 && right_index == -1) {
                break;
            } else if (right_index == -1) {
                if (priority_queue[index] > priority_queue[left_index]) {
                    swap(priority_queue[index], priority_queue[left_index]);
                    index = left_index;
                } else {
                    break;
                }
            } else {
                int rep_index = left_index;
                if (priority_queue[right_index] < priority_queue[left_index]) {
                    rep_index = right_index;
                }

                 if (priority_queue[index] > priority_queue[rep_index]) {
                    swap(priority_queue[index], priority_queue[rep_index]);
                    index = rep_index;
                } else {
                    break;
                }
            }
        }
    }
}
int main() {
    vector <int> v = {12, 34, 32, 56, 32432, 123};
    vector <int> priority_queue;

    priority_queue.push_back(-1);

    for (auto i: v) {
        add(priority_queue, i);
        
    }

    for (int i = 0; i < v.size(); i++) {
        cout << top(priority_queue) << " ";
        /*cout << endl;
        for (auto j: priority_queue) {
            cout << j << " ";
        }
        */
        cout << endl;
        remove(priority_queue, 1);

    }

    return 0;
}