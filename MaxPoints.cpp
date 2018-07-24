/** Max Points in a pyramid array
 * DATE : 5/15/2018
 * PROGRAMMER: Yu-Min Chen
 * MEMBER FUNCTION NAME:
 *    int getMaxPoints(vector<vector<int>> &maze);
 * PURPOSE:
 *    produce the max amount of points possible by launching a ball to fall from the top to the bottom drain.
 * PARAMETER:
 *    vector<vector<int>> &maze
 * RETURN VALUE:
 *    int getMaxPoints
 */

#include <iostream>
#include <vector>

using namespace std;

class CIS14 {
public:
     int getMaxPoints(vector<vector<int>> &maze);
};

int CIS14::getMaxPoints(vector<vector<int>> &maze) {

    if(maze.empty())
        return 0;

    for (int i = maze.size() - 2; i >= 0; i--) {
        // start from the second-last row to the top

        for(int j = 0; j <= i; j++) {
            // adding the bigger number of two possible choices in next row
            maze[i][j] += max(maze[i + 1][j], maze[i + 1][j + 1]);
        }
    }
    return maze[0][0];
}

int main() {

    vector<vector<int>> maze = {{2}, {4,1}, {5,3,8}, {1,6,7,3}};

    cout << "Get the max point from the maze:" << endl;
    cout << "{" << endl;
    for(int i = 0; i < maze.size(); i++){
        cout << "{ ";
        for(int j = 0; j <= i; j++){
            cout << maze[i][j] << " ";
        }
        cout << "}" << endl;
    }
    cout << "}" << endl << endl;

    CIS14 cis;
    int i = cis.getMaxPoints(maze) ;
    cout << "Max point is " << i << endl;

    return 0;
}


/** TEST RESULT
* input:   {{2}, {4,1}, {5,3,8}, {1,6,7,3}}
* output:  18
*/
