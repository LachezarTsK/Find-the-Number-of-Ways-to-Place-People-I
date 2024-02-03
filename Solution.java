
import java.util.Arrays;

public class Solution {

    int[][] points;

    public int numberOfPairs(int[][] points) {

        Arrays.sort(points, (first, second) -> comparator_decreasingOrder_yCoordinates(first, second));

        this.points = points;
        int countNumberOfPairs = 0;

        for (int first = 0; first < points.length; ++first) {
            for (int second = first + 1; second < points.length; ++second) {

                if (points[first][0] > points[second][0]) {
                    continue;
                }

                boolean firstAndSecondMakePair = true;

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

    private boolean middlePoint_isOnTheFence_or_withinTheFencedArea(int firstIndex, int secondIndex, int middleIndex) {
        return points[middleIndex][0] >= points[firstIndex][0]
                && points[middleIndex][0] <= points[secondIndex][0]
                && points[middleIndex][1] >= points[secondIndex][1]
                && points[middleIndex][1] <= points[firstIndex][1];
    }

    private int comparator_decreasingOrder_yCoordinates(int[] firstPoint, int[] secondPoint) {
        return (secondPoint[1] == firstPoint[1])
                ? (firstPoint[0] - secondPoint[0])
                : (secondPoint[1] - firstPoint[1]);
    }
}
