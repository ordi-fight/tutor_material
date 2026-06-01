#include <bits/stdc++.h>

class Table{
    public:
        int grids[4][4];
        int step;
        int h;

        Table(){
            step = 0;
            for(int i = 0;i < 4;i++)
                for(int j = 0;j < 4;j++)
                    grids[i][j] = i * 4 + j + 1;
            grids[3][3] = 0;
        }

        Table(const Table& other) {
            for(int i = 0;i < 4;i++)
                for(int j = 0;j < 4;j++){
                    grids[i][j] = other.grids[i][j];
                    step = other.step;
                    h = other.h;
                }
        }

        bool operator==(const Table& other){
            for(int i = 0;i < 4;i++)
                for(int j = 0;j < 4;j++){
                    if(other.grids[i][j] != grids[i][j])
                        return false;
                }
            return true;
        }

        void readInput(){
            for(int i = 0;i < 4;i++)
                for(int j = 0;j < 4;j++)
                    std::cin >> grids[i][j];
        }

        int compute_linear_conflict_row(int row){
            int result = 0;
            int SIZE = (row == 3)? 3:4;
            int numbers[4] = {4 * row + 1, 4 * row + 2, 4 * row + 3, 4 * row + 4};
            for(int i = 1;i < SIZE;i++){
                for(int j = 0;j < i;j++){
                    int numA = numbers[i], numB = numbers[j];
                    int A_idx = -1, B_idx = -1;
                    for(int k = 0;k < 4;k++){
                        if(grids[row][k] == numA)
                            A_idx = k;
                        if(grids[row][k] == numB)
                            B_idx = k;
                    }
                    if(A_idx < B_idx and A_idx != -1 and B_idx != -1)
                        result += 2;
                }
            }
            return result;
        }

        int compute_linear_conflict_col(int col){
            int result = 0;
            int SIZE = (col == 3)? 3:4;
            int numbers[4] = {col + 1, col + 5, col + 9, col + 13};
            for(int i = 1;i < SIZE;i++){
                for(int j = 0;j < i;j++){
                    int numA = numbers[i], numB = numbers[j];
                    int A_idx = -1, B_idx = -1;
                    for(int k = 0;k < 4;k++){
                        if(grids[k][col] == numA)
                            A_idx = k;
                        if(grids[k][col] == numB)
                            B_idx = k;
                    }
                    if(A_idx < B_idx and A_idx != -1 and B_idx != -1)
                        result += 2;
                }
            }
            return result;
        }

        void compute_h(){
            h = 0;
            for(int i = 0;i < 4;i++){
                for(int j = 0;j < 4;j++){
                    if(grids[i][j] == 0)
                        continue;
                    int correct_r = (grids[i][j] - 1) / 4;
                    int correct_c = (grids[i][j] - 1) % 4;
                    h += abs(i - correct_r) + abs(j - correct_c);
                }
                h += compute_linear_conflict_col(i);
                h += compute_linear_conflict_row(i);
            }
        }

        uint64_t encode() const {
            uint64_t code = 0;
            for(int i = 0;i < 4;i++)
                for(int j = 0;j < 4;j++)
                    code |= ((uint64_t)grids[i][j] << (4 * (i * 4 + j)));
            return code;
        }
};

struct Cmp {
    bool operator()(const Table& a, const Table& b){
        return a.step + a.h > b.step + b.h;
    }
};

int main(void){
    Table start;
    start.readInput();
    start.step = 0;
    start.compute_h();

    std::priority_queue<Table, std::vector<Table>, Cmp> pq;
    std::unordered_map<uint64_t, int> dist;

    pq.push(start);
    dist[start.encode()] = 0;

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    while(!pq.empty()){
        Table cur = pq.top(); pq.pop();

        uint64_t code = cur.encode();
        if(dist.count(code) && dist[code] < cur.step) continue;

        if(cur.h == 0){
            std::cout << cur.step << std::endl;
            return 0;
        }

        int bx = -1, by = -1;
        for(int i = 0;i < 4;i++)
            for(int j = 0;j < 4;j++)
                if(cur.grids[i][j] == 0){ bx = i; by = j; }

        for(int d = 0;d < 4;d++){
            int nx = bx + dx[d], ny = by + dy[d];
            if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;

            Table next = cur;
            std::swap(next.grids[bx][by], next.grids[nx][ny]);
            next.step++;
            next.compute_h();

            uint64_t next_code = next.encode();
            if(!dist.count(next_code) || dist[next_code] > next.step){
                dist[next_code] = next.step;
                pq.push(next);
            }
        }
    }

    return 0;
}
