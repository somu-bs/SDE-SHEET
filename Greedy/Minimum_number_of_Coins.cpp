vector<int> minPartition(int val)
{
    // code here
    int deno[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> totalCoins;

    for(int i = 9;i>=0;i--) {
        while(val >= deno[i]) {
            val -= deno[i];
            totalCoins.push_back(deno[i]);
        }
    }

    return totalCoins;
}
