class Solution {
public:
    // Basically find all the 1's in the graph and use those as start locations. 
    // We then do a BFS from each start location and paint a copy of the grid.
    // Each time we have a new start location which has not yet been painted then
    // we accumulate an island
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> discoveredIslands(grid.size(), std::vector<int>(grid[0].size(), 0));
        
        // Grab all the start coordinates
        vector<pair<int, int>> startCoordinates;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') 
                    startCoordinates.push_back(make_pair(i, j));
            }
        }
        
        int islands(0);
        for (auto& coordinate : startCoordinates) {
            // already painted
            if (discoveredIslands[coordinate.first][coordinate.second] == 1) 
                continue;
            
            // check them bois
            islands++;
            paintIslands(coordinate, grid, discoveredIslands);
        }
        
        return islands;
    }
    
    void paintIslands(const pair<int, int>& coordinate, const vector<vector<char>>& grid, vector<vector<int>>& discoveredIslands) {
        discoveredIslands[coordinate.first][coordinate.second] = 1;
        queue<pair<int, int>> coordinates;
        coordinates.push(coordinate);
        // printf("initial coord was %d, %d\n", coordinate.first, coordinate.second);
        while (!coordinates.empty()) {
            auto currentCoord = coordinates.front();
            coordinates.pop();
            
            // Paint this island
            
            
            // Add row above
            if (currentCoord.first > 0 && 
                grid[currentCoord.first - 1][currentCoord.second] == '1' &&
                discoveredIslands[currentCoord.first - 1][currentCoord.second] == 0) {
                coordinates.push(make_pair(currentCoord.first - 1, currentCoord.second));
                discoveredIslands[currentCoord.first - 1][currentCoord.second] = 1;
            }
            
            // Add column to the right
            if (currentCoord.second + 1 < grid[0].size() && 
                grid[currentCoord.first][currentCoord.second + 1] == '1' &&
                discoveredIslands[currentCoord.first][currentCoord.second + 1] == 0) {
                coordinates.push(make_pair(currentCoord.first, currentCoord.second + 1));
                discoveredIslands[currentCoord.first][currentCoord.second + 1] = 1;
            }
            
            // Add row below
            if (currentCoord.first + 1 < grid.size() &&
                grid[currentCoord.first + 1][currentCoord.second] == '1' &&
                discoveredIslands[currentCoord.first + 1][currentCoord.second] == 0) {
                coordinates.push(make_pair(currentCoord.first + 1, currentCoord.second));
                discoveredIslands[currentCoord.first + 1][currentCoord.second] = 1;
            }
            
            // Add column to the left
            if (currentCoord.second > 0 &&
                grid[currentCoord.first][currentCoord.second - 1] == '1' &&
                discoveredIslands[currentCoord.first][currentCoord.second - 1] == 0) {
                coordinates.push(make_pair(currentCoord.first, currentCoord.second - 1));
                discoveredIslands[currentCoord.first][currentCoord.second - 1] = 1;
            }
            
            // printf("discovered coord was %d, %d\n", currentCoord.first, currentCoord.second);
            // printMatrix(discoveredIslands);
        }
    }
    
    void printMatrix(const vector<vector<int>>& vec) {
        for (int i = 0; i < vec.size(); ++i) {
            printf("[");
            for (int j = 0; j < vec[i].size(); ++j) {
                printf(" %d,", vec[i][j]);
            }
            printf("]\n");
        }
    }
};
