/*
 * Given some points in cartesian coordinate, (X, Y) find the number of rectangles that can be created
 * by those points.
 * Take into consideration only the rectangles that are parallel with the X, Y axes.
 */
#include <fstream>
#include <set>
using namespace std;

int main() {
    // Total complexity of the program is O(n^2 + log(n))
    ifstream fin("text.in");
    ofstream fout("text.out");
    int x, y, sol=0;
    set<pair<int,int>> points;
    //We read pairs of numbers from a file until there is nothing else to read
    //We insert the pairs in a set, which is a data structure that stores unique elements (and sorts them by default)
    while (fin>>x>>y){
        points.insert({x,y});
    }
    //We iterate through the set and for each pair that can represent a rectangle's diagonal we
    // check if there is another pair that can represent the other diagonal
    for (auto i = points.begin(); i!=points.end(); i++){
        pair<int,int> p1 = *i;
        auto j = i;
        j++;
        while (j!=points.end()){
            pair<int,int> p2 = *j;
            j++;
            // If we have two points with the same X or Y coordinates, they can't represent a diagonal of a rectangle
            if (p1.first == p2.first || p1.second == p2.second) continue;
            // If we have two points with different X and Y coordinates, we check if there are other points that can form a rectangle
            if (points.find({p1.first, p2.second}) != points.end()
            && points.find({p2.first, p1.second}) != points.end()){
                sol++;
            }
        }
    }
    // We divide the number of rectangles by 2 because we counted each rectangle twice
    // When we find a pair that can represent a rectangle's diagonal,
    // eventually we well also find the other pair that represents the other diagonal
    sol/=2;
    fout<<sol;
    fin.close();
    fout.close();
    return 0;
}
