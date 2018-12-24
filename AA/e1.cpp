#include "stdio.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int numCasos;
    cin >> numCasos;
    for (int c = 0; c < numCasos; c++)
    {
        int budget;
        int tgNum;
        cin >> budget;
        cin >> tgNum;
        vector<vector<int> > garments;
        garments.resize(tgNum);
        for (int gt = 0; gt < tgNum; gt++)
        {
            int gNum;
            cin >> gNum;
            garments[gt].resize(gNum);
            for (int g = 0; g < gNum; g++)
            {
                int gPrice;
                cin >> gPrice;
                garments[gt][g] = gPrice;
            }
        }

        // Dynamic programming
        int** opt = new int*[budget + 1];
        for (int b = 0; b <= budget; b++)
        {
            opt[b] = new int[tgNum];
        }

        // OPT(b, 0) = the maximum price of last garment type less than or equals to b
        for (int current_budget = 0; current_budget <= budget; current_budget++)
        {
            int cBestSpent = -1;
            for (unsigned int g = 0; g < garments[0].size(); g++)
            {
                int cPrice = garments[0][g];
                if (cPrice <= current_budget)
                {
                    if (cPrice > cBestSpent)
                    {
                        cBestSpent = cPrice;
                    }
                }
            }
            opt[current_budget][0] = cBestSpent;
        }
        for (unsigned int gt = 1; gt < garments.size(); gt++)
        {
            for (int current_budget = 0; current_budget <= budget; current_budget++)
            {
                int cBestSpent = -1;
                for (unsigned int g = 0; g < garments[gt].size(); g++)
                {
                    int cPrice = garments[gt][g];
                    if (cPrice <= current_budget)
                    {
                        if (opt[current_budget - cPrice][gt - 1] != -1)
                        {
                            int current_spent = cPrice + opt[current_budget - cPrice][gt - 1];
                            if (current_spent > cBestSpent)
                            {
                                cBestSpent = current_spent;
                            }
                        }
                    }
                }
                opt[current_budget][gt] = cBestSpent;
            }
        }

        int optimal = opt[budget][tgNum - 1];

        if (optimal == -1)
        {
            cout << "no solution" << endl;
        }
        else
        {
            cout << optimal << endl;
        }

        for (int b = 0; b <= budget; b++)
        {
            delete[] opt[b];
        }
        delete[] opt;
    }

    return 0;
}
