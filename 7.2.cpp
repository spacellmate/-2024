#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Box {
    int weight;
    int maxWeight;
};

bool compare(Box a, Box b) {
    return a.maxWeight < b.maxWeight;
}

int maxBoxes(vector<Box>& boxes) {
    sort(boxes.begin(), boxes.end(), compare);

    int count = 1;
    int currentWeight = boxes[0].weight;

    for (int i = 1; i < boxes.size(); ++i) {
        if (currentWeight + boxes[i].weight <= boxes[i].maxWeight) {
            currentWeight += boxes[i].weight;
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<Box> boxes(n);
    for (int i = 0; i < n; ++i) {
        cin >> boxes[i].weight >> boxes[i].maxWeight;
    }

    int result = maxBoxes(boxes);

    cout << result << endl;

    return 0;
}
