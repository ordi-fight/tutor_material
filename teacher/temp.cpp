#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

const int SIZE = 20;
const int MAX_STEPS = 4000;

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
        //  go ahead
        for (int i = 0; i < 4; i++) {
            Pos p = pos + dirs[i];

            if (knownOpen(p) and visited[p.r][p.c] == 0 and p != untouchable) {
                visited[p.r][p.c] = visited[pos.r][pos.c] + 1;
                pos = p;
                return dirs[i];
            }
        }
        // retreat
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
    void computeDistance(Pos start, int distance[SIZE][SIZE]) const{

        std :: queue<Pos> pos_queue;
        Direction dir[4] = {Direction::Up , Direction::Down , Direction::Left , Direction::Right};
        for(int r = 0 ;r < SIZE ; r++){
            for(int c = 0 ; c < SIZE ; c++){
                distance[r][c] = 0;
            }
        }
        distance[start.r][start.c] = 0;
        pos_queue.push(start);

        while (!pos_queue.empty())
        {
            Pos pos = pos_queue.front();

            // add nei to queue and renew the distance table as flag
            for(int i = 0 ; i < 4; i++){
                Pos newpos = pos + dir[i];
                // visited
                if (!(0 <= newpos.r && newpos.r < SIZE && 0 <= newpos.c && newpos.c < SIZE) || getCell({newpos.r , newpos.c}) == '#' || getCell({newpos.r , newpos.c}) == '?' || distance[newpos.r][newpos.c] != 0 || newpos == start){
                    continue;
                }// unvisited
                distance[newpos.r][newpos.c] = distance[pos.r][pos.c] + 1;
                pos_queue.push(newpos);
            }
            pos_queue.pop();

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
        pos(startPos),
        memory_map(MemoryMap(startPos, 'S')),
        target(startPos),
        phase(0)
        
    {}
    // TODO: Update the cat's memory using the visible neighboring cells.
    void see(char up, char down, char left, char right){
        memory_map.setCell(pos + Direction::Up , up);
        memory_map.setCell(pos + Direction::Down , down);
        memory_map.setCell(pos + Direction::Left , left);
        memory_map.setCell(pos + Direction::Right , right);
    }
    // TODO: Move the cat and return the chosen direction.
    Direction move(int step, Pos mousePos, Pos exitPos){
        /*
        Steps 0–799: The cat explores all reachable cells without entering the mouse’s cell. (The mouse stays still.)
        Steps 800–1599: The cat moves to a discovered reachable that is farthest from 'E'.
        Steps 3200–3999: The cat moves to 'E'.
        */
        Direction dir = Direction::Stay;
       if (0 <= step && step <= 799){
            dir = memory_map.dfsNextDirection(pos , {-1 , -1} , mousePos);
       }else if (800 <= step && step <= 1599){
            if (step == 800){
                int distance[SIZE][SIZE];
                memory_map.computeDistance(exitPos , distance);
                int farthest_dis = 0; Pos farthest_pos;
                for(int r = 0 ; r < SIZE ; r++){
                    for(int c = 0 ; c < SIZE ; c++){
                        if(distance[r][c] > farthest_dis){
                            farthest_dis = distance[r][c];
                            farthest_pos = {r , c};
                        }
                    }
                }
                target = farthest_pos;
                memory_map.resetVisited(pos);
            }
            dir = memory_map.dfsNextDirection(pos , target , mousePos);

       }else if (3200 <= step && step <= 3999){
            if (step == 3200){
                memory_map.resetVisited(pos);
            }
            dir = memory_map.dfsNextDirection(pos , exitPos , mousePos);
       }
       return dir;

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
        pos(startPos),
        memory_map(MemoryMap(startPos, 'E')),
        target(startPos),
        phase(0)
    {}
    // TODO: Update the mouse's memory using the visible neighboring cells.
    void see(char up, char down, char left, char right){
        memory_map.setCell(pos + Direction::Up , up);
        memory_map.setCell(pos + Direction::Down , down);
        memory_map.setCell(pos + Direction::Left , left);
        memory_map.setCell(pos + Direction::Right , right);
    }
    // TODO: Move the mouse and return the chosen direction.
    Direction move(int step, Pos catPos, Pos exitPos){
        /*
        Steps 1600–2399: The mouse explores all reachable cells without entering the cat’s cell.

        Steps 2400–3199: The mouse moves to a discovered reachable cell that does not block the cat from reaching 'E'.

        To find such a cell, temporarily treat each candidate cell as a wall and check whether the cat can still reach 'E'.*/
        Direction dir = Direction::Stay;
        if (1600<= step && step <= 2399){
            dir = memory_map.dfsNextDirection(pos , {-1 , -1} , catPos);
        }else if (2400 <= step && step <= 3199){
            if (step == 2400){
                bool found = false;
                for(int r = 0 ;r < SIZE && !found; r++){
                    for(int c = 0 ; c < SIZE ; c++){
                        Pos mouse_pos = {r ,c};

                        memory_map.resetVisited(catPos);

                        if (memory_map.getCell({r , c}) == '#' || memory_map.getCell({r , c}) == 'E' || (catPos.r ==  mouse_pos.r && catPos.c == mouse_pos.c) || memory_map.getCell(mouse_pos) == '?'){
                            continue;
                        }
                        // if(r == 1 and c == 3){
                        //     printf("enter\n");
                        // }
                        Pos cat_cur_pos = catPos;
                        // if(r == 1 and c == 3){
                        //     printf("%d %d\n", cat_cur_pos.r, cat_cur_pos.c);
                        // }

                        while(cat_cur_pos != exitPos){
                            Direction next_dir = memory_map.dfsNextDirection(cat_cur_pos , exitPos , mouse_pos);
                            if (next_dir == Direction :: Stay){
                                break;
                            }
                            // cat_cur_pos = cat_cur_pos + next_dir;
                            // if(r == 1 and c == 3){
                            //     printf("%d %d\n", cat_cur_pos.r, cat_cur_pos.c);
                            // }
                        }
                        if (cat_cur_pos == exitPos){
                            // printf("enter result\n");
                            target = {r ,c};
                            found = true;
                            break;
                        }
                    }
                }
                memory_map.resetVisited(pos);
                // printf("target = %d %d\n", target.r, target.c);
                // for(int i = 0;i < SIZE;i++){
                //     for(int j = 0;j < SIZE;j++){
                //         printf("%c", memory_map.getCell({i, j}));
                //     }
                //     printf("\n");
                // }
            }
            dir = memory_map.dfsNextDirection(pos ,target , catPos);
            
        }
        return dir;
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