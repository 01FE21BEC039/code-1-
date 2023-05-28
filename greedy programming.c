#include<stdio.h>
struct Item {
    int weight;
    int value;
};

int comp(struct Item item1, struct Item item2) {
    double ratio1 = (double)item1.value / item1.weight;
    double ratio2 = (double)item2.value / item2.weight;

    if (ratio1 > ratio2)
        return -1;
    else if (ratio1 < ratio2)
        return 1;
    else
        return 0;
}

double fk(int W, struct Item items[], int n) {

    qsort(items, n, sizeof(items[0]), compare);

    int currentWeight = 0;
    double Value = 0.0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= W) {
            currentWeight += items[i].weight;
            value += items[i].value;
        } else {
                     int remainingWeight = W - currentWeight;
            value += (double)items[i].value / items[i].weight * remainingWeight;
            break;
        }
    }

    return value;
}

int main() {
    struct Item items[] = {{10, 60}, {20, 100}, {30, 120}};
    int n = sizeof(items) / sizeof(items[0]);

    int kWeight = 50;

    double maxValue = fk(kWeight, items, n);
    printf("Maximum value obtainable: %.2f\n", maxValue);

    return 0;
}
