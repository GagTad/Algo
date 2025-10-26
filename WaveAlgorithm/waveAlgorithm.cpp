#include <iostream>
#include <queue>
#include <vector>

const int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

struct Point {
	int row;
	int col;

	bool operator==(const Point& other) const {
		return row == other.row && col == other.col;
	}
};

//himnakan masy arjeqavwurum enq mer matrixy
bool runWave(std::vector<std::vector<int>>& grid, Point start, Point finish) {
    if (grid.empty()) return false;

    std::queue<Point> q;
    grid[start.row][start.col] = 1;
    q.push(start);

    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        if (current.row == finish.row && current.col == finish.col) {
            return true;
        }

        for (const auto& dir : directions) {
            Point neighbor = { current.row + dir[0], current.col + dir[1] };

            if (neighbor.row >= 0 && neighbor.row < grid.size() &&
                neighbor.col >= 0 && neighbor.col < grid[0].size() &&
                grid[neighbor.row][neighbor.col] == 0)
            {
                grid[neighbor.row][neighbor.col] = grid[current.row][current.col] + 1;
                q.push(neighbor);
            }
        }
    }

    return grid[finish.row][finish.col] != 0;
}

//havaqum enq mer stacvac ardyunqnery 
std::vector<Point> restorePath(const std::vector<std::vector<int>>& grid, Point start, Point finish) {

    std::vector<Point> path; 

    Point current = finish;  
    path.push_back(current); 

    while (!(current.row == start.row && current.col == start.col)) {

       
        for (const auto& dir : directions) {
            Point neighbor = { current.row + dir[0], current.col + dir[1] };

             
            if (neighbor.row >= 0 && neighbor.row < grid.size() &&
                neighbor.col >= 0 && neighbor.col < grid[0].size())
            {
               
                if (grid[neighbor.row][neighbor.col] == grid[current.row][current.col] - 1) {

                     
                    current = neighbor;        
                    path.push_back(current);     
                    break;  
                }
            }
        }
    }
    std::reverse(path.begin(), path.end());
    return path;
}


void printGrid(const std::vector<std::vector<int>>& grid) {
	std::cout << "    ";
    for (int i = 0; i <= grid.size(); ++i)
    {
		std::cout << i << "| ";
    }
	std::cout << std::endl;
    std::cout << "------------------------" << std::endl;
    for (int i = 0; i < grid.size();++i)
    {
		std::cout << i << "| ";
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if (grid[i][j] == -1)
				std::cout << " X ";
			else
				std::cout << ' ' << grid[i][j] << ' ';
		}
		std::cout << std::endl;
    }
}

//ajd 2 funkcianery havaqum enq mek logikaji mej
void waveAlgorithm(std::vector<std::vector<int>>& grid, Point start, Point finish) {
	if (runWave(grid, start, finish)) {
		std::cout << "Path found:"<<std::endl;
		printGrid(grid);
		std::vector<Point> path = restorePath(grid, start, finish);
        std::cout << "Restored Path:" << std::endl;
		for (const auto& p : path) {
			std::cout << "(" << p.row << ", " << p.col << ") ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "No path found.\n";
	}
}



int main(){

	

	const int WALL = -1;
	const int EMPTY = 0;


	std::vector<std::vector<int>> grid = {
		{EMPTY, WALL, WALL, WALL, WALL, WALL, WALL},
		{WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, WALL},
		{WALL, EMPTY, WALL, EMPTY, EMPTY, EMPTY, WALL},
		{WALL, EMPTY, WALL, WALL, WALL, EMPTY, WALL},
		{WALL, EMPTY, EMPTY, EMPTY, WALL, EMPTY, WALL},
		{WALL, WALL, WALL, WALL, WALL, WALL, WALL}
	};


	Point start = { 1, 1 };	
	Point end = { 4, 5 };

	waveAlgorithm(grid, start, end);
    return 0;

}
