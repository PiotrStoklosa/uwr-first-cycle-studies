#include <iostream>
#include <algorithm>

int difference[1'000'001];
int differenceCopy[1'000'001];

int main() {

    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int n;
    std::cin>>n;

    int blocks[n];

    for (int i = 0; i < n; i++)
        std::cin>>blocks[i];

    std::sort(blocks, blocks + n);

    int sum = 0;

    for (int block : blocks) {

        sum += block;

        for (int j = 0; j <= sum; j++) {

            if (difference[j] == 0 && j == block)
                differenceCopy[block] = std::max(block, differenceCopy[block]);
            else if (difference[j]) {

                differenceCopy[j + block] = std::max(std::max(difference[j + block], difference[j] + block),
                                                     differenceCopy[j + block]);

                if (block < j)
                    differenceCopy[j - block] = std::max(std::max(difference[j - block], difference[j]),
                                                         differenceCopy[j - block]);

                else
                    differenceCopy[block - j] = std::max(std::max(difference[block - j], difference[j] - j + block),
                                                         differenceCopy[block - j]);
            }
        }
        for (int j = 0; j <= sum; j++)
            difference[j] = differenceCopy[j];
    }

    if (difference[0])
        std::cout<<"TAK\n"<<difference[0];
    else
        for (int i = 1; i <= sum; i++)
            if (difference[i] && difference[i] != i){
                std::cout<<"NIE\n"<<i;
                break;
            }

    return 0;
}