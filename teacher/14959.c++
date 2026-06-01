#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

const int SIZE = 20;
const int MAX_STEPS = 4000;
const int INF = 1000000000;

enum class Direction {
    Up,
    Down,
    Left,
    Right,
    Stay
};

struct Pos {
    int r, c;

    Pos operator+(Direction dir) const {
        switch (dir) {
            case Direction::Up:
                return {r - 1, c};
            case Direction::Down:
                return {r + 1, c};
            case Direction::Left:
                return {r, c - 1};
            case Direction::Right:
                return {r, c + 1};
        }

        return {r, c}; // Direction::Stay
    }

    bool operator==(const Pos& other) const {
        return r == other.r and c == other.c;
    }

    bool operator!=(const Pos& other) const {
        return r != other.r or c != other.c;
    }
};

class MemoryMap {
private:
    char memory[SIZE][SIZE];
    int visited[SIZE][SIZE];

public:
    MemoryMap(Pos startPos, char startCell) {
        fill(memory[0], memory[0] + SIZE * SIZE, '?');
        memory[startPos.r][startPos.c] = startCell;

        resetVisited(startPos);
    }

    char getCell(Pos p) const {
        return memory[p.r][p.c];
    }

    void setCell(Pos p, char cell) {
        memory[p.r][p.c] = cell;
    }

    bool knownOpen(Pos p) const {
        return memory[p.r][p.c] != '#' and memory[p.r][p.c] != '?';
    }

    void resetVisited(Pos pos) {
        fill(visited[0], visited[0] + SIZE * SIZE, 0);
        visited[pos.r][pos.c] = 2;
    }

    // Performs one step of a DFS walk and returns the chosen direction.
    // Remember to call resetVisited(pos) before starting a new DFS search.
    Direction dfsNextDirection(Pos& pos, Pos target, Pos untouchable) {
        /*
            This method performs one step of a DFS walk from pos through known open cells.
            It avoids untouchable when visiting new cells, and stops when it reaches target.

            The parameter pos is the current position of the player. This method updates
            pos to the next position chosen by DFS, and returns the direction of that move.

            The parameter untouchable is usually the position of the other player
            (cat / mouse).

            To use this method:
            1. Call resetVisited(pos) before starting a new DFS search.
            2. Repeatedly call dfsNextDirection(pos, target, untouchable).
            3. If target or untouchable changes, call resetVisited(pos) before continuing.
            4. If target is reached, this method returns Direction::Stay.
            5. To explore all reachable known cells, use an impossible target such as {-1, -1}.
        */

        Direction dirs[4] = {
            Direction::Up,
            Direction::Down,
            Direction::Left,
            Direction::Right
        };

        if (pos == target) {
            return Direction::Stay;
        }

        for (int i = 0; i < 4; i++) {
            Pos p = pos + dirs[i];

            if (knownOpen(p) and visited[p.r][p.c] == 0 and p != untouchable) {
                visited[p.r][p.c] = visited[pos.r][pos.c] + 1;
                pos = p;
                return dirs[i];
            }
        }

        for (int i = 0; i < 4; i++) {
            Pos p = pos + dirs[i];

            if (visited[p.r][p.c] == visited[pos.r][pos.c] - 1) {
                visited[pos.r][pos.c] = -1;
                pos = p;
                return dirs[i];
            }
        }

        return Direction::Stay;
    }

    // TODO: Use BFS to compute shortest distances from start to all known open cells.
    void computeDistance(Pos start, int distance[SIZE][SIZE], Pos untouchable) const{
        std::queue<Pos> q;
        q.push(start);
        distance[start.r][start.c] = 0;

        Direction dirs[4] = {Direction::Up, Direction::Down, Direction::Left, Direction::Right};

        while (!q.empty()){
            Pos pos = q.front();
            for(int i = 0;i < 4;i++){
                Pos newPos = pos + dirs[i];
                if(newPos.r >= SIZE or newPos.r < 0 or newPos.c >= SIZE or newPos.c < 0)
                    continue;
                if(distance[newPos.r][newPos.c] != 0 or start == newPos or getCell(newPos) == '?' or getCell(newPos) == '#' or newPos == untouchable)
                    continue;
                q.push(newPos);
                distance[newPos.r][newPos.c] = distance[pos.r][pos.c] + 1;
            }
            q.pop();
        }
        
    }
};

class Cat {
private:
    MemoryMap memory_map;
    Pos pos;
    Pos target;


    // HINT(optional): You may use these variables if you need them.
    int phase;
    int direction;
    int state[SIZE];

public:
    // TODO: Initialize the cat.
    Cat(Pos startPos): 
        memory_map(startPos, 'S'),
        pos(startPos),
        phase(0)
    {}

    // TODO: Update the cat's memory using the visible neighboring cells.
    void see(char up, char down, char left, char right){
        memory_map.setCell(pos + Direction::Up, up);
        memory_map.setCell(pos + Direction::Down, down);
        memory_map.setCell(pos + Direction::Left, left);
        memory_map.setCell(pos + Direction::Right, right);
    }

    // TODO: Move the cat and return the chosen direction.
    Direction move(int step, Pos mousePos, Pos exitPos){
        updatePlan(step, mousePos, exitPos);
        return memory_map.dfsNextDirection(pos, target, mousePos);
    }

