
#include <ranges>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
    unique_ptr<vector<vector<int>>> points;

public:
    int numberOfPairs(vector<vector<int>>& points) {

        auto comparator_decreasingOrder_yCoordinates =
                [](const vector<int>& firstPoint, const vector<int>& secondPoint) {
                    return (secondPoint[1] == firstPoint[1])
                            ? (firstPoint[0] < secondPoint[0])
                            : (secondPoint[1] < firstPoint[1]);
                };

        // Prior to C++20: 
        // sort(points.begin(), points.end(), comparator_decreasingOrder_yCoordinates)
        ranges::sort(points, comparator_decreasingOrder_yCoordinates);

        this->points = make_unique<vector<vector<int>>>(points);
        int countNumberOfPairs = 0;

        for (int first = 0; first < points.size(); ++first) {
            for (int second = first + 1; second < points.size(); ++second) {

                if (points[first][0] > points[second][0]) {
                    continue;
                }

                bool firstAndSecondMakePair = true;

                for (int middle = first + 1; middle < second; ++middle) {
                    if (middlePoint_isOnTheFence_or_withinTheFencedArea(first, second, middle)) {
                        firstAndSecondMakePair = false;
                        break;
                    }
                }
                countNumberOfPairs += firstAndSecondMakePair ? 1 : 0;
            }
        }
        return countNumberOfPairs;
    }

private:
    bool middlePoint_isOnTheFence_or_withinTheFencedArea(int firstIndex, int secondIndex, int middleIndex) const {
        return (*points)[middleIndex][0] >= (*points)[firstIndex][0]
                && (*points)[middleIndex][0] <= (*points)[secondIndex][0]
                && (*points)[middleIndex][1] >= (*points)[secondIndex][1]
                && (*points)[middleIndex][1] <= (*points)[firstIndex][1];
    }
};
