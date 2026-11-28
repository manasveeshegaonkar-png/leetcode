
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        priority_queue<int> pq; // Max Heap

        int fuel = startFuel;
        int stops = 0;
        int i = 0;

        while (fuel < target) {

            // Add all stations we can reach
            while (i < stations.size() && stations[i][0] <= fuel) {
                pq.push(stations[i][1]);
                i++;
            }

            // No reachable station left
            if (pq.empty()) {
                return -1;
            }

            // Take maximum fuel from available stations
            fuel += pq.top();
            pq.pop();

            stops++;
        }

        return stops;
    }
};