    void updatePlan(int step, Pos mousePos, Pos exitPos){
        phase = step / 800;
        if(step == 0)
            target = {-1, -1};

        if(step == 800){
            memory_map.resetVisited(pos);
            int distance[SIZE][SIZE] = {};
            memory_map.computeDistance(exitPos, distance, mousePos);
            int maxDistance = 0;
            Pos maxPos = exitPos;

            for(int i = 0;i < SIZE;i++){
                for(int j = 0;j < SIZE;j++){
                    if(distance[i][j] > maxDistance){
                        maxDistance = distance[i][j];
                        maxPos = {i, j};
                    }
                }
            }
            target = maxPos;
        }

        if(step == 3200){
            memory_map.resetVisited(pos);
            target = exitPos;
        }
    }
};

class Mouse {
private:
    MemoryMap memory_map;
    Pos pos;
    Pos target;

    // HINT(optional): You may use these variables if you need them.
    int phase;
    int direction;
    int state[SIZE];

public:
    // TODO: Initialize the mouse.
    Mouse(Pos startPos): 
        memory_map(startPos, 'E'),
        pos(startPos),
        phase(0)
    {}
    
    // TODO: Update the mouse's memory using the visible neighboring cells.
    void see(char up, char down, char left, char right){
        memory_map.setCell(pos + Direction::Up, up);
        memory_map.setCell(pos + Direction::Down, down);
        memory_map.setCell(pos + Direction::Left, left);
        memory_map.setCell(pos + Direction::Right, right);
    }
    // TODO: Move the mouse and return the chosen direction.
    Direction move(int step, Pos catPos, Pos exitPos){
        updatePlan(step, catPos, exitPos);
        return memory_map.dfsNextDirection(pos, target, catPos);
    }

    void updatePlan(int step, Pos catPos, Pos exitPos){
        phase = step / 800;
        if(step == 0)
            target = pos;
        
        if(step == 1600)
            target = {-1, -1};

        if(step == 2400){
            memory_map.resetVisited(pos);

            for(int candidate_r = 0;candidate_r < SIZE;candidate_r++){
                for(int candidate_c = 0;candidate_c < SIZE;candidate_c++){
                    if(memory_map.getCell({candidate_r, candidate_c}) == '?' or memory_map.getCell({candidate_r, candidate_c}) == '#' or (catPos.r == candidate_r and catPos.c == candidate_c))
                        continue;
                    char temp = memory_map.getCell({candidate_r, candidate_c});
                    memory_map.setCell({candidate_r, candidate_c}, '#');
                    int distance[SIZE][SIZE] = {};
                    memory_map.computeDistance(catPos, distance, {-1, -1});
                    if(distance[exitPos.r][exitPos.c] != 0){
                        target = {candidate_r, candidate_c};
                        memory_map.setCell({candidate_r, candidate_c}, temp);
                        return;
                    }
                    
                    memory_map.setCell({candidate_r, candidate_c}, temp);
                }
            }
        }

        
    }
};

class Game {
private:
    const vector<string> maze;
    Pos catPos;
    Cat cat;
    Pos exitPos;
    Pos mousePos;
    Mouse mouse;
    string catSteps;
    string mouseSteps;

    char getCell(Pos p) const {
        return maze[p.r][p.c];
    }

    Pos findCell(char cell) const {
        for (int i = 0; i < SIZE; i++) {
            if (auto it = maze[i].find(cell); it != string::npos) {
                return {i, int(it)};
            }
        }

        return {-1, -1};
    }

    bool success() const {
        return catPos == exitPos;
    }

    char directionToChar(Direction dir) const {
        switch (dir) {
            case Direction::Up:
                return 'U';
            case Direction::Down:
                return 'D';
            case Direction::Left:
                return 'L';
            case Direction::Right:
                return 'R';
            case Direction::Stay:
                return 'S';
        }

        return 'S';
    }

    bool illegal(Pos p) const {
        return p.r < 0 or p.r >= SIZE or p.c < 0 or p.c >= SIZE or getCell(p) == '#';
    }

public:
    Game(const vector<string>& inputMaze)
        : maze(inputMaze),
          catPos(findCell('S')),
          cat(catPos),
          exitPos(findCell('E')),
          mousePos(exitPos),
          mouse(mousePos)
    {}

    void play() {
        for (int step = 0; step < MAX_STEPS; step++) {
            // cout << step << endl;
            cat.see(
                getCell(catPos + Direction::Up),
                getCell(catPos + Direction::Down),
                getCell(catPos + Direction::Left),
                getCell(catPos + Direction::Right)
            );

            Direction catDir = cat.move(step, mousePos, exitPos);
            catSteps += directionToChar(catDir);
            catPos = catPos + catDir;

            if (catPos == mousePos or illegal(catPos) or success()) {
                break;
            }

            mouse.see(
                getCell(mousePos + Direction::Up),
                getCell(mousePos + Direction::Down),
                getCell(mousePos + Direction::Left),
                getCell(mousePos + Direction::Right)
            );

            Direction mouseDir = mouse.move(step, catPos, exitPos);
            mouseSteps += directionToChar(mouseDir);
            mousePos = mousePos + mouseDir;

            if (mousePos == catPos or illegal(mousePos)) {
                break;
            }
        }

        cout << catSteps << '\n' << mouseSteps << '\n';
    }
};

int main() {
    vector<string> inputMaze(SIZE);

    for (string& row : inputMaze) {
        cin >> row;
    }

    Game game(inputMaze);
    game.play();

    return 0;
}